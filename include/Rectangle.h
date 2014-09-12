#ifndef RECTANGLE
#define RECTANGLE

#include "SFML/Graphics.hpp"
#include "Color.h"

class Rectangle {
  private:
    // Position
    int _x,_y;
    // Size
    int _width, _height;
    
    sf::Color _color;
    Color colori;
    
  public :
    void move(int dx, int dy);
    void draw(sf::RenderWindow *win) const;
    
    Rectangle(int x, int y, int width, int height): _x(x), _y(y), _width(width), _height(height), colori(Color(50,100,155)){
      _color = sf::Color(rand()%255, rand()%255, rand()%255);
    }

};
#endif
