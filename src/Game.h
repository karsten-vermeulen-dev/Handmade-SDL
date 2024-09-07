#pragma once
#include <deque>
#include <memory>
#include <string>
#include "GameState.h"

//This class implements the Game State Pattern as per this tutorial:
//https://gameprogrammingpatterns.com/state.html

class Game
{

public:

	Game(GameState* initialGameState);

	bool Initialize(const std::string& name,
		int screenWidth,
		int screenHeight,
		bool fullscreen = false);

	bool Run();
	void Shutdown();

private:

	int deltaTime{ 0 };
	std::unique_ptr<GameState> gameState;

};