#include <algorithm>
#include "BoxCollider.h"

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