/**********************
 * Fichier: Appli.cpp
 * Auteur: Yoann Diquélou
 * Date: 23/09/2014
 * 
 * Application SFML
 * 
 ***********************/
#include "Pong.h"
#include <iostream>
#include "Window.h"

int main(){
  std::cout<<"Test"<<std::endl;
  Pong pong = Pong(800,600);
  pong.init();
  pong.execute();
  std::cout<<"End"<<std::endl;
  return 0;
}

