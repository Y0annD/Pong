/**********************
 * Fichier: Pong.cpp
 * Auteur: Yoann Diquélou
 * Date: 23/09/2014
 * 
 * Application SFML
 * 
 ***********************/
#include "Pong.h"


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

    _walls.push_back(new Mur(150,(HEIGHT - 25)/3,25,HEIGHT/5,0,1));
    addCircle();
    addTriangle();
  }

void Pong::display() const{
    for(unsigned int i=0; i< _walls.size();i++){
      _walls[i]->draw(_win);
    }

    for(unsigned int i=0; i< _mobiles.size();i++){
      _mobiles[i]->draw(_win);
    }
    // interface de controle des evenements
    sf::Texture texture;
    std::string imgName;
    if(pause){
      imgName = "paused.png";
    }else{
      imgName= "running.png";
    }
    if(!texture.loadFromFile(imgName)){
        std::cout<<"can't load plus.png"<<std::endl;
    }else{
      sf::Sprite sprite;
      sprite.setPosition(20,HEIGHT );
      sprite.setTexture(texture);
      //      sprite.setScale(0.2f,0.2f);
      
      _win->draw(sprite);
      }
    
    // affichage de la fenetre
    _win->display();
    _win->clear(sf::Color(100,100,100));
  }


/**
 * Lance le jeu
 **/
void Pong::execute(){
  float time = 0.0;
  int fps = 0;
  while(_win->isOpen()){
    manageEvent();
    if(!pause){
    float timeDelta = clock.restart().asSeconds();
    time += timeDelta;
    if(time>=1/3&& fps==30){
      moveAll();
      time = 0.0;
      fps=0;
    }
      fps++;
    }
    display();
  }
}
/**
 * Gestion des événements
 * comportement différent en fonction des événements
 **/
void Pong::manageEvent(){
  sf::Event event;
  if(_win->pollEvent(event)){
  switch (event.type) 
      {
      case sf::Event::Closed:
        _win->close();
        break;
      case sf::Event::KeyPressed:
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::C)) {
          addCircle();
          
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::T)) {
          addTriangle();
          
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::P)) {
          pause = !pause;
          
        }
        break;
      case sf::Event::MouseButtonPressed:
        if(event.mouseButton.button == sf::Mouse::Left){
          unsigned int x = event.mouseButton.x;
          unsigned int y = event.mouseButton.y;
          if(y>HEIGHT){
            if(x>=20 && x<=60)
              pause = !pause;
            if(x>=150 && x<=185)
              addCircle();
            if(x>=270 && x<=300)
              addTriangle();
          }            
        }
      default:
        break;
      }
  }
}

void Pong::moveAll(){
  for(unsigned int i=0; i<_mobiles.size();i++){
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
 *               1: collision latérale
 *               2: collision haut||bas
 **/
int Pong::collision(Mobile * obj){
  int result = 0;
  unsigned int height = (int)obj->getHeight()/2;
  unsigned int width = (int)obj->getWidth()/2;
  unsigned int top = (int)obj->getY() - height;
  unsigned int bot = (int)obj->getY() + height;
  unsigned int right = (int)obj->getX() + width;
  unsigned int left    = (int)obj->getX() - width;
  for(unsigned int i=0; i<_walls.size();i++){
    unsigned int wtop    = (int)_walls[i]->getY()-_walls[i]->getHeight()/2-1;
    unsigned int wbot    = (int)_walls[i]->getY()+_walls[i]->getHeight()/2+1;
    unsigned int wright = (int)_walls[i]->getX()+_walls[i]->getWidth()/2+1;
    unsigned int wleft    = (int)_walls[i]->getX()-_walls[i]->getWidth()/2-1;
    // side collision
    // left collision
    if(left <= wright && 
       left > wleft && 
       top >= wtop-height && bot <= wbot+height){
      result = 1;
      obj->updateSpeed(_walls[i]->collide());
      break;
      }
    // right collision
       if(right < wright && 
       (right >= wleft || right>=WIDTH) && 
       top >= wtop-height && 
       bot <= wbot+height){
      result = 1;
      obj->updateSpeed(_walls[i]->collide());
      break;
      }
    // top collsision

    if(top <= wbot && 
       (top > wtop || top < 1) && 
       bot > wbot && 
       (right <= wright+width && left >= wleft-width)){
      result = 2;
      obj->updateSpeed(_walls[i]->collide());
      break;
    }
    // bottom collision
    if(bot>=wtop&&
       top<=wtop &&
       (left>=wleft-width && right<=wright+width)){
      result = 2;
      obj->updateSpeed(_walls[i]->collide());
      break;
      }

    }
  return result;
}

void Pong::addCircle(){
  _mobiles.push_back(new Circle(WIDTH/2, HEIGHT/2, 25,rand()%360,3));
}

void Pong::addTriangle(){
  _mobiles.push_back(new Triangle(WIDTH/3, HEIGHT/3, 25,25,rand()%360,1));
}
