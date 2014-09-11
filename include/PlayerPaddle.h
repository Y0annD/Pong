#pragma once
#include "VisibleObject.h"

class PlayerPaddle : public VisibleObject
{
 public:
  PlayerPaddle();
  ~PlayerPaddle();

  void Update();
  void Draw(sf::RenderWindow& rw);

  float GetVelocity() const;

 private:
  float _velocity; // -- left ++ right
  float _maxVelocity;

};
