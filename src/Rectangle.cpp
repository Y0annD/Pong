/**********************
 * Fichier: Rectangle.cpp
 * Auteur: Yoann Diquélou
 * Date: 01/05/2014
 * 
 * Classe permettant la création d'un rectangle
 * 
 ***********************/

#include "Rectangle.h"

/** 
* Méthode permettant de bouger le rectangle  
* @param dx: décallage en x
* @param dy: décallage en y
**/
void Rectangle::move(int dx, int dy){
 _x += dx;
 _y += dy;
}

/**
 * Méthode permettant de dessiner un cercle
 * @param win: pointeur vers la fenetre ou l'on doit afficher le rectangle
 **/ 
void Rectangle::draw(sf::RenderWindow *win) const {
  int width=_width, height=_height;
  int r,g,b;
  colori.getRGB(r,g,b);
  sf::RectangleForme shape(sf::Vector2f(width, height));
  shape.setFillColor(sf::Color(r,g,b));
  shape.setPosition(_x,_y);
  win->draw(shape);
}


