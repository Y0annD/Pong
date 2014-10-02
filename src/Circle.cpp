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
/** 
* Méthode permettant de bouger le cercle  
**/

/**
 * Méthode permettant de dessiner un cercle
 * @param win: pointeur vers la fenetre ou l'on doit afficher le cercle
 **/ 
void Circle::draw(sf::RenderWindow *win) const {
  // forme du cerlce
  sf::CircleShape shape(_width/2);
  // récupération de la couleur du cercle
  int r,g,b;
  _color->getRGB(r,g,b);
  shape.setFillColor(sf::Color(r,g,b));
  // positionnement du cerlce
  shape.setPosition((int)(_x-_width/2),(int)(_y-_width/2));
  // dessin du cercle
  win->draw(shape);
}

