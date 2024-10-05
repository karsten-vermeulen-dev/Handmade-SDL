#pragma once
#include <vector>
#include "Background.h"
#include "BoxCollider.h"
#include "Collectible.h"
#include "GameObject.h"
#include "GameState.h"
#include "Obstacle.h"
#include "Player.h"
#include "Text.h"

class PlayState : public GameState
{

public:

	PlayState() {}
	virtual ~PlayState() {}

	virtual bool OnEnter();
	virtual GameState* Update(int deltaTime);
	virtual bool Render();
	virtual void OnExit();

private:

	Background image;

	Player player{ 9, 25 };

	Text message;

	std::vector<BoxCollider> bounds;

	std::vector<Collectible> coins;

	std::vector<Obstacle> obstacles;

	std::vector<GameObject> gameObjects;

};