#ifndef WINDOW_H
#define WINDOW_H
#define GLEW_STATIC
#include<GL/glew.h>
#include <vector>
#include <SFML/Graphics.hpp>

#include "Circle.h"
#include "Triangle.h"
#include "Mur.h"

class Window {
  private :
    std::string _name;
    int _width, _height;
    sf::RenderWindow *_win;
    void drawAll(sf::RenderWindow*);
    void moveAll();
    std::vector<Triangle*> _triangles;
    std::vector<Circle*> _circs;
    std::vector<Mur*> _murs;
    
    float ellapsedTime;

  public :
    
    Window(std::string n, int w, int h) : _name(n), _width(w), _height(h), 
      ellapsedTime(0.0f),_win(new sf::RenderWindow(sf::VideoMode(_width, _height), _name)){} 

    sf::RenderWindow* getWindow(void)const;
    void addTriangle(Triangle*);
    void addCircle(Circle*);
    void addMur(Mur*);
    ~Window(void);
    bool isOpen(void)const;
    void display(void);
    
    

};

#endif
