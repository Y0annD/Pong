#include "stdafx.h"
#include "GameBall.h"
#include "Game.h"

GameBall::GameBall():_velocity(230.0f),
                     _elapsedTimeSinceStart(0)
{
  Load("res/images/gameBall.png");
  assert(IsLoaded());
  
  GetSprite().setOrigin(15,15);

  init(Game::SCREEN_WIDTH/2,Game::SCREEN_HEIGHT/2);
}

GameBall::~GameBall()
{
}

void GameBall::Update()
{
  float dt = (1.0f/60.0f);
  // mise à jour du temps depuis le départ
  _elapsedTimeSinceStart += dt;

  // on ne part pas si sa fait pas 3s
  if(_elapsedTimeSinceStart < 3.0f)
    return;
  
  float moveAmount = _velocity * dt;

  // quantité de mouvement selon chaque axe
  float moveByX = LinearVelocityX(_angle) * moveAmount;
  float moveByY = LinearVelocityY(_angle) * moveAmount;

  // si Bord gauche de l'écran ou droit
  if(GetPosition().x + moveByX <= (GetHeight()/2)
     || GetPosition().x + GetHeight()/2 + moveByX >= Game::SCREEN_WIDTH)
    {
      // inversion de l'angle
      _angle = 360.0f - _angle;
      // evite l'aller retour incessant
      if(_angle > 260.0f && _angle < 280.0f) _angle += 20.0f;
      if(_angle > 80.0f && _angle < 100.0f) _angle += 20.0f;
      // rebond de la balle suivant X
      moveByX = -moveByX;
    }

  /*
A modifier
  */
  PlayerPaddle* player1 =
    dynamic_cast<PlayerPaddle*>(Game::GetGameObjectManager().Get("Paddle1"));
  if(player1 != NULL)
    {
      // on recupere le rectangle qui définit le contour de la raquete
      sf::Rect<float> p1BB = player1->GetBoundingRect();
      // si il y à collision
      if(p1BB.intersects(GetBoundingRect()))
        {
          // on change l'orientation de la balle
          _angle = 360.0f - (_angle - 180.0f);
          if(_angle > 360.0f)_angle -= 360.0f;
          // on change le sens du mouvement
          moveByY = -moveByY;
          // si on est entré dans la raquette
          if(GetBoundingRect().width > player1->GetBoundingRect().top)
            {
              // on se replace correctement
              SetPosition(GetPosition().x, player1->GetBoundingRect().top - GetWidth()/2);
            }
          // on récupére la vitesse de la requete
          float playerVelocity = player1->GetVelocity();
          
          if(playerVelocity < 0)
            {
              // on descend l'angle de la balle
              _angle -= 20.0f;
              // si l'angle est négatif, on le renverse
              if(_angle < 0) _angle = 360.0f - _angle;
            }
          else if(playerVelocity > 0)
            {
              //on descend l'angle de la balle
              _angle += 20.0f;
              if(_angle > 360.0f) _angle = _angle - 360.0f;
            }
          // on augmente la vitesse de la balle de 5px à chaque toucher
          _velocity += 5.0f;
        }
      // si on touche le haut
      if(GetPosition().y - GetHeight()/2 <=0)
        {
          // on renverse l'angle et le mouvement
          _angle = 180 - _angle;
          moveByY = - moveByY;
        }
      // si on arrive en bas, on redémarre
      if(GetPosition().y + GetHeight()/2 + moveByY >= Game::SCREEN_HEIGHT)
        {
          init(Game::SCREEN_WIDTH/2,Game::SCREEN_HEIGHT/2);
        }
      
      GetSprite().move(moveByX, moveByY);
    }
}

void GameBall::init(int x, int y, float angle)
{
  GetSprite().setPosition(x, y);
  _angle = angle;
  _velocity = 220.0f;
  _elapsedTimeSinceStart = 0.0f;
}

float GameBall::LinearVelocityX(float angle)
{
  angle -= 90;
  if(angle < 0) angle += 360;
  return (float)cos(angle * (3.1415925 / 180.0f));
}

float GameBall::LinearVelocityY(float angle)
{
  angle -= 90;
  if(angle < 0) angle += 360;
  return (float)sin(angle * (3.1415925 / 180.0f));
}
