// associated header
#include "entitymovement.h"

// include
// core
#include "constantes.h"
#include "door/doorstatemachine.h"
#include "entitymanager.h"
#include "entityposition.h"
#include "gameworld.h"
#include "pathfinder.h"


namespace core
{


/*
 *									MovementTarget
 */


MovementTarget::MovementTarget(const Eigen::Vector2f& target)
  : _target(target)
  , _state(Ordered)
{
}


const Eigen::Vector2f& MovementTarget::target() const
{
  return _target;
}


MovementTarget::State MovementTarget::state() const
{
  return _state;
}


void MovementTarget::setState(MovementTarget::State state)
{
  _state = state;
}


/*
 *													EntityMovement
 */


EntityMovement::EntityMovement(std::size_t entityId, float speedMax)   // speedMax correspond au nombre de cases par secondes
  : EntityModule(entityId)
  , _splinePath(Eigen::VectorXf(0, 1), Eigen::Matrix2Xf(2, 0))
  , _crossedDoor(std::numeric_limits<std::size_t>::max())
{
  EntityManager& entityManager = GameWorld::Instance().entityManager();
  assert(entityManager.positionModule(entityId));
  _position = entityManager.positionModule(entityId)->position();
  _tilePosition = entityManager.positionModule(entityId)->tilePosition();
  _tileCandidate = _tilePosition;
  _orientation = Eigen::Vector2f(1.f,0.f);
  _speedMax = speedMax * core::tileSizef;
  _target = std::unique_ptr<MovementTarget>(new MovementTarget(_position));
  _target->setState(MovementTarget::Done);
}


EntityMovement::~EntityMovement()
{
}


const Eigen::Vector2f& EntityMovement::position() const
{
  return _position;
}


const TilePos& EntityMovement::tilePosition() const
{
  return _tilePosition;
}


float EntityMovement::maxSpeed() const
{
  return _speedMax;
}


bool EntityMovement::setTarget(std::unique_ptr<MovementTarget> target)
{
  _target = std::move(target);
  if(_target)
  {
    assert(MovementTarget::Ordered == _target->state());

    // find the path
    PathFinder<PathFindingMap> pf;
    TilePos tileTarget = tileFromPixel(_target->target().cast<int>());

    // we launch the path finding from tile candidate
    _path = pf.find(gameworld().pathFindingMap(), _tileCandidate, tileTarget);

    if(!_path.empty())
    {
      // if the path doesn't contain tile position
      // we add it in first position to avoid teleportation
      // of the unit in tile candidate
      if(_path[1] != _tilePosition)
      {
        _path.insert(_path.begin(), _tilePosition);
      }
      computeSplinePath();
      _pathTime = 0.f;
      _target->setState(MovementTarget::InProgress);
      return true;
    }
    else
    {
      // path is impossible to follow
      _target->setState(MovementTarget::Abort);
      return false;
    }
  }
  return false;
}


void EntityMovement::setTarget(std::unique_ptr<MovementTarget> target,
                               std::vector<TilePos> path)
{
  assert(!path.empty());

  /// @todo maybe modify the path to avoid some path issue when the unit
  /// is moving.
  _target = std::move(target);
  if(_target)
  {
    _path = std::move(path);
    computeSplinePath();
    _pathTime = 0.f;
    _target->setState(MovementTarget::InProgress);
  }
}


MovementTarget::State EntityMovement::movementTargetState() const
{
  assert(_target);
  return _target->state();
}


void EntityMovement::update(const int deltaMs)
{
  const float fdeltaS = static_cast<float>(deltaMs)/1000.f;
  if(_target && MovementTarget::InProgress == _target->state())
  {
    _pathTime += fdeltaS;
    if(_pathTime >= _pathDuration)
    {
      _pathTime = _pathDuration;
      _tilePosition = _path.back();
      _tileCandidate = _tilePosition;
      _position = pixelTopLeft(_tilePosition).cast<float>();
      _target->setState(MovementTarget::Done);

      processDoor();
    }
    else
    {
      if(_pathTime >= _splinePath.knots()(_curKnot))
      {
        _tilePosition = _path[_curKnot - 1];
        _tileCandidate = _path[_curKnot];
        ++_curKnot;

        processDoor();
      }

      if(_target->state() != MovementTarget::Abort)
      {
        _position = _splinePath(_pathTime);
      }
    }
  }
}


void EntityMovement::computeSplinePath()
{
  assert(!_path.empty());

  // knots size is point numbre + order + 1
  int nrKnots = _path.size() + 1 + 1;
  Eigen::VectorXf knots(nrKnots);
  Eigen::Matrix2Xf ctls(2, _path.size());

  ctls.col(0) = _position;
  for(int i = 1; i < ctls.cols(); ++i)
  {
    ctls.col(i) = pixelTopLeft(_path[i]).cast<float>();
  }

  // knots(0) => no tile
  // knots(1) => ctls.col(0)
  // ...
  // knots(last - 1) => ctls.col(last)
  // knots(last) => no tile
  knots(0) = knots(1) = 0.;
  for(int i = 2; i < nrKnots - 1; ++i)
  {
    float dist = (ctls.col(i - 1) - ctls.col(i - 2)).norm();
    knots(i) = knots(i - 1) + dist/_speedMax;
  }
  knots(nrKnots - 1) = knots(nrKnots - 2);

  _splinePath = Eigen::Spline<float, 2, 1>(knots, ctls);
  _pathDuration = knots(nrKnots - 1);
   _curKnot = 1;
}


void EntityMovement::processDoor()
{
  // close door if openned
  if(_crossedDoor != std::numeric_limits<std::size_t>::max())
  {
    EntityManager& eMan = gameworld().entityManager();
    DoorStateMachine* dsm =
        dynamic_cast<DoorStateMachine*>(eMan.stateMachineModule(_crossedDoor));
    assert(dsm);

    EntityTeam::Team doorTeam = eMan.teamModule(_crossedDoor)->team();
    EntityTeam::Team entityTeam = eMan.teamModule(entityId())->team();
    if(doorTeam == entityTeam)
    {
      dsm->lock();
    }

    _crossedDoor = std::numeric_limits<std::size_t>::max();
  }

  // open door if we cross one
  EntityMap& eMap = gameworld().entityMap();
  std::size_t doorId;
  if((doorId = eMap.door({_tilePosition, _tileCandidate})) != EntityMap::not_found)
  {
    EntityManager& eMan = gameworld().entityManager();
    DoorStateMachine* dsm =
        dynamic_cast<DoorStateMachine*>(eMan.stateMachineModule(doorId));
    assert(dsm);

    EntityTeam::Team doorTeam = eMan.teamModule(doorId)->team();
    EntityTeam::Team entityTeam = eMan.teamModule(entityId())->team();
    if(doorTeam == entityTeam)
    {
      dsm->open();
      _crossedDoor = doorId;
    }
    else
    {
      _target->setState(MovementTarget::Abort);
      _tileCandidate = _tilePosition;
    }
  }
}

} // core
