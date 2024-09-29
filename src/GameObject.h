#pragma once
#include <string>
#include "Vector.h"

class GameObject
{

public:

	GameObject() {}
	virtual ~GameObject() = 0 {}

	bool IsAlive() const;
	bool IsActive() const;
	bool IsVisible() const;

	void IsAlive(bool flag);
	void IsActive(bool flag);
	void IsVisible(bool flag);

	float GetAngle() const;
	int GetPriority() const;

	const std::string& GetTag() const;
	const Vector<int>& GetDimension() const;
	const Vector<int>& GetPosition() const;

	void SetPosition(int x, int y);
	void SetPosition(const Vector<int>& position);

	void SetDimension(int x, int y);
	void SetDimension(const Vector<int>& dimension);
	
	void SetTag(const std::string& tag);

	virtual void Update(int deltaTime) = 0;
	virtual bool Render() = 0;

protected:

	int priority{ 0 };
	float angle{ 0.0f };

	bool isDirty{ true };
	bool isAlive{ true };
	bool isActive{ true };
	bool isVisible{ true };

	std::string tag;
	Vector<int> position;
	Vector<int> dimension;

};