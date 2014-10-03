/**********************
 * Fichier: Forme.h
 * Auteur: Yoann Diquélou
 * Date: 23/09/2014
 * 
 * Header de la classe Forme
 * 
 ***********************/

#ifndef FORME
#define FORME
#include "SFML/Graphics.hpp"
#include "Color.h"

class Forme{
 public:
  /**
   * Forme
   * x: position en x du centre de la forme
   * y: position en y du centre de la forme
   * width: largeur de la forme
   * height: hauteur de la forme
   * orientation: direction dans laquelle va se déplacer la forme en deg
   * color: couleur de la forme
   **/
 Forme(int x, int y, int width, int height, 
       double orientation, Color *color):_x(x), _y(y),
    _width(width),_height(height), _orientation(orientation), _color(color){}

  // destructeur de l'objet, on supprime le pointeur sur la couleur
  ~Forme(void) {delete _color;}

  // méthode qui permet de dessiner la forme
  virtual void draw(sf::RenderWindow *win) const =0;
  
  // accesseurs de la position du centre de la forme
  inline int getX(){return _x;}
  inline int getY(){return _y;}
  // accesseurs des dimensions de la forme
  inline int getWidth(){return _width;}
  inline int getHeight(){return _height;}
  inline double getOrientation(){return _orientation;}

  //mutateurs de la position du centre de la forme
  inline void setX(int x){_x = x;}
  inline void setY(int y){_y = y;}
  // mutateurs de la dimension de la forme
  inline void setWidth(int width){_width = width;}
  inline void setHeight(int height){_height = height;}
  inline void setOrientation(int orientation){_orientation = orientation;}

 protected:
  // shape position, double pour pouvoir avoir des 
  // angles différents de 0, 45 ou 90 degres
  double _x, _y;
  // dimensions de la forme
  unsigned int _width, _height;
  //orientation
  double _orientation;
  // couleur de la forme
  Color *_color;
};

#endif
