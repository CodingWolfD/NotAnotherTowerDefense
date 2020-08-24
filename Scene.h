#pragma once
#include "SFML/Graphics/RenderWindow.hpp"
#include "Framework/Input.h"
#include "Framework/GameState.h"
#include "Framework/AudioManager.h"
#include "Framework/TileMap.h"
#include <iostream>
#include "Map.h"
#include "GameUI.h"

class Scene
{
	public:
		Scene();
		Scene(sf::RenderWindow* window, Input* in, GameState* gs, AudioManager* aud);
		~Scene();

		virtual void handleInput(float dt, Input* in);
		virtual void update(float dt);
		virtual void render();

		virtual State getGameState();
		virtual void setGameState(State state);
	
	protected:
		sf::RenderWindow* window;
		Input* input;
		GameState* gameState;
		AudioManager* audio;

		sf::Font f_arialFont;

		void beginDraw();
		void endDraw();
};