/**********************
 * Fichier: Triangle.h
 * Auteur: Yoann Diqu�lou
 * Date: 23/09/2014
 * 
 * Header de la classe Triangle
 * 
 ***********************/
#ifndef TRIANGLE
#define TRIANGLE

#include "SFML/Graphics.hpp"
#include "Color.h"
#include "Mobile.h"

/**
 * Classe Triangle
 * d�fini un triangle par son centre, 
 * ses dimensions et son orientation
 **/
class Triangle:public Mobile {
  public :
  // m�thode qui permet d'afficher le triangle
    virtual void draw(sf::RenderWindow *win) const;
   
    // constructeur du triangle
 Triangle(int x, int y, int width, int height ,int orientation,int speed): Mobile(x, y, width, height, orientation,  speed){}
};
#endif
