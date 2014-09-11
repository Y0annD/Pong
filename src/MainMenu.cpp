#include "stdafx.h"
#include "MainMenu.h"


MainMenu::MenuResult MainMenu::Show(sf::RenderWindow& window)
{
	// charger l'image du menu
	sf::Texture image;
	image.loadFromFile("res/images/mainMenu.png");
	sf::Sprite sprite;
	sprite.setTexture(image);

	/*sf::RectangleShape rectangle(sf::Vector2f(1025, 235));
	rectangle.setPosition(sf::Vector2f(0, 145));
	rectangle.setFillColor(sf::Color(255, 0, 0));*/

	// zones clickables
	MenuItem playButton;
	playButton.rect.top = 145;
	playButton.rect.height = 235;
	playButton.rect.left = 0;
	playButton.rect.width = 1023;
	playButton.action = Jouer;


	MenuItem exitButton;
	exitButton.rect.top = 383;
	exitButton.rect.height = 235;
	exitButton.rect.left = 0;
	exitButton.rect.width = 1023;
	exitButton.action = Quitter;
	
	/*sf::RectangleShape rectangle1(sf::Vector2f(1025, 235));
	rectangle1.setPosition(sf::Vector2f(0, 383));
	rectangle1.setFillColor(sf::Color(0, 255, 0));*/

	_menuItems.push_back(playButton);
	_menuItems.push_back(exitButton);


	window.draw(sprite);
	/*window.draw(rectangle);
	window.draw(rectangle1);*/
	window.display();


	return GetMenuResponse(window);
}

MainMenu::MenuResult MainMenu::HandleClick(int x, int y)
 {
	   std::list<MenuItem>::iterator it;
	   std::cout << "Click " << x << ":" << y << std::endl;
	   for (it = _menuItems.begin(); it != _menuItems.end(); it++)
	   {
		   sf::Rect<int> menuItemRect = (*it).rect;
		   if (menuItemRect.top< y
			   && (menuItemRect.height+menuItemRect.top) > y
			   && menuItemRect.left < x
			   && menuItemRect.width > x)
		   {
			   return (*it).action;
		   }
	   }
	   return Rien;
	 }

 MainMenu::MenuResult  MainMenu::GetMenuResponse(sf::RenderWindow& window)
 {
   sf::Event menuEvent;

   while (true)
   {

     while (window.pollEvent(menuEvent))
     {
       if (menuEvent.type == sf::Event::MouseButtonPressed)
       {
         return HandleClick(menuEvent.mouseButton.x, menuEvent.mouseButton.y);
       }
       if (menuEvent.type == sf::Event::Closed)
       {
         return Quitter;
       }
     }
   }
}