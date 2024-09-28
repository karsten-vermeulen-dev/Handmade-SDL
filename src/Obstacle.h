#pragma once

#include "BoxCollider.h"
#include "GameObject.h"
#include "Texture.h"

class Obstacle : public GameObject
{
public:

	enum class Type
	{
		Crate,
		Stone
	};

	Obstacle(const Vector<int>& position, Type type);
	~Obstacle() override;

	const BoxCollider& GetBound();

	void Update(int deltaTime) override;
	bool Render() override;

private:

	BoxCollider bound;

	Texture image;

};