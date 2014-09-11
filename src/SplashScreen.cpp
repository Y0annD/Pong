#include "stdafx.h"
#include "SplashScreen.h"


void SplashScreen::Show(sf::RenderWindow & renderWindow)
{
	sf::Texture image;
	if (image.loadFromFile("res/images/splash.png") != true)
	{
		std::cout << "splash.png introuvable" << std::endl;
		return;
	}

	sf::Sprite sprite;
	sprite.setTexture(image);

	renderWindow.draw(sprite);
	renderWindow.display();

	sf::Event event;
	while (true)
	{
		while (renderWindow.pollEvent(event))
		{
			if (event.type == sf::Event::KeyPressed
				|| event.type == sf::Event::MouseButtonPressed
				|| event.type == sf::Event::Closed)
			{
				return;
			}
		}
	}
}
