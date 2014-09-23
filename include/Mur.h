#ifndef MUR
#define MUR
#include "Shape.h"
#include "Color.h"
#include "SFML/Graphics.hpp"

class Mur: public Shape{
 public:
 Mur(int x, int y, int width, int height, int orientation, double coefficient): Shape(x,y,width, height, orientation, Color(50, rand()%255, (int)(rand()%255))), _coefficient(coefficient){}
  void draw(sf::RenderWindow *win) const;
  double getCoefficient()const;

 private:
  double _coefficient;
};

#endif
