#include "Node.h"

Node::Node() {}

Node::Node(sf::Vector2f instancePosition, sf::Vector2f instanceSize)
{
	v_position = instancePosition;
	v_size = instanceSize;

	setupNode();
}

void Node::setupNode()
{
	g_node.setSize(v_size);
	g_node.setPosition(v_position);
	g_node.setCollisionBox(v_position.x, v_position.y, v_size.x, v_size.y);
	g_node.setFillColor(sf::Color::White);
}

void Node::render(sf::RenderWindow* window)
{
	window->draw(g_node);
}

sf::Vector2f Node::getNodePosition()
{
	return v_position;
}

Node::~Node() {}