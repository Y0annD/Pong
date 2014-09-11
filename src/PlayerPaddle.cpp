#include "stdafx.h"
#include "PlayerPaddle.h"
#include "Game.h"

PlayerPaddle::PlayerPaddle() : _velocity(0),_maxVelocity(600.0f)
{
  Load("res/images/paddle.png");
  std::cout<<IsLoaded()<<std::endl;
  assert(IsLoaded());

  GetSprite().setOrigin(GetSprite().getLocalBounds().width /2, GetSprite().getLocalBounds().height /2);
}

PlayerPaddle::~PlayerPaddle()
{
}


void PlayerPaddle::Draw(sf::RenderWindow& rw)
{
  VisibleObject::Draw(rw);
}

float PlayerPaddle::GetVelocity()const
{
  return _velocity;
}


void PlayerPaddle::Update()
{
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
      _velocity-=10.0f;
    }
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
      _velocity+=10.0f;
    }
  if((sf::Keyboard::isKeyPressed(sf::Keyboard::Down)|| (!sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Left))))
    {
      _velocity=0.0f;
    }

  if(_velocity > _maxVelocity)
    _velocity = _maxVelocity;

  if(_velocity < -_maxVelocity)
    _velocity = -_maxVelocity;

  sf::Vector2f pos = this->GetPosition();

  if(pos.x < GetSprite().getLocalBounds().width/2
     || pos.x > (Game::SCREEN_WIDTH - GetSprite().getLocalBounds().width/2))
    {
      _velocity = -_velocity; // rebond dans la direction opposée
    }
  GetSprite().move(_velocity * (1.0f/60.0f), 0);
  
}
