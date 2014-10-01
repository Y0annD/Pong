#ifndef WINDOW_H
#define WINDOW_H
#include <SFML/Graphics.hpp>

class Window {
  private :
  // nom de la fenetre
  std::string _name;
  // dimensions de la fenêtre
  unsigned int _width, _height;
  // objet SFML Qui défini la fenetre
    sf::RenderWindow *_win;
    sf::Event _event;

  public :
    /**
     * Constructeur
     * string n: Nom de la fenêtre
     * int w     : Largeur de la fenetre
     * int h      : Hauteur de la fenêtre
     **/
    Window(std::string n,unsigned int w,unsigned int h) : _name(n), _width(w), _height(h), 
      _win(new sf::RenderWindow(sf::VideoMode(_width, _height), _name)){} 
    // Destructeur de la fenêtre
    ~Window(void);
   
    // accésseurs de l'attribut _win, nécéssaire pour afficher les objets du Pong
    sf::RenderWindow* getWindow(void)const;
    /*
     * La fenêtre est-elle ouverte?
     * return true: fenêtre ouverte
     * return false: fenêtre fermée
     **/
    bool isOpen(void)const;
    // affiche la fenêtre après l'avoir rafraichie
    void display(void);
    // récupére le delta entre l'affichage de deux frames
    float getTime(void)const;

    // récupére les événements associés à la fenêtre
    sf::Event getEvent()const;
};

#endif
