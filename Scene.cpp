#include "Scene.h"

Scene::Scene() {}

Scene::Scene(sf::RenderWindow* wind, Input* in, GameState* gs, AudioManager* aud)
{
	window = wind;
	input = in;
	gameState = gs;
	audio = aud;
}

Scene::~Scene() {}

void Scene::handleInput(float dt, Input* in)
{

}

void Scene::update(float dt)
{

}

void Scene::render()
{
	beginDraw();
	endDraw();
}

void Scene::beginDraw()
{
	window->clear(sf::Color(0, 0, 0));
}

void Scene::endDraw()
{
	window->display();
}

State Scene::getGameState()
{
	return gameState->getCurrentState();
}

void Scene::setGameState(State state)
{
	gameState->setCurrentState(state);
}