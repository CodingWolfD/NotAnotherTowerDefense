#pragma once

#include "Framework/Collision.h"
#include <iostream>
#include "Button.h"
#include "Tower.h"
#include <list>

class GameUI
{
	public:
		GameUI(sf::RenderWindow* window, sf::Vector2f position, sf::Vector2f size, sf::Color backgroundColour);
		void render();

	private:
		GameObject g_gameUI;

		sf::Texture t_backgroundTexture;
		sf::Text towerText[4];
		sf::RenderWindow* window;
};