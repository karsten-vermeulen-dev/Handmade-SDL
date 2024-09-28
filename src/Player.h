#pragma once
#include "BoxCollider.h"
#include "GameObject.h"
#include "Sound.h"
#include "Texture.h"
#include "Vector.h"

class Player : public GameObject
{

public:

	enum class Direction
	{
		Left,
		Right
	};

	Player(int speed = 5);
	~Player() override;

	const BoxCollider& GetBound();

	void Update(int deltaTime) override;
	bool Render() override;

private:

	int speed{ 5 };
	int jumpSpeed{ 25 };
	bool isJumping{ false };

	Sound footsteps;
	BoxCollider bound;

	Texture runAnimation;
	Texture idleAnimation;
	Texture jumpAnimation;
	Texture* activeAnimation{ nullptr };

	Vector<int> jumpVelocity;
	Vector<int> walkDirection;
	Vector<int> gravity{ 0, 1 };
	Direction direction{ Direction::Right };
	
};