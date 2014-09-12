/**********************
 * Fichier: Window.cpp
 * Auteur: Yoann Diquélou
 * Date: 01/05/2014
 * 
 * Classe permettant la création d'une fenetre
 * 
 ***********************/
#include <iostream>
#include "Window.h"
#include "Rectangle.h"
#include "Circle.h"

using namespace std;

/* Destructeur */
Window::~Window(void) {
  for(unsigned int i=0; i< _rects.size(); i++){
      delete _rects[i];
  }
  for(unsigned int i=0; i< _circs.size(); i++){
      delete _circs[i];
  }
  delete _win;
}

/**
 * Méthode qui dessine tous les éléments graphiques ajoutés 
 * @param win: fenetre sur laquelle dessiner
 **/
void Window::drawAll(sf::RenderWindow* win){
  /* Dessin des rectangles */
  if(_rects.size()>0){
    for(int i=0; i<(int)_rects.size(); i++){
      _rects[i]->draw(win);
    }
  }
  /* Dessin des cercles */
  if( _circs.size()>0){
   for(int i=0; i<(int)_circs.size(); i++){
     _circs[i]->draw(win);
   }
  }

  if( _murs.size()>0){
   for(int i=0; i<(int)_murs.size(); i++){
     _murs[i]->draw(win);
   }
  }
  
}

/**
 * Méthode qui bouge tous les éléments
 * @param dx: déplacement en x
 * @param dy: déplacement en y
 **/ 
void Window::moveAll(int dx, int dy){
  for(int i=0; i<(int)_rects.size(); i++){
    _rects.at(i)->move(dx, dy);
    _circs.at(i)->move(dx,dy);
  }
}

/**
 * Méthode qui ajoute un rectangle
 * @param rect: pointeur vers le rectangle à ajouter
 **/ 
void Window::addRect(Rectangle* rectangle){
   _rects.push_back(rectangle);
}

/**
 * Méthode qui ajoute un cercle
 * @param circ: pointeur vers le cercle à ajouter 
 **/ 
void Window::addCircle(Circle* circle){
  _circs.push_back(circle);
}

/**
 * M�thode qui ajoute un mur
 * @param mur: pointeur vers le mur � ajouter
 **/
void Window::addMur(Mur* mur){
  _murs.push_back(mur);
}

/**
 * Méthode qui affiche la fenetre
 **/ 
void Window::display(void)
{  
  while (_win->isOpen())
  {
    _win->clear(sf::Color(100, 100, 100));
    
    // Dessiner ici les formes géométriques 
    drawAll(_win);
    _win->display();

    sf::Event event;
    if(_win->waitEvent(event)) 
    {
      switch (event.type) 
      {
        case sf::Event::Closed :
             _win->close();
             break;
        case sf::Event::KeyPressed:
             if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
	      cout<< "A" <<endl;
	      moveAll(10,0);
	       
	    }
	     if(sf::Keyboard::isKeyPressed(sf::Keyboard::B)) {
		cout<< "B" <<endl;
		
	     }

             if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		moveAll(-10,0);
	     }
	     if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		moveAll(10,0);
	     }
	     if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		moveAll(0,-10);
	     }
	     if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		moveAll(0,10);
	     }
             break;
        default:
          break;
      }
    }
  }
}


