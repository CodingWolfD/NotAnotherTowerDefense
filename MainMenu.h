#pragma once

#include <SFML/Graphics.hpp>
#include "Framework/Input.h"
#include "Framework/AudioManager.h"
#include "Framework/GameState.h"
#include "Scene.h"
#include <string>
#include <iostream>
#include "Button.h"
#include "Framework/Collision.h"

class MainMenu : public Scene
{
	public:
		MainMenu(sf::RenderWindow* hwnd, Input* in, GameState* state, AudioManager* audio);
		~MainMenu();

		void handleInput(float dt);
		void update(float dt);
		void render();

	private:
		sf::Text txt_titleText;
		sf::Text txt_madeByText;

		Button* btn_playButton;
};