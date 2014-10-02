/*****************************************************
 * Fichier: Pong.cpp
 * Auteur: Yoann Diqu�lou
 * Date: 23/09/2014
 * 
 * Application SFML
 * Pong est la classe qui g�re le comportement du pong,
 * elle � pour but de g�rer les collisions, le mouvement 
 * de chaque mobile et la gestion des �v�nements 
 * sur la fenetre.
 * 
 ****************************************************/
#include "Pong.h"


/**
 * Destructeur
 * on d�truit tous les pointeurs de 
 * la classe
 **/
Pong::~Pong(void){
  // destruction des murs
  for(unsigned int i=0; i< _walls.size(); i++){
     delete _walls[i];
  }

  // destruction des mobiles
  for(unsigned int i=0; i< _mobiles.size(); i++){
      delete _mobiles[i];
  }

  // destruction de la fen�tre
  delete _win;
}

/**
 * Initialisation du Pong
 * 
 * Initialise les objets n�cessaire 
 * au fonctionnement du Pong
 **/
void  Pong::init(){
  // nombre de murs par c�t�s
  // ne pas mettre ce nombre trop grand,
  // sinon la collision sera d�faillante
  unsigned int n=5;
  
  // ajout des murs de gauche
  for(unsigned int i = 0; i< n; i++){
    _walls.push_back(new Mur(25/2,i*(HEIGHT/n)+(HEIGHT/n)/2,25,HEIGHT/n,0,1));
  }

  // ajout des murs de droite
  for(unsigned int i = 0; i< n; i++){
    _walls.push_back(new Mur(WIDTH - 25/2 ,i*(HEIGHT/n)+(HEIGHT/n)/2,25,HEIGHT/n,0,1));
    }

  // ajout des mur du haut
  for(unsigned int i = 0; i< n; i++){
    _walls.push_back(new Mur(((WIDTH - 50)/n)*i+((WIDTH - 50)/n)/2+25,25/2,WIDTH/n,25,0,1));
  }

  // ajout des mur du bas
    for(unsigned int i = 0; i< n; i++){
      _walls.push_back(new Mur(((WIDTH - 50)/n)*i+((WIDTH - 50)/n)/2+25,HEIGHT - 25/2,WIDTH/n,25,0,1));
    }
    // ajout de deux mobiles
    addCircle();
    addTriangle();
  }


/**
 * Affichage sur une fenetre du Pong 
 * dans son �tat actuel
 **/
void Pong::display() const{
  // on affiche tous les murs
  for(unsigned int i=0; i< _walls.size();i++){
    _walls[i]->draw(_win);
  }

  // on affiche tous les mobiles
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
    std::cout<<"can't load image"<<std::endl;
  }else{
    sf::Sprite sprite;
    sprite.setPosition(20,HEIGHT );
    sprite.setTexture(texture);
    
    _win->draw(sprite);
  }
  
  // affichage de la fenetre
  _win->display();
  // nettoyage de la fenetre
  _win->clear(sf::Color(100,100,100));
}


/**
 * Lance le jeu
 **/
void Pong::execute(){
  // temps depuis la derniere actualisation
  float time = 0.0f;
  // tant que la fenetre est ouverte
  while(_win->isOpen()){
    // on g�re les �v�nements
    manageEvent();
    // si le jeu n'est pas en pause
    if(!pause){
      // on regarde combien de temps c'est �coul� depuis le dernier appel de cette fonction
      float timeDelta = clock.restart().asSeconds();
      time += timeDelta;
      // on fait en sorte d'avoir un mouvement des
      // objets fluide � une fr�quence proche de 
      // celle d'un moniteur 60Hz
      if(time>1/60.0f){
        moveAll();
        time = 0.0f;
      }
    }
    // dans tous les cas on raffraichi l'�cran
    display();
  }
}
/**
 * Gestion des �v�nements
 * comportement diff�rent en fonction des �v�nements
 **/
void Pong::manageEvent(){
  // on cr�e une variable de type sf::Event qui contiendra 
  // les valeurs associ�s � l'�v�nement
  sf::Event event;
  // si on re�oit un �v�nement, on le traite
  if(_win->pollEvent(event)){
  switch (event.type) 
      {
        // cas o� l'on demande de fermer la fenetre
      case sf::Event::Closed:
        _win->close();
        break;
        // si une touche clavier est appuy�
      case sf::Event::KeyPressed:
        
        // si on presse la touche C, on cr�e un nouveau cercle
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::C)) {
          addCircle();          
        }

        // si on presse la touche T(riangle), on cr�e un nouveau triangle
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::T)) {
          addTriangle();          
        }

        // si on presse la touche P(ause), on inverse l'�tat de Pause
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::P)) {
          pause = !pause;          
        }

        break;
        // Si on appuye sur un bouton de la souris
      case sf::Event::MouseButtonPressed:
        // si on appui sur le bouton gauche de la souris
        if(event.mouseButton.button == sf::Mouse::Left){
          unsigned int x = event.mouseButton.x;
          unsigned int y = event.mouseButton.y;
          if(y>HEIGHT){
            // si on appuye au niveau de la touche
            // play-pause, on compl�mete l'�tat pause
            if(x>=20 && x<=60)
              pause = !pause;
            // si on appuye au niveau du bouton plus
            // du cercle, on cr�e un nouveau cercle
            if(x>=150 && x<=185)
              addCircle();
            // si on appuye au niveau du bouton plus
            // du triangle, on cr�e un nouveau triangle
            if(x>=270 && x<=300)
              addTriangle();
          }            
        }
        // si sa ne correspond � aucun cas pr�c�dent
      default:
        break;
      }
  }
}


/**
 * moveAll
 * permet de faire bouger tous les mobiles 
 * associ�s au Pong
 * mouvements en deux phases pour une
 * gestion plus simple de la collision
 **/
void Pong::moveAll(){
  // pour chaque mobile
  for(unsigned int i=0; i<_mobiles.size();i++){
    // on bouge selon l'axe X
    _mobiles[i]->moveX();
    // on v�rifie si ce mobile est en collision avec un mur
    int col = collision(_mobiles[i]);
    // si il y � collision, on modifie l'orientation du mobile
    if(col!=0){
      _mobiles[i]->switchSide(col);
      _mobiles[i]->moveX();
      _mobiles[i]->moveX();
    }
    // on bouge le mobile selon l'axe Y
    _mobiles[i]->moveY();
    col = collision(_mobiles[i]);
    // si il y � collision, on modifie l'orientation du mobile
    if(col!=0){
      _mobiles[i]->switchSide(col);
      _mobiles[i]->moveY();
      _mobiles[i]->moveY();
    }
  }
}



/**
 * V�rifie que deux objets n'entrent pas en collision
 * @param obj: mobile pointer
 * @param nx: futur x position
 * @param ny: futur y position
 * @return 0: no collision
 *               1: collision lat�rale
 *               2: collision haut||bas
 **/
int Pong::collision(Mobile * obj){
  // on initialise la variable de retour
  int result = 0;
  // on r�cup�re les dimensions du mobile
  int height = (int)obj->getHeight()/2;
  int width = (int)obj->getWidth()/2;
  // on r�cup�re les cotes du mobile
  int top = (int)obj->getY() - height;
  int bot = (int)obj->getY() + height;
  int right = (int)obj->getX() + width;
  int left    = (int)obj->getX() - width;
  // on parcours chaque mur du Pong
  for(unsigned int i=0; i<_walls.size();i++){
    // demi-dimensions du mur
    int wheight = _walls[i]->getHeight()/2;
    int wwidth = _walls[i]->getWidth()/2;
    //cotes du mur
    int wtop    = (int)_walls[i]->getY()-wheight;
    int wbot    = (int)_walls[i]->getY()+wheight;
    int wright = (int)_walls[i]->getX()+wwidth;
    int wleft    = (int)_walls[i]->getX()-wwidth;
    // side collision
    // left collision
    if(left <= wright && 
       left >= wleft && 
       top > wtop-height && bot < wbot+height){
      result = 1;
      obj->updateSpeed(_walls[i]->collide());
      break;
    }
    // right collision
    if(right < wright && 
       (right >= wleft || right>(int)WIDTH) && 
       top > wtop-height && 
       bot < wbot+height){
      result = 1;
      obj->updateSpeed(_walls[i]->collide());
      break;
    }
    // top collsision

    if(top < wbot && 
       top > wtop && 
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


/**
 * addCircle()
 * ajoute un cercle au Pong
 **/
void Pong::addCircle(){
  _mobiles.push_back(new Circle(WIDTH/2, HEIGHT/2, 25,rand()%360,3));
}

/**
 * addTriangle()
 * ajout un triangle au Pong
 **/
void Pong::addTriangle(){
  _mobiles.push_back(new Triangle(WIDTH/3, HEIGHT/3, 25,25,rand()%360,1));
}
