/**********************
 * Fichier: Pong.cpp
 * Auteur: Yoann Diquélou
 * Date: 23/09/2014
 * 
 * Application SFML
 * 
 ***********************/
#include "Pong.h"
#include "Window.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Mur.h"

  /* Création d'une fenetre de 800x600 avec un nom */
  //Window win("Pong", WIDTH,HEIGHT);
  //init();
    /* Affichage de la fenetre */
//win.display();
//return 0;
//}

void  Pong::init(){
  for(int i = 0; i< 5; i++){
      _walls.push_back(new Mur(25/2,i*(HEIGHT/5)+(HEIGHT/5)/2,25,HEIGHT/5,0,1));
    }
    for(int i = 0; i< 5; i++){
      _walls.push_back(new Mur(WIDTH - 25/2 ,i*(HEIGHT/5)+(HEIGHT/5)/2,25,HEIGHT/5,0,1));
    }
    for(int i = 0; i< 7; i++){
      _walls.push_back(new Mur(((WIDTH - 50)/7)*i+((WIDTH - 50)/7)/2+25,25/2,WIDTH/7,25,0,1));
    }
    for(int i = 0; i< 7; i++){
      _walls.push_back(new Mur(((WIDTH - 50)/7)*i+((WIDTH - 50)/7)/2+25,HEIGHT - 25/2,WIDTH/7,25,0,1));
    }
    
    _mobiles.push_back(new Circle(WIDTH/2, HEIGHT/2, 25,rand()%360,1));
    _mobiles.push_back(new Triangle(WIDTH/3, HEIGHT/3, 25,25,0,0));
  }

void Pong::drawAll(sf::RenderWindow *win) const{
    for(unsigned int i=0; i< _walls.size();i++){
      _walls[i]->draw(win);
    }

    for(unsigned int i=0; i< _mobiles.size();i++){
      _mobiles[i]->draw(win);
    }
  }


/**
 * Lance le jeu
 **/
void Pong::execute(){
  while(win.isOpen()){
    drawAll(win.getWindow());
    win.display();
  }
  isRunning = true;
 }


void collision(){}

