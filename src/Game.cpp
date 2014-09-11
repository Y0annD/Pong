#include "stdafx.h"
#include "Game.h"
#include "MainMenu.h"
#include "SplashScreen.h"


// Initialisation des variables
Game::Game(){
}

// Méthode qui démarre le jeu
void Game::Start(void){
	// si le jeu n'est pas initialisé, on quitte
  if(DEBUG)
    std::cout<<"Start"<<std::endl;
	if (_gameState != Uninitialized)
		return;

	// on crée une fenêtre principale de 1024 x 768
	_mainWindow.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32), "Corsaire");

  if(DEBUG)
    std::cout<<"Window created"<<std::endl;

  PlayerPaddle *player1 = new PlayerPaddle();
  player1->SetPosition((SCREEN_WIDTH/2), SCREEN_HEIGHT - 68);

  GameBall *ball = new GameBall();
  ball->SetPosition(SCREEN_WIDTH/2,SCREEN_HEIGHT/2);
  
  _gameObjectManager.Add("Ball",ball);
  _gameObjectManager.Add("Paddle1",player1);  

  /*SFMLSoundProvider _soundProvider;
  ServiceLocator::RegisterServiceLocator(&_soundProvider);
  ServiceLocator::GetAudio()->PlaySong("res/audio/soundtrack.ogg",true);*/
  
  
  
  _gameState = Game::ShowingSplash;

  
	// boucle principale
	while (!IsExiting())
	{
		GameLoop();
	}

	_mainWindow.close();
}

/**
**	Vérifie l'état de l'enum GameState
**  Renvoi true si gameState vaut Exiting
**  Renvoi false sinon	
*/
bool Game::IsExiting(){
	// si l'enum vaut Exiting, on renvoi true
	if (_gameState == Game::Exiting){
		return true;
	}
	return false;
}

void Game::GameLoop(){
	sf::Event currentEvent;
 
  _mainWindow.pollEvent(currentEvent);
   switch (_gameState){
   case Game::ShowingMenu:
     {
       ShowMenu();
       break;
     }
   case Game::ShowingSplash:
     {
       ShowSplashScreen();
       break;
     }
   case Game::Playing:
     {
       _mainWindow.clear(sf::Color(25, 25, 25));
       _gameObjectManager.UpdateAll();
       _gameObjectManager.DrawAll(_mainWindow);
       _mainWindow.display();
       
       if (currentEvent.type == sf::Event::Closed){
         _gameState = Game::Exiting;
       }
       if(currentEvent.type == sf::Event::KeyPressed){
         if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) ShowMenu();
       }
       
       break;
     }
   }
}

void Game::ShowSplashScreen()
{
	SplashScreen splashScreen;
	splashScreen.Show(_mainWindow);
	_gameState = Game::ShowingMenu;
}

const GameObjectManager& Game::GetGameObjectManager()
{
  return Game::_gameObjectManager;
}

void Game::ShowMenu()
{
	MainMenu mainMenu;
	MainMenu::MenuResult result = mainMenu.Show(_mainWindow);
	switch (result)
	{
	case MainMenu::Quitter:
		_gameState = Game::Exiting;
		break;

	case MainMenu::Jouer:
		_gameState = Game::Playing;
		break;
	}
}

/*void Game::PlaySound(std::string file)
{
  _soundProvider.PlaySound(file);
}

void Game::PlaySong(std::string file)
{
  _soundProvider.PlaySong(file);
}
*/

Game::GameState Game::_gameState = Uninitialized;
sf::RenderWindow Game::_mainWindow;
GameObjectManager Game::_gameObjectManager;
