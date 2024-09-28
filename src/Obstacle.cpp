#include "Obstacle.h"

Obstacle::Obstacle(const Vector<int>& position, Type type)
{
	static int totalObstacles{ 0 };

	tag = "Obstacle_" + std::to_string(totalObstacles++);

	switch (type)
	{
	case Type::Crate:
		tag += "_crate";
		image.Load("Objects/Objects.png", tag);
		break;
	case Type::Stone:
		tag += "_stone";
		image.Load("Objects/Objects.png", tag);
		break;
	}

	image.SetTexture(tag);
	image.SetDimension(150, 106);
	image.SetSourceDimension(4, 3, 600, 318);
	image.SetCel(3, 2);
	image.IsAnimated(false);
	//image.IsAnimationLooping(false);
	//image.SetAnimationVelocity(0.0f);

	//TODO - Not sure why the bound is much smaller, need visualizers
	bound.SetDimension(85, 106);

	this->position = position;

}

Obstacle::~Obstacle()
{
	image.Unload(tag);
}

const BoxCollider& Obstacle::GetBound()
{
	return bound;
}

void Obstacle::Update(int deltaTime)
{
	bound.SetPosition(position.x, position.y);
	bound.Update();
}

bool Obstacle::Render()
{
	image.Render(position.x, position.y);

	return true;
}
