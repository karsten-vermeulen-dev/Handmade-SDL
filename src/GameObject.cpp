#include "GameObject.h"

//======================================================================================================
bool GameObject::IsAlive() const
{
	return isAlive;
}
//======================================================================================================
bool GameObject::IsActive() const
{
	return isActive;
}
//======================================================================================================
bool GameObject::IsVisible() const
{
	return isVisible;
}
//======================================================================================================
void GameObject::IsAlive(bool flag)
{
	isAlive = flag;
}
//======================================================================================================
void GameObject::IsActive(bool flag)
{
	isActive = flag;
}
//======================================================================================================
void GameObject::IsVisible(bool flag)
{
	isVisible = flag;
}
//======================================================================================================
float GameObject::GetAngle() const
{
	return angle;
}
//======================================================================================================
int GameObject::GetPriority() const
{
	return priority;
}
//======================================================================================================
const std::string& GameObject::GetTag() const
{
	return tag;
}
//======================================================================================================
const Vector<int>& GameObject::GetDimension() const
{
	return dimension;
}
//======================================================================================================
const Vector<int>& GameObject::GetPosition() const
{
	return position;
}
//======================================================================================================
void GameObject::SetPosition(int x, int y)
{
	position.x = x;
	position.y = y;
}
//======================================================================================================
void GameObject::SetPosition(const Vector<int>& position)
{
	this->position = position;
}
//======================================================================================================
void GameObject::SetDimension(int x, int y)
{
	dimension.x = x;
	dimension.y = y;
}
//======================================================================================================
void GameObject::SetDimension(const Vector<int>& dimension)
{
	this->dimension = dimension;
}
//======================================================================================================
void GameObject::SetTag(const std::string& tag)
{
	this->tag = tag;
}