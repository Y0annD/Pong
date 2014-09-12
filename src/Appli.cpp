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

/* Fonction principale du programme */
int main(void) {
 /* Création d'une fenetre de 800x600 avec un nom */
  Window win("Circles and Rectangles", 800,600);

  // créer 3 objets de type Rectangle et les ajouter Ã  la fenÃªtre
  for(int i=0; i<3; i++){
    win.addRect(new Rectangle(rand()%800,rand()%600,rand()%400,rand()%300));
    win.addCircle(new Circle(rand()%800, rand()%600, rand()%100));
  }
  /* Affichage de la fenetre */
  win.display();

  return 0;
}
