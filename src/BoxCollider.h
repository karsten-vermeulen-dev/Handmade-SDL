#pragma once
#include <string>
#include <SDL.h>
#include "Vector.h"

#define NOMINMAX

class BoxCollider
{

public:

	BoxCollider(int x = 0, int y = 0, 
				int width = 0, int height = 0, 
				const std::string& tag = "");

	BoxCollider(const Vector<int>& position, 
		        const Vector<int>& dimension, 
		        const std::string& tag);
	
	const std::string& GetTag() const;
	const Vector<int>& GetPosition() const;
	const Vector<int>& GetDimension() const;
	SDL_Rect GetCollisionArea(const BoxCollider& secondBox) const;

	void SetPosition(int x, int y);
	void SetPosition(const Vector<int>& position);

	void SetDimension(int width, int height);
	void SetDimension(const Vector<int>& dimension);

	void Update();
	bool IsColliding(const BoxCollider& secondBox) const;

	//For debugging only
	void Render();

private:

	std::string tag;

	Vector<int> min;
	Vector<int> max;
	Vector<int> position;
	Vector<int> dimension;

};