// Main
// Entry point of the application.
// Handles window creation and window events.
// Contains the game loop, updates input class and contains the level objects.
// @author Paul Robertson

#include <iostream>
#include "Level.h"
#include "MainMenu.h"
#include "Splashscreen.h"

int main()
{
	//Create the window
	sf::RenderWindow window(sf::VideoMode(1200, 675), "Tower Defense");

	// Initialise input and level objects.
	Input input;
	GameState gameState;
	AudioManager audio;

	Splashscreen splashScreen(&window, &input, &gameState, &audio);
	Level level(&window, &input, &gameState, &audio);
	MainMenu menu(&window, &input, &gameState, &audio);

	// Initialise objects for delta time
	sf::Clock clock;
	float deltaTime;

	gameState.setCurrentState(State::SPLASHSCREEN);

	// Game Loop
	while (window.isOpen())
	{
		// Handle window events.
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
				case sf::Event::Closed:
				{
					window.close();
				}
					break;
				case sf::Event::KeyPressed:
				{
					// update input class
					input.setKeyDown(event.key.code);
				}
					break;
				case sf::Event::KeyReleased:
				{
					//update input class
					input.setKeyUp(event.key.code);
				}
					break;
				case sf::Event::MouseMoved:
				{
					//update input class
					input.setMousePosition(event.mouseMove.x, event.mouseMove.y);
				}	
					break;
				case sf::Event::MouseButtonPressed:
				{
					if (event.mouseButton.button == sf::Mouse::Left)
					{
						//update input class
						input.setMouseLDown(true);
					}
					else if (event.mouseButton.button == sf::Mouse::Right)
					{
						input.setMouseRDown(true);
					}
				}
					break;
				case sf::Event::MouseButtonReleased:
				{
					if (event.mouseButton.button == sf::Mouse::Left)
					{
						//update input class
						input.setMouseLDown(false);
					}
					else if (event.mouseButton.button == sf::Mouse::Right)
					{
						input.setMouseRDown(false);
					}
				}
					break;
				default:
					// don't handle other events
					break;
			}
		}

		// Calculate delta time. How much time has passed 
		// since it was last calculated (in seconds) and restart the clock.
		deltaTime = clock.restart().asSeconds();

		switch (gameState.getCurrentState())
		{
			case State::SPLASHSCREEN:
			{
				splashScreen.handleInput(deltaTime);
				splashScreen.update(deltaTime);
				splashScreen.render();
		}
				break;
			case State::MENU:
			{
				menu.handleInput(deltaTime);
				menu.update(deltaTime);
				menu.render();
			}
				break;
			case State::OPTIONS:
			{

			}
				break;
			case State::LEVEL:
			{
				// Call standard game loop functions (input, update and render)
				level.handleInput(deltaTime);
				level.update(deltaTime);
				level.render();
			}
				break;
			case State::PAUSE:
			{

			}
				break;
			case State::CREDITS:
			{

			}
				break;
		}
	}
}