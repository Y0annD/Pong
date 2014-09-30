#ifndef MOBILE
#define MOBILE
#include "Forme.h"

class Mobile:public Forme{
 protected:
  int _speed;

 public:
 Mobile(int x,int y, int width, int height, double orientation, int speed):Forme(x,y,width,height, orientation, Color(rand()%255, rand()%255, rand()%255)), _speed(speed){}
  virtual void draw(sf::RenderWindow*)const{};
  void moveX();
  void moveY();
  void switchSide(int);
  void updateSpeed(int);
  virtual ~Mobile(){}
};

#endif
