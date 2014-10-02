

#ifndef PONG
#define PONG

#include <SFML/Graphics.hpp>
#include <vector>
#include "Mobile.h"
#include "Mur.h"
#include "Triangle.h"
#include "Circle.h"

class Pong{
 private:
  // dimensions du plateau de jeu, n'inclus pas l'interface de gestion
  unsigned int WIDTH, HEIGHT;
  // le jeu est-il en pause?
  bool pause;
  // horloge pour la boucle d'affichage
  sf::Clock clock;
  // fen�tre SFML qui affiche le jeu
  sf::RenderWindow* _win;
  // vecteur qui contient les mobiles
  std::vector<Mobile*> _mobiles;
  // vecteur qui contient les murs
  std::vector<Mur*>     _walls;

  // m�thode de d�tection de collision
  int collision(Mobile*);
  // m�thode qui dessine tous les objets
  void display() const;
  // m�thode qui g�re les �v�nements
  void manageEvent();
  // m�thode qui permet le mouvement des objets
  void moveAll(void);
  // ajout d'un cercle
  void addCircle(void);
  // ajout d'un triangle
  void addTriangle(void);
  
 
 public:
  /** constructeur du Pong
   * width : largeur du plateau de jeu
   * height: hauteur du plateau de jeu
   **/
 Pong(int width, int height):WIDTH(width),HEIGHT(height), pause(true),  _win(new sf::RenderWindow(sf::VideoMode(width, height+40),"Pong")){}
  // Destructeur
  ~Pong(void);
  // initialisation du jeu (cr�ation des murs et des mobiles)
  void init();
  // d�marrage du jeu
  void execute();
};

#endif
