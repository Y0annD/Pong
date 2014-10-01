#include "Mur.h"
#include "Color.h"
#include <string>
#include <iostream>


/**
 * Méthode qui permet l'affichage du mur
 * @param *win: pointeur vers la fenêtre dans laquelle on 
 *                         doit afficher le Mur
 **/
void Mur::draw(sf::RenderWindow *win)const{
  // récupération de la couleur du mur
  int r,g,b;
  _color->getRGB(r,g,b);
  // forme du mur
  sf::RectangleShape shape(sf::Vector2f(_width,_height));
  // Remplissage de la couleur du mur
  shape.setFillColor(sf::Color(r,g,b));
  // Positionnement du Mur de telle sorte que le couple (x, y) représente le centre du Mur
  shape.setPosition((int)(_x-_width/2),(int)(_y-_height/2));
  // Dessin du mur dans la fenêtre
  win->draw(shape);
}


/**
 * Métohde appleée quand un objet entre en collision avec le Mur
 * Elle change la couleur du mur et renvoi le coefficient associé au mur
 *
 **/
double Mur::collide(){
  // actualisation de la couleur
  _color->setRGB(rand()%255,rand()%255, rand()%255);
  // on retourne le coefficient associé au mur
  return _coefficient;
}
