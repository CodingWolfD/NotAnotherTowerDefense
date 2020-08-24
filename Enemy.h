#pragma once

#include "Framework/GameObject.h"
#include "Node.h"
#include <iostream>

class Enemy : public GameObject
{
public:
	Enemy(sf::Vector2f position, sf::Vector2f size, float health, sf::Color colour, Node nodes[]);
	Enemy();

	void render(sf::RenderWindow* window);
	void setHealth(float newHealth);

	void setDestination(Node nodes[], int index);
	void moveToDestination(sf::Vector2f newPosition, float dt);

	void update(float dt);

	float getHealth();

private:
	sf::Sprite s_enemySprite;
	sf::Texture t_enemyTexture;
	sf::Vector2f v_position;
	sf::Vector2f v_enemySize;
	sf::Vector2f v_destination;

	Node a_nodes[5];

	GameObject g_enemy;

	int i_index;

	float f_enemyHealth;
	float f_speed;
};