#ifndef CIRCLE
#define CIRCLE

#include "SFML/Graphics.hpp"
#include "Color.h"

class Circle {
  private:
    /* Position */
    int _x,_y;
    /* Size */
    int _radius;
    
    Color _color;
    
  public :
    void move(int dx, int dy);
    void draw(sf::RenderWindow *win) const;
    
    Circle(int x, int y, int radius): _x(x), _y(y), _radius(radius), _color(Color(rand()%255, rand()%255, rand()%255)){}

};
#endif
