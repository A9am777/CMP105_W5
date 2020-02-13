#include "Mario.h"

Mario::Mario()
{
	setSize(sf::Vector2f(15, 21));
	tex.loadFromFile("gfx/MarioSheetT.png");
	setTexture(&tex);

	for (int i = 0; i < 4; i++)
	{
		walk.addFrame(sf::IntRect(15 * i, 0, 15, 21));
	}
	walk.setFrameSpeed(0.1f);

	for (int i = 0; i < 3; i++)
	{
		swim.addFrame(sf::IntRect(16 * i, 21, 16, 20));
	}
	swim.setFrameSpeed(0.2f);

	for (int i = 0; i < 2; i++)
	{
		duck.addFrame(sf::IntRect(16 * i, 41, 16, 20));
	}
	duck.setFrameSpeed(0.5f);

	curAnim = &duck;
}


Mario::~Mario()
{

}

void Mario::handleInput(float dt)
{
	velocity = sf::Vector2f(0, 0);
	animate = false;
	if (input->isKeyDown(sf::Keyboard::D)) { velocity += sf::Vector2f(80, 0); walk.setFlipped(false); animate = true; curAnim = &walk; }
	if (input->isKeyDown(sf::Keyboard::A)) { velocity += sf::Vector2f(-80, 0); walk.setFlipped(true); animate = true; curAnim = &walk; }
	if (input->isKeyDown(sf::Keyboard::S)) { curAnim = &duck; animate = true; }
	if (input->isKeyDown(sf::Keyboard::Space)) { curAnim = &swim; animate = true; }
}

void Mario::update(float dt)
{
	setPosition(getPosition() + dt * getVelocity());

	if (animate) { curAnim->animate(dt); }
	setTextureRect(curAnim->getCurrentFrame());
}