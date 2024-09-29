#pragma once
#include "Vector.h"

class BoxCollider
{

public:

	void SetPosition(int x, int y);
	void SetPosition(const Vector<int>& position);

	void SetDimension(int width, int height);
	void SetDimension(const Vector<int>& dimension);

	void Update();
	bool IsColliding(const BoxCollider& secondBox) const;

	//Intended for debugging only
	void Render();

private:

	Vector<int> min;
	Vector<int> max;
	Vector<int> position;
	Vector<int> dimension;

};