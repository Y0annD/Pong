/**********************
 * Fichier: Circle.h
 * Auteur: Yoann Diquélou
 * Date: 23/09/2014
 * 
 * Header de la classe Circle
 * 
 ***********************/

#ifndef CIRCLE
#define CIRCLE

#include "SFML/Graphics.hpp"
#include "Color.h"
#include "Mobile.h"

/**
 * Classe Circle,
 * défini un cercle par son centre, 
 * ses dimensions et son orientation
 **/
class Circle: public Mobile {
  public :
    // permet d'afficher le cercle
    virtual void draw(sf::RenderWindow *) const;

    // constructeur du cercle
 Circle(int x, int y, int radius,int orientation,int speed): Mobile(x, y, radius, radius, orientation,  speed){}
};
#endif
