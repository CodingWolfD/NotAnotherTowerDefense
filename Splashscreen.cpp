#include "Splashscreen.h"

Splashscreen::Splashscreen(sf::RenderWindow* hwnd, Input* in, GameState* state, AudioManager* aud)
{
	window = hwnd;
	input = in;
	gameState = state;
	audio = aud;

	f_alpha = 0;
	f_displaySpeed = 30;
	v_imagePosition = sf::Vector2f(240, -50);

	if (!t_companyLogoTexture.loadFromFile("gfx/Icons/Autumn_Bomb.png"))
	{
		std::cout << "Couldn't located the splash screen image!";
	}

	s_companyLogo.setTexture(t_companyLogoTexture);
	s_companyLogo.setPosition(v_imagePosition);
	s_companyLogo.setColor(sf::Color(255, 255, 255, 0));
}

Splashscreen::~Splashscreen()
{

}

// handle user input
void Splashscreen::handleInput(float dt)
{

}

// Update game objects
void Splashscreen::update(float dt)
{
	if (f_alpha < 255)
	{
		f_alpha += f_displaySpeed * dt;
	}
	else
	{
		gameState->setCurrentState(State::MENU);
	}

	s_companyLogo.setColor(sf::Color(255, 255, 255, f_alpha));
}

// Render Splashscreen
void Splashscreen::render()
{
	beginDraw();
	window->draw(s_companyLogo);
	endDraw();
}