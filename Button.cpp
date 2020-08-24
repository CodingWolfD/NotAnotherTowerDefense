#include "Button.h"

Button::Button() {}

Button::Button(sf::Vector2f position, sf::Vector2f size, std::string filePath)
{
	t_buttonTexture = new sf::Texture();

	if (!t_buttonTexture->loadFromFile(filePath))
	{
		std::cout << "Couldn't locate the play button sprite!";
	}

	v_position = position;

	button.setPosition(position);
	button.setSize(size);
	button.setTexture(t_buttonTexture);
}

Button::~Button() {}

sf::Vector2f Button::getPos()
{
	return v_position;
}

sf::Texture* Button::getBTexture()
{
	return t_buttonTexture;
}

// handle user input
void Button::handleInput(float dt){}

void Button::render(sf::RenderWindow* window)
{
	window->draw(button);
}

// Update game objects
void Button::update(float dt){}