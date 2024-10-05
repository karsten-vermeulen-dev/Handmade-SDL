#pragma once
#include <string>
#include "Vector.h"

class SphereCollider
{

public:

	SphereCollider(int x = 0, int y = 0, 
		           int radius = 0, const std::string& tag = "");

	SphereCollider(const Vector<int>& position, 
		           int radius = 0, const std::string& tag = "");

	int GetRadius() const;
	const std::string& GetTag() const;
	const Vector<int>& GetPosition() const;

	void SetRadius(int radius);
	void SetPosition(int x, int y);
	void SetPosition(const Vector<int>& position);

	bool IsColliding(const SphereCollider& secondSphere) const;

private:

	int radius{ 0 };
	std::string tag;
	Vector<int> position;

};