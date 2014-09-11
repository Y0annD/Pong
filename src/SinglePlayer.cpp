#include "SinglePlayer.h"

SinglePlayer::SinglePlayer()
{
  *player = new PlayerPaddle();
  player ->SetPosition((Game::Screen_WIDTH / 2),
                       (Game::Screen_HEIGHT / 2 - 68));
                       
}

SinglePlayer::~SinglePlayer()
{


}

