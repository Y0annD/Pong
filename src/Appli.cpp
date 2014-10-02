/**********************
 * Fichier: Appli.cpp
 * Auteur: Yoann Diquélou
 * Date: 23/09/2014
 * 
 * Pong en SFML
 * 
 ***********************/
#include <iostream>
#include "Pong.h"

int main(){
  std::cout<<"Started"<<std::endl;
  // création du Pong
  Pong pong = Pong(800,600);
  // initialisation du Pong
  pong.init();
  // lancement du pong
  pong.execute();
  // fin
  std::cout<<"End"<<std::endl;
  return 0;
}

