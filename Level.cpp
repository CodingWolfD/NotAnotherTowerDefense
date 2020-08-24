#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in, GameState* state, AudioManager* aud)
{
	window = hwnd;
	input = in;
	gameState = state;
	audio = aud;

	initialiseLevel();
}

void Level::initialiseLevel()
{
	g_nodes[0] = Node(sf::Vector2f(210, 150), sf::Vector2f(32, 32));
	g_nodes[1] = Node(sf::Vector2f(270, 150), sf::Vector2f(32, 32));
	g_nodes[2] = Node(sf::Vector2f(270, 400), sf::Vector2f(32, 32));
	g_nodes[3] = Node(sf::Vector2f(400, 400), sf::Vector2f(32, 32));
	g_nodes[4] = Node(sf::Vector2f(400, 640), sf::Vector2f(32, 32));

	map = new Map();
	ui_background = new GameUI(window, sf::Vector2f(960, 0), sf::Vector2f(240, 675), sf::Color(128, 128, 128));
	ui_textUI = new GameUI(window, sf::Vector2f(960, 0), sf::Vector2f(240, 150), sf::Color(96, 96, 96));

	btn_playButton = new Button(sf::Vector2f(965, 620), sf::Vector2f(50, 50), "gfx/buttons/playButton.png");
	btn_playButton->setCollider(true);
	btn_playButton->setCollisionBox(sf::FloatRect(sf::Vector2f(965, 620), sf::Vector2f(50, 50)));

	i_currentMoney = 300;
	i_currentWave = 1;
	i_lives = 100;

	i_numOfEnemies = 0;
	i_enemiesSpawned = 0;

	startSpawn = false;
	clickedTower = false;

	if (!f_arialFont.loadFromFile("font/arial.ttf"))
	{
		std::cout << "Font file couldn't be located!";
	}

	txt_waveText.setFont(f_arialFont);
	txt_waveText.setFillColor(sf::Color::White);
	txt_waveText.setPosition(975, 10);
	txt_waveText.setCharacterSize(25);
	txt_waveText.setString("Wave: " + std::to_string(i_currentWave));

	txt_livesText.setFont(f_arialFont);
	txt_livesText.setFillColor(sf::Color::White);
	txt_livesText.setPosition(975, 60);
	txt_livesText.setCharacterSize(25);
	txt_livesText.setString("Lives: " + std::to_string(i_lives));

	txt_moneyText.setFont(f_arialFont);
	txt_moneyText.setFillColor(sf::Color::White);
	txt_moneyText.setPosition(975, 40);
	txt_moneyText.setCharacterSize(25);
	txt_moneyText.setString("Money: " + std::to_string(i_currentMoney));

	txt_timeText.setFont(f_arialFont);
	txt_timeText.setFillColor(sf::Color::White);
	txt_timeText.setPosition(975, 100);
	txt_timeText.setCharacterSize(25);
	
	worldTiles = map->getMap();

	setupTowerLayout();
}

void Level::setupTowerLayout()
{
	towerButtons[0] = new Button(sf::Vector2f(980, 175), sf::Vector2f(75, 75), "gfx/UI/In-Game/Towers/Tower_1.png");
	towerButtons[1] = new Button(sf::Vector2f(1100, 175), sf::Vector2f(75, 75), "gfx/UI/In-Game/Towers/Tower_2.png");

	towerButtons[2] = new Button(sf::Vector2f(980, 300), sf::Vector2f(75, 75), "gfx/UI/In-Game/Towers/Tower_3.png");
	towerButtons[3] = new Button(sf::Vector2f(1100, 300), sf::Vector2f(75, 75), "gfx/UI/In-Game/Towers/Tower_4.png");

	initaliseTowerButtons();
}

void Level::initaliseTowerButtons()
{
	for (int i = 0; i < 4; ++i)
	{
		towerButtons[i]->setCollisionBox(sf::FloatRect(sf::Vector2f(towerButtons[i]->getPos().x, towerButtons[i]->getPos().y), sf::Vector2f(75, 75)));
		towerButtons[i]->setCollider(true);
	}
}

Level::~Level() {}

// handle user input
void Level::handleInput(float dt)
{
	if (Collision::checkBoundingBox(btn_playButton, sf::Vector2i(input->getMouseX(), input->getMouseY())))
	{
		if (input->isMouseLDown())
		{
			startSpawn = true;
			++i_currentWave;
			++i_numOfEnemies;
			txt_waveText.setString("Wave: " + std::to_string(i_currentWave));
			input->setMouseLDown(false);
		}
	}

	for (int i = 0; i < 4; ++i)
	{
		if (Collision::checkBoundingBox(towerButtons[i], sf::Vector2i(input->getMouseX(), input->getMouseY())))
		{
			if (input->isMouseLDown())
			{
				std::cout << "Tower " << i << " selected";

				chosenTower.setTexture(towerButtons[i]->getBTexture());
				chosenTower.setSize(sf::Vector2f(64, 64));

				clickedTower = true;

				input->setMouseLDown(false);
			}
		}
	}

	if (clickedTower && input->isMouseLDown())
	{
		std::cout << "placing tower!";

		Tower* newTower = new Tower(sf::Vector2f(input->getMouseX(), input->getMouseY()), sf::Vector2f(64, 64), 2, 100, chosenTower.getTexture());
		newTower->setAlive(true);

		towers.push_back(*newTower);
		this->i_currentMoney -= newTower->getBuyPrice();
		txt_moneyText.setString("Money: " + std::to_string(i_currentMoney));

		input->setMouseLDown(false);
	}

	if (input->isMouseRDown())
	{
		clickedTower = false;
		input->setMouseRDown(false);
	}
}

// Update game objects
void Level::update(float dt)
{
	for (std::list<Enemy>::iterator enemy = enemies.begin(); enemy != enemies.end(); ++enemy)
	{
		if (enemy->isAlive())
		{
			enemy->update(dt);
		}
	}

	if (startSpawn)
	{
		++i_spawnTimer;

		std::cout << i_spawnTimer;

		if (i_spawnTimer == 1500 && i_enemiesSpawned < i_numOfEnemies)
		{
			Enemy enemy = Enemy(sf::Vector2f(210, 0), sf::Vector2f(32, 32), 100, sf::Color::Red, g_nodes);
			enemy.setDestination(g_nodes, 0);
			enemy.setAlive(true);
			enemies.push_back(enemy);

			i_spawnTimer = 0; 
			++i_enemiesSpawned;

			if (i_enemiesSpawned == i_numOfEnemies)
			{
				i_spawnTimer = 0;
				i_enemiesSpawned = 0;
				startSpawn = false;
			}
		}
	}

	if (clickedTower)
	{
		chosenTower.setPosition(sf::Vector2f(input->getMouseX(), input->getMouseY()));
	}
}

// Render level
void Level::render()
{
	beginDraw();

	map->render(window);
	ui_background->render();
	ui_textUI->render();

	window->draw(txt_waveText);
	window->draw(txt_moneyText);
	window->draw(txt_livesText);
	window->draw(txt_timeText);

	btn_playButton->render(window);

	for (std::list<Enemy>::iterator enemy = enemies.begin(); enemy != enemies.end(); ++enemy)
	{
		if (enemy->isAlive())
		{
			enemy->render(window);
		}
	}

	for (int i = 0; i < 4; ++i)
	{
		towerButtons[i]->render(window);
	}

	for (std::list<Tower>::iterator tower = towers.begin(); tower != towers.end(); ++tower)
	{
		tower->render(window);
	}

	if (clickedTower)
	{
		window->draw(chosenTower);
	}

	endDraw();
}

void Level::setLives(int newLives)
{
	i_lives = newLives;
}

int Level::getLives()
{
	return i_lives;
}

std::list<Tower> Level::getTowers()
{
	return towers;
}