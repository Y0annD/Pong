#pragma once
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "PlayerPaddle.h"
#include "GameBall.h"
#include "GameObjectManager.h"

class SinglePlayerGame:Game
{
public:

	static void Start();

  const static GameObjectManager& GetGameObjectManager();
  const static int SCREEN_WIDTH  = 1024;
  const static int SCREEN_HEIGHT = 768;
  Game();

  /*void PlaySound(std::string filename);
    void PlaySong(std::string filename);*/

private:
	static bool IsExiting();
	static void GameLoop();

	static void ShowSplashScreen();
	static void ShowMenu();

	// Etats possible du jeu
	enum GameState{Uninitialized, 
					ShowingSplash,
					Paused,
					ShowingMenu, 
					Playing, 
					Exiting};

	static GameState _gameState;
	static sf::RenderWindow _mainWindow;

  // objets du jeu
  static GameObjectManager _gameObjectManager;

  static int _width, _height;
  //  ServiceLocator _soundProvider;
};
