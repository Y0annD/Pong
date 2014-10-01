/**********************
 * Fichier: Triangle.cpp
 * Auteur: Yoann Diqu�lou
 * Date: 01/05/2014
 * 
 * Classe d�finissant un triangle
 ***********************/
#include "Triangle.h"
/**
 * M�thode permettant de dessiner un cercle
 * @param win: pointeur vers la fenetre ou l'on doit afficher le cercle
 **/ 
void Triangle::draw(sf::RenderWindow *win) const {
  // Forme du rectangle
  sf::CircleShape shape(_width/2, 3);
  // r�cup�ration de la couleur appliqu�e au triangle
  int r,g,b;
  _color->getRGB(r,g,b);
  // remplissage du triangle
  shape.setFillColor(sf::Color(r,g,b));
  // on positionne le triange de telle fa�on que le couple (x,y) soit le centre du triangle
  shape.setPosition((int)(_x-_width/2),(int)(_y-_height/2));
  // on affiche le triangle sur la fen�tre
  win->draw(shape);
}
