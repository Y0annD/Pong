/**********************
 * Fichier: Window.cpp
 * Auteur: Yoann Diqu√©lou
 * Date: 01/05/2014
 * 
 * Classe permettant la cr√©ation d'une fenetre
 * 
 ***********************/
#include <iostream>
#include "Window.h"

using namespace std;

/* Destructeur */
Window::~Window(void) {
  delete _win;
}

/**
 * MÈthode qui spÈcifie au contexte appelant si la 
 * fenetre est ouverte
 * @return: true- fenetre ouverte
 *                false- fenetre fermee
 **/
bool Window::isOpen()const{
  _win->clear(sf::Color(100, 100, 100));
  return _win->isOpen();
}

/**
 * M√©thode qui affiche la fenetre
 **/ 
void Window::display(void)
{  
    _win->display();
   _win->clear(sf::Color(100, 100, 100));
    sf::Event event;
    if(_win->pollEvent(event)) 
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
         //        moveAll();
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
  //  return _win->getFrameTime();
  return 1;
}
