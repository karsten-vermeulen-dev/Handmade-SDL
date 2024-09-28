#pragma once
#include "BoxCollider.h"
#include "GameObject.h"
#include "Sound.h"
#include "Texture.h"
#include "Vector.h"

class Player : public GameObject
{

public:

	enum class State
	{
		Idle,
		Walking,
		Jumping,
		Shooting
	};

	enum class Direction
	{
		Left,
		Right
	};

	Player();
	~Player() override;

	const BoxCollider& GetBound();

	void SetVelocity(int velocity);

	void Update(int deltaTime) override;
	bool Render() override;

private:

	int velocity{ 5 };
	int jumpSpeed{ 25 };

	State state{ State::Idle };
	Direction direction{ Direction::Right };

	BoxCollider bound;
	Sound footsteps;

	Texture idleAnimation;
	Texture walkAnimation;
	Texture jumpAnimation;

	Vector<int> jumpVelocity;
	Vector<int> gravity{ 0, 1 };
	
	Vector<int> walkDirection;

};