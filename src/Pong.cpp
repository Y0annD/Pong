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
#include "Mobile.h"
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
  /*for(int i = 0; i< 5; i++){
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
      }*/
  _walls.push_back(new Mur(WIDTH/2,25/2,WIDTH,25,0,1));
_walls.push_back(new Mur(25/2,HEIGHT/2,25,HEIGHT,0,1));
  _walls.push_back(new Mur(WIDTH /2,HEIGHT - 25/2,WIDTH,25,0,1));
    _walls.push_back(new Mur(WIDTH - 25/2 ,HEIGHT/2,25,HEIGHT,0,1));
    _mobiles.push_back(new Circle(WIDTH/2, HEIGHT/2, 25,rand()%360,3));
    //_mobiles.push_back(new Triangle(WIDTH/3, HEIGHT/3, 25,25,0,0));
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
    moveAll();
    drawAll(win.getWindow());
    win.display();
    float time = win.getTime();
    std::cout<<"Time: "<<time<<std::endl;
  }
  isRunning = true;
 }

void Pong::moveAll(){
  for(int i=0; i<_mobiles.size();i++){
    _mobiles[i]->move();
    int col = collision(_mobiles[i]);
    std::cout<<"Collision "<<col<<std::endl;
    if(col!=0){
      _mobiles[i]->switchSide(col);

      /*      _mobiles[i]->setX(400);
              _mobiles[i]->setY(400);*/
      _mobiles[i]->move();
  }
}
}



/**
 * Vérifie que deux objets n'entrent pas en collision
 * @param obj: mobile pointer
 * @param nx: futur x position
 * @param ny: futur y position
 * @return 0: no collision
 *               1: side collision right
 *               2: collision gauche
 *               3: collision haut
 *               4: collision bas
 **/
int Pong::collision(Mobile * obj){
  int result = 0;
  int top = obj->getY() - obj->getHeight()/2;
  int bot = obj->getY() + obj->getHeight()/2;
  int right = obj->getX() + obj->getWidth()/2;
  int left    = obj->getX() - obj->getWidth()/2;
  for(int i=0; i<_walls.size();i++){
    int wtop    = _walls[i]->getY()-_walls[i]->getHeight()/2;
    int wbot    = _walls[i]->getY()+_walls[i]->getHeight()/2;
    int wright = _walls[i]->getX()+_walls[i]->getWidth()/2;
    int wleft    = _walls[i]->getX()-_walls[i]->getWidth()/2;
    // side collision
    // left collision
    if(left < wright && 
       (left >= wleft || left < 0) && top > wtop && bot < wbot){
      result = 2;
      break;
    }
    // right collision
    if(right < wright && 
       (right >= wleft || right>WIDTH) && 
       top > wtop && 
       bot < wbot){
      result = 1;
      break;
    }
    // top collsision

    if(top < wbot && 
       (top > wtop || top < 0) && 
       bot > wbot && 
       (right <= wright && left >= wleft)){
      result = 3;
      break;
    }
    // bottom collision
    if(bot>=wtop&&
       top<=wtop &&
       (left>=wleft && right<=wright)){
      result = 4;
      break;
      }

    }
  return result;
}

