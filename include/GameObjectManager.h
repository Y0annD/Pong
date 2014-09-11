#pragma once
#include "VisibleObject.h"

class GameObjectManager
{
 public:
  GameObjectManager();
  ~GameObjectManager();
  
  // Ajouter un object
  void Add(std::string name, VisibleObject* object);
  // Enlever un objet
  void Remove(std::string name);
  // retourne le nombre d'objet
  int GetObjectCount() const;
  // r�cup�re un object par son nom
  VisibleObject* Get(std::string name)const;
  
  // d�ssine tous les objets
  void DrawAll(sf::RenderWindow& renderWindow);
  // mise � jour de tous les objets
  void UpdateAll();

  
 private:
  std::map<std::string, VisibleObject*> _gameObjects;

  sf::Clock clock;

  float _time;
  struct GameObjectDeallocator
  {
    void operator()(const std::pair<std::string, VisibleObject*> & p)const
    {
      delete p.second;
    }
  };
};
