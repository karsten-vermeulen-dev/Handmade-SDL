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

	enum class CollisionSide
	{
		Left,
		Right,
		Top,
		Bottom,
		None
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
	bool isFalling{ false };

	Sound footsteps;
	BoxCollider bound;

	Texture runAnimation;
	Texture idleAnimation;
	Texture jumpAnimation;
	Texture* activeAnimation{ nullptr };

	Vector<int> runVelocity;
	Vector<int> jumpVelocity;
	Vector<int> gravity{ 0, 1 };

	CollisionSide collisionSide{ CollisionSide::None };
	FacingDirection facingDirection{ FacingDirection::Right };
	
};