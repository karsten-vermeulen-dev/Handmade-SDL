#include "SphereCollider.h"

//======================================================================================================
SphereCollider::SphereCollider(int x, int y, int radius, const std::string& tag)
{
	this->tag = tag;
	SetPosition(x, y);
	SetRadius(radius);
}
//======================================================================================================
SphereCollider::SphereCollider(const Vector<int>& position, int radius, const std::string& tag)
{
	this->tag = tag;
	SetRadius(radius);
	SetPosition(position);
}
//======================================================================================================
int SphereCollider::GetRadius() const
{
	return radius;
}
//======================================================================================================
const std::string& SphereCollider::GetTag() const
{
	return tag;
}
//======================================================================================================
const Vector<int>& SphereCollider::GetPosition() const
{
	return position;
}
//======================================================================================================
void SphereCollider::SetRadius(int radius)
{
	this->radius = radius;
}
//======================================================================================================
void SphereCollider::SetPosition(int x, int y)
{
	position.x = x;
	position.y = y;
}
//======================================================================================================
void SphereCollider::SetPosition(const Vector<int>& position)
{
	this->position = position;
}
//======================================================================================================
bool SphereCollider::IsColliding(const SphereCollider& secondSphere) const
{
	Vector<int> centerPoint_1(position.x + radius, position.y + radius);
	Vector<int> centerPoint_2(secondSphere.position.x + secondSphere.radius,
		secondSphere.position.y + secondSphere.radius);

	return (centerPoint_1.Distance(centerPoint_2) <= (radius + secondSphere.radius));
}