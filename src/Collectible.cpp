#include "Collectible.h"

Collectible::Collectible()
{
	animation.Load("Objects/Coin_gold.png", "Coin");
	animation.SetTexture("Coin");
	animation.SetDimension(100, 100);
	animation.SetSourceDimension(6, 1, 3072, 512);
	animation.IsAnimated(true);
	animation.IsAnimationLooping(true);
	animation.SetAnimationVelocity(9.0f);

	bound.SetDimension(100, 100);
}

Collectible::~Collectible()
{	
	animation.Unload("Coin");
}

const BoxCollider& Collectible::GetBound()
{
	return bound;
}

void Collectible::Update(int deltaTime)
{


	animation.Update(deltaTime);

	bound.SetPosition(position.x, position.y);
	bound.Update();
}

bool Collectible::Render()
{
	animation.Render(position.x, position.y);

	return true;
}