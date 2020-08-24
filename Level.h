#pragma once

#include <SFML/Graphics.hpp>
#include "Framework/Input.h"
#include "Framework/AudioManager.h"
#include "Framework/GameState.h"
#include "Framework/Collision.h"
#include "Scene.h"
#include <string>
#include <iostream>
#include "Node.h"
#include "Enemy.h"
#include <list>
#include "Button.h"

class Level : public Scene
{
	public:
		Level(sf::RenderWindow* hwnd, Input* in, GameState* state, AudioManager* audio);
		Level();
		~Level();

		void initialiseLevel();
		void setupTowerLayout();
		void initaliseTowerButtons();

		void handleInput(float dt);
		void update(float dt);
		void render();
		
		void setLives(int newLives);
		int getLives();

		std::list<Tower> getTowers();

	private:
		sf::Text txt_waveText;
		sf::Text txt_moneyText;
		sf::Text txt_livesText;
		sf::Text txt_timeText;

		std::vector<GameObject>* worldTiles;

		Button* towerButtons[4];

		Node g_nodes[5];
		Map* map;

		GameUI* ui_background;
		GameUI* ui_textUI;

		GameObject chosenTower;

		bool clickedTower;
		bool startSpawn;

		std::list<Tower> towers;
		std::list<Enemy> enemies;

		Button* btn_playButton;

		int i_numOfEnemies;
		int i_currentWave;
		int i_currentMoney;
		int i_lives;
		int i_spawnTimer;
		int i_enemiesSpawned;
};