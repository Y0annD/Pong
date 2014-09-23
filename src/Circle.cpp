/**********************
 * Fichier: Circle.cpp
 * Auteur: Yoann Diquélou
 * Date: 01/05/2014
 * 
 * Classe définissant un cercle
 ***********************/
#include "Circle.h"
#include <math.h>
#include <iostream>
#include <string>
#define PI 3.1415
/** 
* Méthode permettant de bouger le cercle  
**/
void Circle::move(){
  std::cout<<"Orientation: "<<_orientation<<std::endl;
  double moveX = _speed * cos(PI*_orientation/180.0);
  double moveY = _speed * sin(PI*_orientation/180.0);
  std::cout<<"moveX: "<<moveX<<" moveY: "<<moveY<<std::endl;
}

/**
 * Méthode permettant de dessiner un cercle
 * @param win: pointeur vers la fenetre ou l'on doit afficher le cercle
 **/ 
void Circle::draw(sf::RenderWindow *win) const {
  sf::CircleShape shape(_width);
  int r,g,b;
  _color.getRGB(r,g,b);
  shape.setFillColor(sf::Color(r,g,b));
  shape.setPosition(_x+_width/2,_y+_width/2);
  win->draw(shape);
}
