#include <vector>
#include "stdafx.h"
#include "PlayerPaddle.h"

using namespace std;

public GameMode
{
 public:
  // constructeur
  GameMode();
  // destructeur
  ~GameMode();

  void addBall();
  void removeBall(int position);
  
    
  
 private:
  PlayerPadlle _player;
  Vector<GameBall> _balls;
  
  
};
