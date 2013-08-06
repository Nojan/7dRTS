// associated header
#include "entitymovement.h"

// include
// core
#include "constantes.h"
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
{
  EntityManager& entityManager = GameWorld::Instance().entityManager();
  assert(entityManager.positionModule(entityId));
  _position = entityManager.positionModule(entityId)->position();
  _orientation = Eigen::Vector2f(1.f,0.f);
  _speedMax = speedMax * core::tileSizef;
  _target = NULL;
}


EntityMovement::~EntityMovement()
{
}


Eigen::Vector2f EntityMovement::position() const
{
  return _position;
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
    TilePos tileStart = tileFromPixel(_position.cast<int>());
    TilePos tileTarget = tileFromPixel(_target->target().cast<int>());
    _path = pf.find(gameworld().pathFindingMap(), tileStart, tileTarget);

    if(!_path.empty())
    {
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

  _target = std::move(target);
  if(_target)
  {
    _path = std::move(path);
    computeSplinePath();
    _pathTime = 0.f;
    _target->setState(MovementTarget::InProgress);
  }
}


void EntityMovement::update(float deltas)
{
  if(_target && MovementTarget::InProgress == _target->state())
  {
    _pathTime += deltas;
    if(_pathTime >= _pathDuration)
    {
      _pathTime = _pathDuration;
      _position = pixelTopLeft(_path.back()).cast<float>();
      _target->setState(MovementTarget::Done);
    }
    else
    {
      _position = _splinePath(_pathTime);
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

  knots(0) = knots(1) = 0.;
  for(int i = 2; i < nrKnots - 1; ++i)
  {
    float dist = (ctls.col(i - 1) - ctls.col(i - 2)).norm();
    knots(i) = knots(i - 1) + dist/_speedMax;
  }
  knots(nrKnots - 1) = knots(nrKnots - 2);

  _splinePath = Eigen::Spline<float, 2, 1>(knots, ctls);
  _pathDuration = knots(nrKnots - 1);
}

} // core
