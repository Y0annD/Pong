#include "Mobile.h"
#include <math.h>
#define PI 3.1415

/**
 * Change le sens de la balle en fonction de la collision
 * @param side: 1 - collision droite
 * @param side: 2 - collision gauche
 * @param side: 3 - collision haut
 * @param side: 4 - collision bas
 **/
void Mobile::switchSide(int side ){
  if(side == 1|| side == 2){
    _orientation = 180 - _orientation;
    if(_orientation < 0 )
      _orientation +=360;
  }else if(side == 3||side == 4){
    _orientation = 360 - _orientation;
    if(_orientation <=0)
      _orientation +=360;
  }
}


/** 
* Méthode permettant de bouger le mobile selon l'axe X
**/

void Mobile::moveX(){
  double moveX = _speed * cos(PI*_orientation/180.0);
  _x += moveX;
}

void Mobile::moveY(){
  std::cout<<"Orientation: "<<_orientation<<std::endl;
  double moveY = _speed * sin(PI*_orientation/180.0);
  _y += moveY;
}

void Mobile::updateSpeed(int update){
  _speed += update;
  if(_speed==0 && update>0)
    _speed++;
  if(_speed==0 && update<0)
    _speed++;
  if(_speed>5)
    _speed=5;
}
