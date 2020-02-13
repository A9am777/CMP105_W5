#pragma once
#include "Framework\GameObject.h"
#include "Framework\Animation.h"
class Zombie:
public GameObject
{
	public:
		Zombie();
		~Zombie();

		void handleInput(float dt) override;
		void update(float dt) override;
	private:
		Animation walk;
		sf::Texture tex;
};

