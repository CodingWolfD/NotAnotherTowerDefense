#include "Enemy.h"

Enemy::Enemy(sf::Vector2f position, sf::Vector2f size, float health, sf::Color colour, Node nodes[])
{
	this->v_position = position;
	this->v_enemySize = size;
	this->f_enemyHealth = health;

	g_enemy.setSize(v_enemySize);
	g_enemy.setPosition(v_position);
	g_enemy.setFillColor(colour);

	for (int i = 0; i < 5; ++i)
	{
		a_nodes[i] = nodes[i];
	}

	f_speed = 30;
	i_index = 0;
}

Enemy::Enemy() {}

void Enemy::update(float dt)
{
	moveToDestination(v_destination, dt);
}

void Enemy::moveToDestination(sf::Vector2f destination, float dt)
{
	if (g_enemy.getPosition().y == destination.y && g_enemy.getPosition().x < destination.x)
	{
		g_enemy.move(f_speed * dt, 0);
	}
	else if (g_enemy.getPosition().y == destination.y && g_enemy.getPosition().x > destination.x)
	{
		g_enemy.move(-f_speed * dt, 0);
	}
	else if (g_enemy.getPosition().x == destination.x && g_enemy.getPosition().y < destination.y)
	{
		g_enemy.move(0, f_speed * dt);
	}
	else if (g_enemy.getPosition().x == destination.x && g_enemy.getPosition().y > destination.y)
	{
		g_enemy.move(0, -f_speed * dt);
	}
	
	if (g_enemy.getPosition().x == destination.x && g_enemy.getPosition().y == destination.y)
	{
		++i_index;
		setDestination(a_nodes, i_index);
	}
	
	if (g_enemy.getPosition().x == a_nodes[4].getNodePosition().x && g_enemy.getPosition().y == a_nodes[4].getNodePosition().y)
	{
		std::cout << "Reached the last waypoint!";
		setAlive(false);
	}
}

void Enemy::setDestination(Node nodes[], int index)
{
	v_destination = nodes[index].getNodePosition();
}

void Enemy::render(sf::RenderWindow* window)
{
	window->draw(g_enemy);
}

float Enemy::getHealth()
{
	return f_enemyHealth;
}

void Enemy::setHealth(float newHealth)
{
	f_enemyHealth = newHealth;
}