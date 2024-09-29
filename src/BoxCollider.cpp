#include <SDL.h>
#include "BoxCollider.h"
#include "Screen.h"

//======================================================================================================
void BoxCollider::SetPosition(int x, int y)
{
	position.x = x;
	position.y = y;
}
//======================================================================================================
void BoxCollider::SetPosition(const Vector<int>& position)
{
	this->position = position;
}
//======================================================================================================
void BoxCollider::SetDimension(int width, int height)
{
	dimension.x = width;
	dimension.y = height;
}
//======================================================================================================
void BoxCollider::SetDimension(const Vector<int>& dimension)
{
	this->dimension = dimension;
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
//======================================================================================================
void BoxCollider::Render()
{
	auto renderer = Screen::Instance()->GetRenderer();
	auto boundingBox = SDL_Rect{ position.x, position.y, dimension.x, dimension.y };

	//NOTE: This code will eventually reside somewhere more global (Utility or Screen class?)
	//Until the next big update, we render a primitive quad here to visualize the bounding box 
	SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 125);
	SDL_RenderFillRect(renderer, &boundingBox);
}