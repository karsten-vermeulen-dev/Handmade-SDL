#pragma once
#include "Vector.h"

class BoxCollider
{

public:

	void SetPosition(int x, int y);
	void SetDimension(int width, int height);

	void Update();
	bool IsColliding(const BoxCollider& secondBox) const;

private:

	Vector<int> min;
	Vector<int> max;
	Vector<int> position;
	Vector<int> dimension{ 1, 1 };

};