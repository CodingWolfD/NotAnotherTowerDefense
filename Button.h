#pragma once

#include <SFML/Graphics.hpp>
#include "Framework/Input.h"
#include "Framework/AudioManager.h"
#include "Framework/GameState.h"
#include "Framework/GameObject.h"
#include <iostream>

class Button : public GameObject
{
	public:
		Button();
		Button(sf::Vector2f position, sf::Vector2f size, std::string filePath);
		~Button();

		void handleInput(float dt) override;
		void update(float dt) override;
		void render(sf::RenderWindow* window);

		sf::Vector2f getPos();
		sf::Texture* getBTexture();

	private:
		sf::Vector2f v_position;
		sf::Texture* t_buttonTexture;
		GameObject button;
};