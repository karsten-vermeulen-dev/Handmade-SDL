#include "Collectible.h"

//======================================================================================================
Collectible::Collectible(const Vector<int>& position)
{
	static int totalCoins{ 0 };

	tag = "Coin_" + std::to_string(totalCoins++);

	animation.Load("Objects/Coin_gold.png", tag);
	animation.SetTexture(tag);
	animation.SetDimension(100, 100);
	animation.SetSourceDimension(6, 1, 3072, 512);
	animation.IsAnimated(true);
	animation.IsAnimationLooping(true);
	animation.SetAnimationVelocity(9.0f);

	bound.SetDimension(100, 100);

	this->position = position;
}
//======================================================================================================
Collectible::~Collectible()
{	
	animation.Unload(tag);
}
//======================================================================================================
const BoxCollider& Collectible::GetBound()
{
	return bound;
}
//======================================================================================================
void Collectible::Update(int deltaTime)
{
	animation.Update(deltaTime);

	bound.SetPosition(position.x, position.y);
	bound.Update();
}
//======================================================================================================
bool Collectible::Render()
{
	animation.Render(position.x, position.y);

	return true;
}