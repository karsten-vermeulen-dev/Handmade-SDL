#include "Input.h"
#include "Player.h"

//======================================================================================================
Player::Player()
{
	idleAnimation.Load("Characters/Adventure girl_idle.png", "Idle");
	idleAnimation.SetTexture("Idle");
	idleAnimation.SetDimension(200, 200);
	idleAnimation.SetSourceDimension(10, 1, 5880, 600);
	idleAnimation.IsAnimated(true);
	idleAnimation.IsAnimationLooping(true);
	idleAnimation.SetAnimationVelocity(15.0f);

	walkAnimation.Load("Characters/Adventure girl_run.png", "Walk");
	walkAnimation.SetTexture("Walk");
	walkAnimation.SetDimension(200, 200);
	walkAnimation.SetSourceDimension(8, 1, 4704, 600);
	walkAnimation.IsAnimated(true);
	walkAnimation.IsAnimationLooping(true);
	walkAnimation.SetAnimationVelocity(15.0f);

	footsteps.Load("Melee.wav", "Foot");
	footsteps.SetSound("Foot");

	//SetPosition(600, 500);
	bound.SetDimension(125, 250);
}
//======================================================================================================
const BoxCollider& Player::GetBound()
{
	return bound;
}
//======================================================================================================
void Player::SetVelocity(int velocity)
{
	this->velocity = velocity;
}
//======================================================================================================
void Player::Update(int deltaTime)
{
	auto keys = Input::Instance()->GetKey();

	//Check if left or right key is pressed and set player's direction accordingly
	//assign standing direction as well so that when no key is pressed the correct
	//direction is set for the standing stance and sprite of the player object
	if (Input::Instance()->IsKeyPressed(HM_KEY_LEFT))
	{
		standDirection = walkDirection = Vector<int>::Left;
	}

	else if (Input::Instance()->IsKeyPressed(HM_KEY_RIGHT))
	{
		standDirection = walkDirection = Vector<int>::Right;
	}

	else
	{
		walkDirection = Vector<int>::Zero;
	}

	position += walkDirection * velocity;
	bound.SetPosition(position.x, position.y);

	idleAnimation.Update(deltaTime);
	walkAnimation.Update(deltaTime);
}
//======================================================================================================
bool Player::Render()
{
	//Flag to be used for playing "footstep" sound effect
	//We don't want it to play multiple times at once!
	static bool isWalking = false;

	//Check if player is walking or not and render the correct walking cycle
	//render the correct standing stance sprite based on which way he is facing
	if (walkDirection.x == 0 && walkDirection.y == 0)
	{
		standDirection.x < 0.0f ? idleAnimation.Render(position.x, position.y, 0.0, Texture::Flip::Horizontal)
			: idleAnimation.Render(position.x, position.y);
		isWalking = false;
	}

	else
	{
		walkDirection.x < 0.0f ? walkAnimation.Render(position.x, position.y, 0.0, Texture::Flip::Horizontal)
			: walkAnimation.Render(position.x, position.y);

		if (!isWalking)
		{
			//footsteps.Play();
			isWalking = true;
		}
	}

	return true;
}
//======================================================================================================
Player::~Player()
{
	footsteps.Unload("Foot");
	walkAnimation.Unload("Walk");
	idleAnimation.Unload("Idle");
}