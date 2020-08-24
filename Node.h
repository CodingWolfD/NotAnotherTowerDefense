#pragma once

#include "SFML/Graphics.hpp"
#include "Framework/GameObject.h"

class Node : GameObject
{
	public:
		Node(sf::Vector2f instancePosition, sf::Vector2f instanceSize);
		Node();
		~Node();

		void setupNode();
		void render(sf::RenderWindow* window);

		sf::Vector2f getNodePosition();

	private:
		sf::Vector2f v_position;
		sf::Vector2f v_size;

		GameObject g_node;
};