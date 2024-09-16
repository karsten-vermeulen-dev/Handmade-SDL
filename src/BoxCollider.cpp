#include <algorithm>
#include "BoxCollider.h"

//======================================================================================================
BoxCollider BoxCollider::GetCollisionRegion(const BoxCollider& secondBox)
{
	BoxCollider collider;

	collider.min.x = std::max(min.x, secondBox.min.x);
	collider.min.y = std::max(min.y, secondBox.min.y);
	collider.max.x = std::min(max.x, secondBox.max.x);
	collider.max.y = std::max(max.y, secondBox.max.y);

	return collider;
}
//======================================================================================================
void BoxCollider::SetPosition(int x, int y)
{
	position.x = x;
	position.y = y;
}
//======================================================================================================
void BoxCollider::SetDimension(int width, int height)
{
	dimension.x = width;
	dimension.y = height;
}
//======================================================================================================
void BoxCollider::Update()
{
	min.x = position.x;
	min.y = position.y;
	max.x = position.x + dimension.x;
	max.y = position.y + dimension.y;
}
//======================================================================================================
bool BoxCollider::IsColliding(const BoxCollider& secondBox) const
{
	return ((max.x > secondBox.min.x && secondBox.max.x > min.x) &&
		(max.y > secondBox.min.y && secondBox.max.y > min.y));
}