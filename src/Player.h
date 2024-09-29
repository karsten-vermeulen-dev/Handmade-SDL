#pragma once
#include "BoxCollider.h"
#include "GameObject.h"
#include "Sound.h"
#include "Texture.h"

class Player : public GameObject
{

public:

	enum class Direction
	{
		Left = 55,
		Right = 15
	};

	Player(int runSpeed, int jumpSpeed);
	~Player() override;

	void Start();

	void Stop();

	const BoxCollider& GetBound();

	void Update(int deltaTime) override;
	bool Render() override;

private:

	int runSpeed{ 0 };
	int jumpSpeed{ 0 };
	
	bool isJumping{ false };

	Sound footsteps;
	BoxCollider bound;

	Texture runAnimation;
	Texture idleAnimation;
	Texture jumpAnimation;
	Texture* activeAnimation{ nullptr };

	Vector<int> runVelocity;
	Vector<int> jumpVelocity;
	Vector<int> gravity{ 0, 1 };

	Direction direction{ Direction::Right };
	
};