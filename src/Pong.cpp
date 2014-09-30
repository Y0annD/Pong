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
Pong::~Pong(void){
  for(unsigned int i=0; i< _walls.size(); i++){
     delete _walls[i];
  }
  for(unsigned int i=0; i< _mobiles.size(); i++){
      delete _mobiles[i];
  }

}

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
    _mobiles.push_back(new Circle(WIDTH/2, HEIGHT/2, 25,rand()%360,3));
    _mobiles.push_back(new Triangle(WIDTH/3, HEIGHT/3, 25,25,rand()%360,1));
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
  isRunning = true;
  float time = 0.0;
  int fps = 0;
  while(isRunning){
    float timeDelta = clock.restart().asSeconds();
    time += timeDelta;
    if(time>=1/2 && fps==60){
      moveAll();
      drawAll(win.getWindow());
      win.display();
      time = 0.0;
      fps=0;
    }
      fps++;
      if(!win.isOpen())
        isRunning = false;
    //    float time = win.getTime();
    //std::cout<<"Time: "<<time<<std::endl;
  }
 }

void Pong::moveAll(){
  for(int i=0; i<_mobiles.size();i++){
    _mobiles[i]->moveX();
    int col = collision(_mobiles[i]);
    //    std::cout<<"Collision "<<col<<std::endl;
    if(col!=0){
      _mobiles[i]->switchSide(col);

      /*      _mobiles[i]->setX(400);
              _mobiles[i]->setY(400);*/
      _mobiles[i]->moveX();
  }
    _mobiles[i]->moveY();
    col = collision(_mobiles[i]);
    //    std::cout<<"Collision "<<col<<std::endl;
    if(col!=0){
      _mobiles[i]->switchSide(col);

      /*      _mobiles[i]->setX(400);
              _mobiles[i]->setY(400);*/
      _mobiles[i]->moveY();
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
  int height = obj->getHeight()/2;
  int width = obj->getWidth()/2;
  int top = obj->getY() - height;
  int bot = obj->getY() + height;
  int right = obj->getX() + width;
  int left    = obj->getX() - width;
  double orientation = obj->getOrientation();
  for(int i=0; i<_walls.size();i++){
    int wtop    = _walls[i]->getY()-_walls[i]->getHeight()/2;
    int wbot    = _walls[i]->getY()+_walls[i]->getHeight()/2;
    int wright = _walls[i]->getX()+_walls[i]->getWidth()/2;
    int wleft    = _walls[i]->getX()-_walls[i]->getWidth()/2;
    // side collision
    // left collision
    if(left <= wright && 
       left >= wleft && 
       top > wtop-height && bot < wbot+height){
      result = 2;
      obj->updateSpeed(_walls[i]->getCoefficient());
      break;
      }
    // right collision
       if(right < wright && 
       (right >= wleft || right>WIDTH) && 
       top > wtop-height && 
       bot < wbot+height){
      result = 1;
      obj->updateSpeed(_walls[i]->getCoefficient());
      break;
      }
    // top collsision

    if(top < wbot && 
       (top > wtop || top < 0) && 
       bot > wbot && 
       (right <= wright+width && left >= wleft-width)){
      result = 3;
      obj->updateSpeed(_walls[i]->getCoefficient());
      break;
    }
    // bottom collision
    if(bot>=wtop&&
       top<=wtop &&
       (left>=wleft-width && right<=wright+width)){
      result = 4;
      obj->updateSpeed(_walls[i]->getCoefficient());
      break;
      }

    }
  return result;
}

