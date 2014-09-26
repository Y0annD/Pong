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

using namespace std;

/* Destructeur */
Window::~Window(void) {
  for(unsigned int i=0; i< _triangles.size(); i++){
     delete _triangles[i];
  }
  for(unsigned int i=0; i< _circs.size(); i++){
      delete _circs[i];
  }
  delete _win;
}

/**
 * M�thode qui dessine tous les �l�ments graphiques ajout�s 
 * @param win: fenetre sur laquelle dessiner
 **/
void Window::drawAll(sf::RenderWindow* win){
  //  float timeDelta =  clock.restart().asSeconds();
  // ellapsedTime += timeDelta;
  // if(ellapsedTime>=1/60.0f){
  //   moveAll();
  //   ellapsedTime = 0.0f;
  // }
  
  /* Dessin des rectangles */
  if(_triangles.size()>0){
    for(int i=0; i<(int)_triangles.size(); i++){
      _triangles[i]->draw(win);
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
 * M�thode qui bouge tous les �l�ments
 **/ 
void Window::moveAll(){
  for(int i=0; i<(int)_triangles.size(); i++){
    _triangles.at(i)->move();
  }
  for(int i=0; i<(int)_circs.size(); i++){
    _circs.at(i)->move();
  }
}

/**
 * M�thode qui ajoute un rectangle
 * @param rect: pointeur vers le rectangle à ajouter
 **/ 
void Window::addTriangle(Triangle* tri){
   _triangles.push_back(tri);
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
 * M�thode qui sp�cifie au contexte appelant si la 
 * fenetre est ouverte
 * @return: true- fenetre ouverte
 *                false- fenetre fermee
 **/
bool Window::isOpen()const{
  _win->clear(sf::Color(100, 100, 100));
  return _win->isOpen();
}

/**
 * Méthode qui affiche la fenetre
 **/ 
void Window::display(void)
{  
   
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
        //	      moveAll(10,0);
	       
	    }
	     if(sf::Keyboard::isKeyPressed(sf::Keyboard::B)) {
		cout<< "B" <<endl;
		
	     }

             if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
               //		moveAll(-10,0);
	     }
	     if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
         //		moveAll(10,0);
	     }
	     if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
         //		moveAll(0,-10);
	     }
	     if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
         moveAll();
	     }
             break;
        default:
          break;
      }
    }
  
}

sf::RenderWindow* Window::getWindow(void)const{
  return _win;
}

float Window::getTime(void)const{
  return _win->getFrameTime();
}
