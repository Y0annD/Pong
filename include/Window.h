#ifndef WINDOW_H
#define WINDOW_H
#include <SFML/Graphics.hpp>

class Window {
  private :
  // nom de la fenetre
  std::string _name;
  // dimensions de la fen�tre
  unsigned int _width, _height;
  // objet SFML Qui d�fini la fenetre
    sf::RenderWindow *_win;
    sf::Event _event;

  public :
    /**
     * Constructeur
     * string n: Nom de la fen�tre
     * int w     : Largeur de la fenetre
     * int h      : Hauteur de la fen�tre
     **/
    Window(std::string n,unsigned int w,unsigned int h) : _name(n), _width(w), _height(h), 
      _win(new sf::RenderWindow(sf::VideoMode(_width, _height), _name)){} 
    // Destructeur de la fen�tre
    ~Window(void);
   
    // acc�sseurs de l'attribut _win, n�c�ssaire pour afficher les objets du Pong
    sf::RenderWindow* getWindow(void)const;
    /*
     * La fen�tre est-elle ouverte?
     * return true: fen�tre ouverte
     * return false: fen�tre ferm�e
     **/
    bool isOpen(void)const;
    // affiche la fen�tre apr�s l'avoir rafraichie
    void display(void);
    // r�cup�re le delta entre l'affichage de deux frames
    float getTime(void)const;

    // r�cup�re les �v�nements associ�s � la fen�tre
    sf::Event getEvent()const;
};

#endif
