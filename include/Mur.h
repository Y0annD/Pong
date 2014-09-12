#ifndef MUR
#define MUR
#include "Shape.h"
#include "SFML/Graphics.hpp"

class Mur: public Shape{
 public:
 Mur(int x, int y, int width, int height, int orientation, double coefficient): Shape(x,y,width, height, orientation, Color(255,255,255)), _coefficient(coefficient){}
  void draw(sf::RenderWindow *win) const;
  
 private:
  double _coefficient;
};

#endif
