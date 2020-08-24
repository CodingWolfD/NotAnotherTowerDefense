#include "MainMenu.h"

MainMenu::MainMenu(sf::RenderWindow* hwnd, Input* in, GameState* state, AudioManager* aud)
{
	window = hwnd;
	input = in;
	gameState = state;
	audio = aud;

	if (!f_arialFont.loadFromFile("font/arial.ttf"))
	{
		std::cout << "Font file couldn't be located!";
	}

	btn_playButton = new Button(sf::Vector2f(400, 400), sf::Vector2f(250, 100), "gfx/buttons/playButton.png");
	btn_playButton->setCollider(true);
	btn_playButton->setCollisionBox(sf::FloatRect(sf::FloatRect(sf::Vector2f(400, 400), sf::Vector2f(250, 100))));

	txt_titleText.setFont(f_arialFont);
	txt_titleText.setFillColor(sf::Color::White);
	txt_titleText.setPosition(300, 0);
	txt_titleText.setCharacterSize(50);
	txt_titleText.setString("Not another Tower Defense");

	txt_madeByText.setFont(f_arialFont);
	txt_madeByText.setFillColor(sf::Color::White);
	txt_madeByText.setPosition(930, 650);
	txt_madeByText.setCharacterSize(20);
	txt_madeByText.setString("Made By: Autumn Bomb LTD");
}

MainMenu::~MainMenu() {}

// handle user input
void MainMenu::handleInput(float dt)
{
	if (Collision::checkBoundingBox(btn_playButton, sf::Vector2i(input->getMouseX(), input->getMouseY())))
	{
		if(input->isMouseLDown())
		{
			input->setMouseLDown(false);
			gameState->setCurrentState(State::LEVEL);
		}
	}
}

// Update game objects
void MainMenu::update(float dt) 
{
	
}

// Render MainMenu
void MainMenu::render()
{
	beginDraw();
	window->draw(txt_titleText);
	window->draw(txt_madeByText);

	btn_playButton->render(window);
	endDraw();
}