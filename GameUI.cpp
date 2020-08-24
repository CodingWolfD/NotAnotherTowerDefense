#include "GameUI.h"

GameUI::GameUI(sf::RenderWindow* wnd, sf::Vector2f position, sf::Vector2f size, sf::Color backgroundColour)
{
	window = wnd;

	g_gameUI.setPosition(position);
	g_gameUI.setFillColor(backgroundColour);
	g_gameUI.setOutlineColor(sf::Color::White);
	g_gameUI.setOutlineThickness(3);
	g_gameUI.setSize(size);
}

void GameUI::render()
{
	window->draw(g_gameUI);
}