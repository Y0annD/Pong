#include "Mur.h"
#include "Color.h"
#include <string>
#include <iostream>

void Mur::draw(sf::RenderWindow *win)const{
  int r,g,b;
  _color.getRGB(r,g,b);
  sf::RectangleShape shape(sf::Vector2f(_width,_height));
  shape.setFillColor(sf::Color(r,g,b));
  shape.setPosition((int)(_x-_width/2),(int)(_y-_height/2));
  win->draw(shape);
}
