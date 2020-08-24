#include "Map.h"

Map::Map()
{
	initialiseLevel();
}

void Map::initialiseLevel()
{
	tileMap.loadTexture("gfx/SpriteSheets/tileSheets/Level1/testTiles.png");

	for (int i = 0; i < 2; ++i)
	{
		tile.setSize(sf::Vector2f(64, 64));
		tile.setCollisionBox(0, 0, 64, 64);
		tile.setCollider(true);
		tiles.push_back(tile);
	}

	tiles[0].setTextureRect(sf::IntRect(0, 0, 16, 16));
	tiles[1].setTextureRect(sf::IntRect(250, 0, 16, 16));

	tiles[0].setPlayerCanPlace(true);
	tiles[1].setPlayerCanPlace(false);

	tileMap.setTileSet(tiles);
	createMap();
}

void Map::createMap()
{
	sf::Vector2u mapSize(15, 11);

	std::vector<int> map =
	{
		0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0
	};

	tileMap.setTileMap(map, mapSize);
	tileMap.setPosition(sf::Vector2f(0, 0));
	tileMap.buildLevel();
}

std::vector<GameObject>* Map::getMap()
{
	return tileMap.getLevel();
}

void Map::render(sf::RenderWindow* window)
{
	tileMap.render(window);
}