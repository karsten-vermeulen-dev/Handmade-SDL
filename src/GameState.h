#pragma once

class GameState
{

public:

	GameState() {}
	virtual ~GameState() = 0 {}

	virtual bool OnEnter() = 0;
	virtual GameState* Update(int deltaTime) = 0;
	virtual bool Render() = 0;
	virtual void OnExit() = 0;

};