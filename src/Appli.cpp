/**********************
 * Fichier: Appli.cpp
 * Auteur: Yoann Diquélou
 * Date: 01/05/2014
 * 
 * Application SFML
 * 
 ***********************/
#include "Window.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Mur.h"

int WIDTH, HEIGHT;
/* Fonction principale du programme */
int main(void) {
  WIDTH = 800;
  HEIGHT = 600;
  /* Création d'une fenetre de 800x600 avec un nom */
  Window win("Circles and Rectangles", WIDTH,HEIGHT);
  
  for(int i = 0; i< 5; i++){
    win.addMur(new Mur(0,i*(HEIGHT/5),25,HEIGHT/5,0,1));
  }
for(int i = 0; i< 5; i++){
    win.addMur(new Mur(WIDTH - 25,i*(HEIGHT/5),25,HEIGHT/5,0,1));
  }
for(int i = 0; i< 7; i++){
  win.addMur(new Mur(((WIDTH - 50)/7)*i+25,0,WIDTH/7,25,0,1));
 }
for(int i = 0; i< 7; i++){
  win.addMur(new Mur(((WIDTH - 50)/7)*i+25,HEIGHT - 25,WIDTH/7,25,0,1));
  }
  /* Affichage de la fenetre */
  win.display();

  return 0;
}
