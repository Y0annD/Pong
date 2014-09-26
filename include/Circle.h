#ifndef CIRCLE
#define CIRCLE

#include "SFML/Graphics.hpp"
#include "Color.h"
#include "Mobile.h"

class Circle: public Mobile {
  public :
    void move();
    void draw(sf::RenderWindow *) const;
    void switchSide(int);

 Circle(int x, int y, int radius,int orientation,int speed): Mobile(x, y, radius, radius, orientation,  speed){}
    ~Circle(){}
};
#endif
