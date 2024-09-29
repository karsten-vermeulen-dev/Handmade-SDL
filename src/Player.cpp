#include "Input.h"
#include "Player.h"

//======================================================================================================
Player::Player(int runSpeed, int jumpSpeed) : runSpeed(runSpeed), jumpSpeed(jumpSpeed)
{
	idleAnimation.Load("Characters/Adventure girl_idle.png", "Idle");
	idleAnimation.SetTexture("Idle");
	idleAnimation.SetDimension(196, 200);
	idleAnimation.SetSourceDimension(10, 1, 5880, 600);
	idleAnimation.IsAnimated(true);
	idleAnimation.IsAnimationLooping(true);
	idleAnimation.SetAnimationVelocity(15.0f);

	runAnimation.Load("Characters/Adventure girl_run.png", "Run");
	runAnimation.SetTexture("Run");
	runAnimation.SetDimension(196, 200);
	runAnimation.SetSourceDimension(8, 1, 4704, 600);
	runAnimation.IsAnimated(true);
	runAnimation.IsAnimationLooping(true);
	runAnimation.SetAnimationVelocity(15.0f);

	jumpAnimation.Load("Characters/Adventure girl_jump.png", "Jump");
	jumpAnimation.SetTexture("Jump");
	jumpAnimation.SetDimension(196, 200);
	jumpAnimation.SetSourceDimension(10, 1, 5880, 600);
	jumpAnimation.IsAnimated(true);
	jumpAnimation.IsAnimationLooping(false);
	jumpAnimation.SetAnimationVelocity(6.0f);

	footsteps.Load("Melee.wav", "Foot");
	footsteps.SetSound("Foot");

	//The collider dimension is slightly smaller than the actual sprite
	//because the raw image has a gap on the right and bottom of the image
	bound.SetDimension(125, 165);

	//Make sure game object dimension is same 
	//as collider because the sprite has gaps
	SetDimension(125, 165);
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

	static bool hasSwapped = false;

	if (Input::Instance()->IsKeyPressed(HM_KEY_LEFT) && !isJumping)
	{
		//If we're still facing right, adjust x position because the collider is different 
		//when flipped and this messes with the collision tests when changing direction
		if (direction == Direction::Right)
		{
			position.x -= 40;
		}

		direction = Direction::Left;
		activeAnimation = &runAnimation;
		runVelocity = Vector<int>::Left * runSpeed;
	}

	else if (Input::Instance()->IsKeyPressed(HM_KEY_RIGHT) && !isJumping)
	{
		//Same as above, just reversed
		if (direction == Direction::Left)
		{
			position.x += 40;
		}

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

	//We offset the collider a little because the raw sprite image has gaps on the 
	//top and left of it. For this we use the direction the image is facing, which 
	//has an associated offset value. The reason the values are different based on 
	//direction is because when flipping the sprite, the sprite 'gaps' also flip 
	bound.SetPosition(position.x + (int)direction, position.y + 10);
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

	//bound.Render();

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

void Player::HandleCollision(const GameObject& object)
{
	if (isJumping)
	{
		isJumping = false;
		jumpVelocity = Vector<int>::Zero;

		jumpAnimation.ResetAnimation();
		activeAnimation = &idleAnimation;

		//TODO - '5' can now be a const 'pushback' value
		position.y = object.GetPosition().y - dimension.y - 5;
	}

	else
	{
		runSpeed = 0;

		if (direction == Direction::Left)
		{
			position.x += 5;
		}

		else 
		{
			position.x -= 5;
		}
	}
}