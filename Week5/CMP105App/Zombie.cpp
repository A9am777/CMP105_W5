#include "Zombie.h"
#include <iostream>


Zombie::Zombie()
{
	setSize(sf::Vector2f(55,108));
	tex.loadFromFile("gfx/animZombie.png");
	setTexture(&tex);
	for (int i = 0; i < 8; i++)
	{
		walk.addFrame(sf::IntRect(55*i,0,55,108));
	}
	walk.setFrameSpeed(0.1f);
}


Zombie::~Zombie()
{

}

void Zombie::handleInput(float dt)
{
	velocity = sf::Vector2f(0, 0);
	if (input->isKeyDown(sf::Keyboard::D)) { velocity += sf::Vector2f(35,0); walk.setFlipped(false); }
	if (input->isKeyDown(sf::Keyboard::A)) { velocity += sf::Vector2f(-35, 0); walk.setFlipped(true); }
}

void Zombie::update(float dt)
{
	setPosition(getPosition() + dt *getVelocity());

	if (velocity.x*velocity.x+velocity.y*velocity.y>=0.001f) { walk.animate(dt); }
	setTextureRect(walk.getCurrentFrame());
}
