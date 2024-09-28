#pragma once

#include "GameObject.h"
#include "BoxCollider.h"
#include "Texture.h"

class Collectible : public GameObject
{

public:

	Collectible(const Vector<int>& position);
	~Collectible() override;

	const BoxCollider& GetBound();

	void Update(int deltaTime) override;
	bool Render() override;

private:

	BoxCollider bound;

	Texture animation;

};