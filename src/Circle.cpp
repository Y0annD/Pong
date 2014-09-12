/**********************
 * Fichier: Circle.cpp
 * Auteur: Yoann Diquélou
 * Date: 01/05/2014
 * 
 * Classe définissant un cercle
 ***********************/
#include "Circle.h"

/** 
* Méthode permettant de bouger le cercle  
* @param dx: décallage en x
* @param dy: décallage en y
**/
void Circle::move(int dx, int dy){
 _x += dx;
 _y += dy;
}

/**
 * Méthode permettant de dessiner un cercle
 * @param win: pointeur vers la fenetre ou l'on doit afficher le cercle
 **/ 
void Circle::draw(sf::RenderWindow *win) const {
  sf::CircleShape shape(_radius);
  int r,g,b;
  _color.getRGB(r,g,b);
  shape.setFillColor(sf::Color(r,g,b));
  shape.setPosition(_x,_y);
  win->draw(shape);
}
