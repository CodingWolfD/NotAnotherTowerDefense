#pragma once

#include "Framework/GameObject.h"
#include "Level.h"

enum class e_upgradedState { teir1, teir2, teir3 };

class Tower : public GameObject
{
	public:
		Tower(sf::Vector2f position, sf::Vector2f size, int shootSpeed, int buyPrice, const sf::Texture* texture);
		void setTowerUpgrade(e_upgradedState upgrade);
		void setLevel(Level level);

		void setBuyPrice(int buyPrice);
		int getBuyPrice();

		virtual void update(float dt) override;
		virtual void render(sf::RenderWindow* window);

	private:
		sf::Sprite s_towerSprite;
		sf::Texture t_towerTexture;

		Level levelObject;

		sf::Vector2f v_position;
		sf::Vector2f v_towerSize;

		e_upgradedState e_state;

		int i_buyPrice;
		int i_shootSpeed;
		int i_range;

		GameObject g_tower;
		GameObject target;
};