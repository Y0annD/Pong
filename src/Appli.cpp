/**********************
 * Fichier: Appli.cpp
 * Auteur: Yoann Diqu�lou
 * Date: 23/09/2014
 * 
 * Pong en SFML
 * 
 ***********************/
#include <iostream>
#include "Pong.h"

int main(){
  std::cout<<"Started"<<std::endl;
  // cr�ation du Pong
  Pong pong = Pong(800,600);
  // initialisation du Pong
  pong.init();
  // lancement du pong
  pong.execute();
  // fin
  std::cout<<"End"<<std::endl;
  return 0;
}

