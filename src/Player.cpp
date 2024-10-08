#include "Input.h"
#include "Player.h"

#include <iostream>

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

	shootAnimation.Load("Characters/Adventure girl_shoot.png", "Shoot");
	shootAnimation.SetTexture("Shoot");
	shootAnimation.SetDimension(196, 200);
	shootAnimation.SetSourceDimension(3, 1, 1764, 600);
	shootAnimation.IsAnimated(true);
	shootAnimation.IsAnimationLooping(true);
	shootAnimation.SetAnimationVelocity(9.0f);

	//Player is idle by default
	activeAnimation = &idleAnimation;

	footsteps.Load("Melee.wav", "Foot");
	footsteps.SetSound("Foot");

	//The collider dimension is slightly smaller than the actual sprite
	//because the raw image has a gap on the right and bottom of the image
	bound.SetDimension(110, 165);

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
	static int timer{ 0 };

	//If player moves left, they musn't be jumping or shooting at the same time
	if (Input::Instance()->IsKeyPressed(HM_KEY_LEFT) && !isJumping && !isShooting)
	{
		//If we're facing right, adjust the x position 
		//because the sprite is different when flipped 
		if (facingDirection == FacingDirection::Right)
		{
			position.x -= 40;
		}

		activeAnimation = &runAnimation;
		facingDirection = FacingDirection::Left;
		runVelocity = Vector<int>::Left * runSpeed;
	}

	//If player moves right, they also musn't be jumping or shooting at the same time
	else if (Input::Instance()->IsKeyPressed(HM_KEY_RIGHT) && !isJumping && !isShooting)
	{
		//Same as above, only reversed
		if (facingDirection == FacingDirection::Left)
		{
			position.x += 40;
		}

		activeAnimation = &runAnimation;
		facingDirection = FacingDirection::Right;
		runVelocity = Vector<int>::Right * runSpeed;
	}

	//If player is shooting they can't do it mid-jump
	else if (Input::Instance()->IsKeyPressed(HM_KEY_E) && !isShooting && !isJumping)
	{
		isShooting = true;
		activeAnimation = &shootAnimation;
	}

	//Otherwise no keys are pressed and provided player is 
	//not jumping or shooting they remain idle and don't move
	else if(!isJumping && !isShooting)
	{
		activeAnimation = &idleAnimation;
		runVelocity = Vector<int>::Zero;
	}

	//-----------------------------------------------------------------------
	
	//We use a separate if-statement here and not if-else
	//because we want to run and jump at the same time
	
	//TODO: Jump vector should really be 'Up'. This will 
	//be changed in the Vector class in a future update
	if (Input::Instance()->IsKeyPressed(HM_KEY_SPACE) && !isJumping)
	{
		isJumping = true;
		activeAnimation = &jumpAnimation;
		jumpVelocity = Vector<int>::Down * jumpSpeed + runVelocity;
	}

	//-----------------------------------------------------------------------

	//If player is in the air, update their position
	//such that the applied gravity pulls them down
	if (isJumping)
	{
		jumpVelocity += gravity;
		position += jumpVelocity;
	}

	//If player is shooting their weapon, start the timer 
	//and once 1 second has passed, stop their shooting state
	else if (isShooting)
	{
		timer += deltaTime;

		if (timer > 1000)
		{
			timer = 0;
			isShooting = false;
			
			shootAnimation.ResetAnimation();
			activeAnimation = &idleAnimation;
		}
	}

	//If player is neither jumping nor shooting, they are either 
	//running or standing still so update their position either way
	else
	{
		position += runVelocity;
	}

	activeAnimation->Update(deltaTime);

	//We offset the collider a little because the raw sprite image has gaps on the 
	//top and left of it. For this we use the direction the image is facing, which 
	//has an associated offset value. The reason the values are different based on 
	//direction is because when flipping the sprite, the sprite 'gaps' also flip 
	bound.SetPosition(position.x + (int)facingDirection, position.y + 10);
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

	if (facingDirection == FacingDirection::Left)
	{
		activeAnimation->Render(position.x, position.y, 0.0, Texture::Flip::Horizontal);
	}

	else
	{
		activeAnimation->Render(position.x, position.y);
	}

	bound.Render();

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

void Player::OnCollision(BoxCollider& bound)
{
	//Player is in the air and hits the stone slab from the top, which 
	//means we reset the flags, animations and speeds and push the sprite
	//image up a little because it may appear 'sunken' into the stone
	
	auto collisionArea = this->bound.GetCollisionArea(bound);

	//it's a trigger point
	if (bound.GetTag() == "Trigger" && !isJumping)
	{
		isJumping = true;
		activeAnimation = &jumpAnimation;
		jumpVelocity = Vector<int>::Up * jumpSpeed;

		position.x += collisionArea.w;
	}

	//jumping on a trigger point does nothing
	else if (isJumping && bound.GetTag() != "Trigger")
	{
		//falling down
		if (position.y < bound.GetPosition().y)
		{
			isJumping = false;

			jumpVelocity = Vector<int>::Zero;

			jumpAnimation.ResetAnimation();
			activeAnimation = &idleAnimation;

			//Move the player upward so that they 
			//exit the collision intersection area
			position.y -= collisionArea.h;
		}

		//jumping up
		else if (position.y > bound.GetPosition().y)
		{
			jumpVelocity = Vector<int>::Up;
		}
	}

	//we're coming from the sides - check for side collisions
	else if(bound.GetTag() != "Trigger")
	{
		if (this->bound.GetPosition().x < bound.GetPosition().x)
		{
			position.x -= collisionArea.w;
		}

		else if (this->bound.GetPosition().x > bound.GetPosition().x)
		{
			position.x += collisionArea.w;
		}
	}
}