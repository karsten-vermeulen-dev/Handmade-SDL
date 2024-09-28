#include "Input.h"
#include "Player.h"

//======================================================================================================
Player::Player(int runSpeed, int jumpSpeed) : runSpeed(runSpeed), jumpSpeed(jumpSpeed)
{
	idleAnimation.Load("Characters/Adventure girl_idle.png", "Idle");
	idleAnimation.SetTexture("Idle");
	idleAnimation.SetDimension(200, 200);
	idleAnimation.SetSourceDimension(10, 1, 5880, 600);
	idleAnimation.IsAnimated(true);
	idleAnimation.IsAnimationLooping(true);
	idleAnimation.SetAnimationVelocity(15.0f);

	runAnimation.Load("Characters/Adventure girl_run.png", "Run");
	runAnimation.SetTexture("Run");
	runAnimation.SetDimension(200, 200);
	runAnimation.SetSourceDimension(8, 1, 4704, 600);
	runAnimation.IsAnimated(true);
	runAnimation.IsAnimationLooping(true);
	runAnimation.SetAnimationVelocity(15.0f);

	jumpAnimation.Load("Characters/Adventure girl_jump.png", "Jump");
	jumpAnimation.SetTexture("Jump");
	jumpAnimation.SetDimension(200, 200);
	jumpAnimation.SetSourceDimension(10, 1, 5880, 600);
	jumpAnimation.IsAnimated(true);
	jumpAnimation.IsAnimationLooping(false);
	jumpAnimation.SetAnimationVelocity(6.0f);

	footsteps.Load("Melee.wav", "Foot");
	footsteps.SetSound("Foot");

	bound.SetDimension(125, 165);
}
//======================================================================================================
const BoxCollider& Player::GetBound()
{
	return bound;
}
//======================================================================================================
void Player::Update(int deltaTime)
{
	auto keys = Input::Instance()->GetKey();

	if (Input::Instance()->IsKeyPressed(HM_KEY_LEFT) && !isJumping)
	{
		direction = Direction::Left;
		activeAnimation = &runAnimation;
		runVelocity = Vector<int>::Left * runSpeed;
	}

	else if (Input::Instance()->IsKeyPressed(HM_KEY_RIGHT) && !isJumping)
	{
		direction = Direction::Right;
		activeAnimation = &runAnimation;
		runVelocity = Vector<int>::Right * runSpeed;
	}

	else if(!isJumping)
	{
		activeAnimation = &idleAnimation;
		runVelocity = Vector<int>::Zero;
	}

	//TODO: Jump vector should really be 'Up'. This will 
	//be changed in the Vector class in a future update
	if (Input::Instance()->IsKeyPressed(HM_KEY_SPACE) && !isJumping)
	{
		isJumping = true;
		activeAnimation = &jumpAnimation;
		jumpVelocity = Vector<int>::Down * jumpSpeed + runVelocity;
	}

	//-----------------------------------------------------------------------

	//We are jumping
	if (isJumping)
	{
		jumpVelocity += gravity;
		position += jumpVelocity;

		//When we hit the ground, we reset
		if (position.y >= 670)
		{
			position.y = 670;
			
			isJumping = false;
			jumpVelocity = Vector<int>::Zero;
			
			jumpAnimation.ResetAnimation();
			activeAnimation = &idleAnimation;
		}
	}

	//We are running or standing still
	else
	{
		position += runVelocity;
	}

	activeAnimation->Update(deltaTime);
	bound.SetPosition(position.x, position.y);
	bound.Update();
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

	if (direction == Direction::Left)
	{
		activeAnimation->Render(position.x, position.y, 0.0, Texture::Flip::Horizontal);
	}

	else
	{
		activeAnimation->Render(position.x, position.y);
	}

	return true;
}
//======================================================================================================
Player::~Player()
{
	footsteps.Unload("Foot");
	runAnimation.Unload("Run");
	idleAnimation.Unload("Idle");
	jumpAnimation.Unload("Jump");
}

void Player::Start()
{
	runSpeed = 9;
}

void Player::Stop()
{
	if (isJumping)
	{
		isJumping = false;
		jumpVelocity = Vector<int>::Zero;

		jumpAnimation.ResetAnimation();
		activeAnimation = &idleAnimation;

		position.y -= 15;
	}

	else
	{
		runSpeed = 0;
		position.x -= (int)direction;
	}
}