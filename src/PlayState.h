#pragma once
#include <vector>
#include "Background.h"
#include "GameObject.h"
#include "GameState.h"
#include "Player.h"

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

	Player player{ 9 };

	std::vector<GameObject> gameObjects;

};