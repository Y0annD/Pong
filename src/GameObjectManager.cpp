#include "stdafx.h"
#include "GameObjectManager.h"

GameObjectManager::GameObjectManager():_time(0.0f)
{
}

GameObjectManager::~GameObjectManager()
{
  std::for_each(_gameObjects.begin(), _gameObjects.end(), GameObjectDeallocator());
}

void GameObjectManager::Add(std::string name, VisibleObject* object)
{
  _gameObjects.insert(std::pair<std::string,VisibleObject*>(name, object));
}

void GameObjectManager::Remove(std::string name)
{
  std::map<std::string, VisibleObject*>::iterator results = _gameObjects.find(name);
  if(results != _gameObjects.end())
    {
      delete results->second;
      _gameObjects.erase(results);
    }
}

VisibleObject* GameObjectManager::Get(std::string name)const
{
  std::map<std::string, VisibleObject*>::const_iterator results = _gameObjects.find(name);
  if(results == _gameObjects.end())
    {
      return NULL;
    }
  return results->second;
}

int GameObjectManager::GetObjectCount() const
{
  return _gameObjects.size();
}

void GameObjectManager::DrawAll(sf::RenderWindow& renderWindow)
{
  std::map<std::string,VisibleObject*>::const_iterator itr = _gameObjects.begin();
  while(itr != _gameObjects.end())
    {
      itr->second->Draw(renderWindow);
      itr++;
    }
}
    
void GameObjectManager::UpdateAll()
{
  std::map<std::string, VisibleObject*>::const_iterator itr =
    _gameObjects.begin();

  float timeDelta = clock.restart().asSeconds();
  _time += timeDelta;
  //  std::cout<< "Time: "<< timeDelta << std::endl;
  if(_time >= 1.0f/60.0f){
  while(itr != _gameObjects.end())
    {
      itr->second->Update();
      itr++;
    }
  _time = 0;
  }

  
}
