/**********************
 * Fichier: Mur.h
 * Auteur: Yoann Diqu�lou
 * Date: 23/09/2014
 * 
 * Header de la classe Mur
 * 
 ***********************/

#ifndef MUR
#define MUR
#include "SFML/Graphics.hpp"
#include "Forme.h"
#include "Color.h"


/**
 * classe Mur,
 * d�fini un mur par son centre, 
 * ses dimensions et son coefficient
 **/
class Mur: public Forme{
 public:
  // Constructeur du mur
 Mur(int x, int y, int width, int height, int orientation, double coefficient): Forme(x,y,width, height, orientation, new Color(50, rand()%255, (int)(rand()%255))), _coefficient(coefficient){}
  // m�thode qui affiche le mur � l'�cran
  virtual void draw(sf::RenderWindow *win) const;

  // on sp�cifie qu'on � une collision et on change la couleur du mur
  double collide();

 private:
  // coefficient de changement de vitesse
  // du mobile au contact du mur
  double _coefficient;
};

#endif
