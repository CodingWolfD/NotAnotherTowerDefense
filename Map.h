#pragma once
#include <SFML\Graphics\Texture.hpp>
#include "Framework/GameObject.h"
#include "Framework/TileMap.h"

class Map
{
	public:
		Map();

		void initialiseLevel();
		void createMap();
		void render(sf::RenderWindow* window);

		std::vector<GameObject>* getMap();

	private:
		TileMap tileMap;

		GameObject tile;
		std::vector<GameObject> tiles;
};