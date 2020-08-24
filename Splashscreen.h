#pragma once

#include <SFML/Graphics.hpp>
#include "Framework/Input.h"
#include "Framework/AudioManager.h"
#include "Framework/GameState.h"
#include "Scene.h"
#include <string>
#include <iostream>

class Splashscreen : public Scene
{
	public:
		Splashscreen(sf::RenderWindow* hwnd, Input* in, GameState* state, AudioManager* audio);
		~Splashscreen();

		void handleInput(float dt);
		void update(float dt);
		void render();

	private:
		sf::Texture t_companyLogoTexture;
		sf::Sprite s_companyLogo;

		sf::Vector2f v_imagePosition;

		float f_alpha;
		float f_displaySpeed;
};