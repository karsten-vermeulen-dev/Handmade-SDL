#pragma once

#include <vector>
#include "BoxCollider.h"
#include "GameObject.h"
#include "Sound.h"
#include "Texture.h"

#include "Obstacle.h"

class Player : public GameObject
{

public:

	enum class FacingDirection
	{
		Left = 70,
		Right = 15
	};

	Player(int runSpeed, int jumpSpeed);
	~Player() override;

	void OnCollision(BoxCollider& bound);

	const BoxCollider& GetBound();

	void Update(int deltaTime) override;
	bool Render() override;

private:

	int runSpeed{ 0 };
	int jumpSpeed{ 0 };
	
	bool isJumping{ false };
	bool isShooting{ false };
	
	Vector<int> runVelocity;
	Vector<int> jumpVelocity;
	Vector<int> gravity{ 0, 1 };
	
	Sound footsteps;
	BoxCollider bound;

	Texture runAnimation;
	Texture idleAnimation;
	Texture jumpAnimation;
	Texture shootAnimation;
	Texture* activeAnimation{ nullptr };

	FacingDirection facingDirection{ FacingDirection::Right };
	
};