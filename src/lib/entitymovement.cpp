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


MovementTarget::MovementTarget(const Eigen::Vector2f& start,
                               const Eigen::Vector2f& target,
                               float speed)
  :  _splinePath(Eigen::VectorXf(0, 1), Eigen::Matrix2Xf(2, 0))
{
  PathFinder<PathFindingMap> pf;
  TilePos tileStart = tileFromPixel(start.cast<int>());
  TilePos tileTarget = tileFromPixel(target.cast<int>());
  std::vector<TilePos> res = pf.find(gameworld().pathFindingMap(), tileStart, tileTarget);

  if(res.size() > 0)
  {
    // knots size is point numbre + order + 1
    int nrKnots = res.size() + 1 + 1;
    Eigen::VectorXf knots(nrKnots);
    Eigen::Matrix2Xf ctls(2, res.size());

    knots(0) = knots(1) = 0.;
    for(int i = 2; i < nrKnots - 1; ++i)
    {
      float dist = (pixelCenter(res[i - 1]).cast<float>() -
                    pixelCenter(res[i - 2]).cast<float>()).norm();
      knots(i) = knots(i - 1) + dist/speed;
    }
    knots(nrKnots - 1) = knots(nrKnots - 2);

    for(int i = 0; i < ctls.cols(); ++i)
    {
      ctls.col(i) = pixelTopLeft(res[i]).cast<float>();
    }

    _splinePath = Eigen::Spline<float, 2, 1>(knots, ctls);
    _duration = knots(nrKnots - 1);

    _state = Ordered;
  }
  else
  {
    _state = Abort;
  }
}


Eigen::Vector2f MovementTarget::position(float t) const
{
  return _splinePath(t);
}


float MovementTarget::duration() const
{
  return _duration;
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
  :EntityModule(entityId)
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
  if(_target)
    delete _target;
}


Eigen::Vector2f EntityMovement::position() const
{
  return _position;
}


float EntityMovement::maxSpeed() const
{
  return _speedMax;
}


void EntityMovement::setTarget(MovementTarget *target)
{
  if(NULL != _target)
    delete _target;

  _target = target;
  if(NULL != _target)
  {
    assert(MovementTarget::Ordered == _target->state());
    _time = 0.f;
    _target->setState(MovementTarget::InProgress);
  }
}


void EntityMovement::update(float deltas)
{
  if(_target && MovementTarget::InProgress == _target->state())
  {
    _time += deltas;
    if(_time >= _target->duration())
    {
      _time = _target->duration();
      _target->setState(MovementTarget::Done);
    }

    _position = _target->position(_time);
  }
}

} // core
