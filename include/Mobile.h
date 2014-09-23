#ifndef MOBILE
#define MOBILE
#include "Shape.h"

class Mobile:public Shape{
 protected:
  int _speed;

 public:
 Mobile(int x,int y, int width, int height, double orientation, int speed):Shape(x,y,width,height, orientation, Color(rand()%255, rand()%255, rand()%255)), _speed(speed){}
  virtual void draw(sf::RenderWindow*)const{};
  virtual void move(){};
  ~Mobile(){}
};

#endif
