/**********************
 * Fichier: Mobile.h
 * Auteur: Yoann Diqu�lou
 * Date: 23/09/2014
 * 
 * Header de la classe Mobile
 * 
 ***********************/
#ifndef MOBILE
#define MOBILE

#include "Forme.h"

/**
 * Classe Mobile,
 * d�fini un mobile par son centre, ses dimensions
 * son orientation et sa vitesse
 **/
class Mobile:public Forme{
 protected:
  // vitesse du mobile
  int _speed;
  
 public:
  // Constructeur du mobile
 Mobile(int x,int y, int width, int height, double orientation, int speed):Forme(x,y,width,height, orientation,new Color(rand()%255, rand()%255, rand()%255)), _speed(speed){}

  // m�thode qui affiche un mobile
  virtual void draw(sf::RenderWindow*)const =0;
  // d�placement selon X du mobile
  void moveX();
  // d�placement selon Y du mobile
  void moveY();
  // changement de cot� du mobile
  void switchSide(int);
  // mise � jour de la vitesse du mobile
  void updateSpeed(int);
};

#endif
