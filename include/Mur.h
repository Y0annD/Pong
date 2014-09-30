#ifndef MUR
#define MUR
#include "Forme.h"
#include "Color.h"
#include "SFML/Graphics.hpp"

class Mur: public Forme{
 public:
  // Constructeur du mur
 Mur(int x, int y, int width, int height, int orientation, double coefficient): Forme(x,y,width, height, orientation, Color(50, rand()%255, (int)(rand()%255))), _coefficient(coefficient){}
  // méthode qui affiche le mur à l'écran
  void draw(sf::RenderWindow *win) const;
  // on spécifie qu'on à une collision et on change la couleur du mur
  double collide();

 private:
  // coefficient de changement de vitesse
  // du mobile au contact du mur
  double _coefficient;
};

#endif
