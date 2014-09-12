#ifndef WINDOW_H
#define WINDOW_H
#define GLEW_STATIC
#include<GL/glew.h>
#include <vector>
#include "SFML/Graphics.hpp"
#include "Rectangle.h"
#include "Circle.h"

class Window {
  private :
    std::string _name;
    int _width, _height;
    sf::RenderWindow *_win;
    void drawAll(sf::RenderWindow*);
    void moveAll(int dx, int dy);
    std::vector<Rectangle*> _rects;
    std::vector<Circle*> _circs;

  public :
    
    Window(std::string n, int w, int h) : _name(n), _width(w), _height(h), 
                                         _win(new sf::RenderWindow(sf::VideoMode(_width, _height), _name)){} 


   void addRect(Rectangle*);
    void addCircle(Circle*);
    ~Window(void);
    
    void display(void);
    
    

};

#endif
