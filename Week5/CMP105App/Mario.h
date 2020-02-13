#pragma once
#include "Framework/GameObject.h"
#include "Framework/Animation.h"

class Mario:
public GameObject
{
	public:
		Mario();
		~Mario();

		void handleInput(float dt) override;
		void update(float dt) override;
	private:
		Animation* curAnim;
		Animation walk;
		Animation duck;
		Animation swim;
		sf::Texture tex;
		bool animate;
};

