#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects
	zombie.setInput(in);
	zombie.setPosition(sf::Vector2f(window->getSize().x/2, window->getSize().y/2));
	zombie.setVelocity(sf::Vector2f(0, 0));
	zombie.setAlive(true);

	mario.setInput(in);
	mario.setPosition(sf::Vector2f(window->getSize().x / 2, window->getSize().y / 2-100));
	mario.setVelocity(sf::Vector2f(0, 0));
	mario.setAlive(true);
}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	zombie.handleInput(dt);
	mario.handleInput(dt);
}

// Update game objects
void Level::update(float dt)
{
	zombie.update(dt);
	mario.update(dt);
}

// Render level
void Level::render()
{
	beginDraw();
	window->draw(zombie);
	window->draw(mario);
	endDraw();
}

// clear back buffer
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}