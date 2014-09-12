#ifndef TRIANGLE
#define TRIANGLE

#include "SFML/Graphics.hpp"
#include "Color.h"
#include "Mobile.h"

class Triangle:public Mobile {
  public :
    void move();
    void draw(sf::RenderWindow *win) const;
    
 Triangle(int x, int y, int width, int height ,int orientation,int speed): Mobile(x, y, width, height, orientation,  speed){}
    ~Triangle(){}
};
#endif
