#include "Mur.h"

void Mur::draw(sf::RenderWindow *win)const{
  int r,g,b;
  _color.getRGB(r,g,b);
 sf::RectangleShape shape(sf::Vector2f(_width,_height));
  shape.setFillColor(sf::Color(r,g,b));
  shape.setPosition(_x,_y);
  win->draw(shape);
}
