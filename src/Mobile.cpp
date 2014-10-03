/**********************
 * Fichier: Mobile.cpp
 * Auteur: Yoann Diqu�lou
 * Date: 23/09/2014
 * 
 * Fichier source de la classe Mobile
 * 
 ***********************/
#include "Mobile.h"
#include <math.h>
#define PI 3.1415

/**
 * Change le sens de la balle en fonction de la collision
 * @param side: 1 - collision lat�rale
 * @param side: 2 - collision haut-bas
 **/
void Mobile::switchSide(int side ){
  if(side == 1){
    _orientation = 180 - _orientation;
    if(_orientation < 0 )
      _orientation +=360;
  }else if(side == 2){
    _orientation = 360 - _orientation;
    if(_orientation <=0)
      _orientation +=360;
  }
}



/**
 * Afin d'optimiser la d�tection de la collision,
 * on d�compose le mouvement du mobile en deux phases.
 * La premi�re consiste � effectuer le mouvement selon l'axe X
 * Puis de controller la collision,
 * Ensuite, nous faisons de m�me avec l'axe Y
 **/
/** 
* M�thode permettant de bouger le mobile selon l'axe X
**/

void Mobile::moveX(){
  double moveX = _speed * cos(PI*_orientation/180.0);
  _x += moveX;
}


/** 
* M�thode permettant de bouger le mobile selon l'axe Y
**/
void Mobile::moveY(){
  double moveY = _speed * sin(PI*_orientation/180.0);
  _y += moveY;
}


/**
 * Mise � jour de la vitesse du mobile
 * On ajoute update � la vitesse actuelle du mobile,
 * Si la nouvelle vitesse est nulle, on la fixe � 1,
 * On fixe une vitesse maximale � 5 pour que le mobile 
 * ne traverse pas les murs.
 **/
void Mobile::updateSpeed(int update){
  // on incr�mente la vitesse
  _speed += update;
  // si la vitesse est nulle, on la met � 1
  if(_speed<=0)
    _speed=1;
  // si la vitesse est sup�rieure � 5, on la fixe � 5
  if(_speed>5)
    _speed=5;
}
