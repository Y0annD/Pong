/**********************
 * Fichier: Triangle.cpp
 * Auteur: Yoann Diquélou
 * Date: 01/05/2014
 * 
 * Classe définissant un triangle
 ***********************/
#include "Triangle.h"

/** 
* Méthode permettant de bouger le cercle  
**/
void Triangle::move(){
  _x++;
}

/**
 * Méthode permettant de dessiner un cercle
 * @param win: pointeur vers la fenetre ou l'on doit afficher le cercle
 **/ 
void Triangle::draw(sf::RenderWindow *win) const {
  sf::CircleShape shape(_width, 3);
  int r,g,b;
  _color.getRGB(r,g,b);
  shape.setFillColor(sf::Color(r,g,b));
  shape.setPosition((int)(_x-_width/2),(int)(_y-_height/2));
  win->draw(shape);
}
