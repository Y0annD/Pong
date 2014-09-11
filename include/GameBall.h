#pragma once
#include "VisibleObject.h"

class GameBall: public VisibleObject
{
 public:
  GameBall();
  virtual ~GameBall();
  void Update();

 private:
  sf::CircleShape _shape;
  float _velocity;
  float _angle;
  float _elapsedTimeSinceStart;
  
  void init(int x, int y, float angle=(std::rand()%360+1));
  float LinearVelocityX(float angle);
  float LinearVelocityY(float angle);
  
};
