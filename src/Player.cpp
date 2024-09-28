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

	jumpAnimation.Load("Characters/Adventure girl_jump.png", "Jump");
	jumpAnimation.SetTexture("Jump");
	jumpAnimation.SetDimension(200, 200);
	jumpAnimation.SetSourceDimension(10, 1, 5880, 600);
	jumpAnimation.IsAnimated(true);
	jumpAnimation.IsAnimationLooping(false);
	jumpAnimation.SetAnimationVelocity(6.0f);

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

	if (Input::Instance()->IsKeyPressed(HM_KEY_LEFT) && state != State::Jumping)
	{
		state = State::Walking;
		direction = Direction::Left;
		walkDirection = Vector<int>::Left;
	}

	else if (Input::Instance()->IsKeyPressed(HM_KEY_RIGHT) && state != State::Jumping)
	{
		state = State::Walking;
		direction = Direction::Right;
		walkDirection = Vector<int>::Right;
	}

	else if(state != State::Jumping)
	{
		state = State::Idle;
		walkDirection = Vector<int>::Zero;
	}

	//TODO: Jump vector should really be 'Up'. This will 
	//be changed in the Vector class in a future update
	if (Input::Instance()->IsKeyPressed(HM_KEY_SPACE) && state != State::Jumping)
	{
		state = State::Jumping;
		jumpVelocity = (Vector<int>::Down * jumpSpeed) + (walkDirection * velocity);
	}

	//-----------------------------------------------------------------------

	//We are jumping
	if (state == State::Jumping)
	{
		jumpVelocity += gravity;
		position += jumpVelocity;

		if (position.y >= 670)
		{
			position.y = 670;
			state = State::Idle;
			jumpVelocity = Vector<int>::Zero;
			jumpAnimation.ResetAnimation();
		}
	}

	else
	{
		position += walkDirection * velocity;
	}

	bound.SetPosition(position.x, position.y);

	if (state == State::Idle)
	{
		idleAnimation.Update(deltaTime);
	}

	else if (state == State::Walking)
	{
		walkAnimation.Update(deltaTime);
	}

	else if (state == State::Jumping)
	{
		jumpAnimation.Update(deltaTime);
	}
}
//======================================================================================================
bool Player::Render()
{
	//Flag to be used for playing "footstep" sound effect
	//We don't want it to play multiple times at once!
	//static bool isWalking = false;

	//if (!isWalking)
	//{
	//	//footsteps.Play();
	//	isWalking = true;
	//}

	Texture* animationToRender{ nullptr };

	if (state == State::Jumping)
	{
		animationToRender = &jumpAnimation;
	}

	else if (state == State::Idle)
	{
		animationToRender = &idleAnimation;
	}

	else
	{
		animationToRender = &walkAnimation;
	}

	if (direction == Direction::Left)
	{
		animationToRender->Render(position.x, position.y, 0.0, Texture::Flip::Horizontal);
	}

	else
	{
		animationToRender->Render(position.x, position.y);
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