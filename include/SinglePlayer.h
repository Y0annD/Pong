#include <vector>
#include "stdafx.h"
#include "PlayerPaddle.h"

using namespace std;

public SinglePlayer
{
 public:
  // constructeur
  SinglePlayer();
  // destructeur
  ~SinglePlayer();

  void addBall();
  void removeBall(int position)
  
 private:
  PlayerPadlle player;
  Vector<GameBall> balls;
  
  
};
