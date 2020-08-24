#include "Tower.h"

Tower::Tower(sf::Vector2f position, sf::Vector2f size, int shootSpeed, int buyPrice, const sf::Texture* texture)
{
	this->e_state = e_upgradedState::teir1;

	g_tower.setPosition(position);
	g_tower.setSize(size);
	g_tower.setTexture(texture);

	this->i_shootSpeed = shootSpeed;
	this->i_buyPrice = buyPrice;
}

void Tower::update(float dt)
{
	for (std::list<Tower>::iterator towers = levelObject.getTowers().begin(); towers != levelObject.getTowers().end(); ++towers)
	{
		if (towers->getPosition().x < getPosition().x - i_range)
		{

		}
	}
}

void Tower::render(sf::RenderWindow* window)
{
	window->draw(g_tower);
}

int Tower::getBuyPrice()
{
	return i_buyPrice;
}

void Tower::setBuyPrice(int buyPrice)
{
	i_buyPrice = buyPrice;
}

void Tower::setTowerUpgrade(e_upgradedState upgrade)
{
	e_state = upgrade;
}

void Tower::setLevel(Level level)
{
	levelObject = level;
}