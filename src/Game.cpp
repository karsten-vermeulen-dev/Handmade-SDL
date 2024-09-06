#include "Game.h"
#include "Input.h"
#include "Music.h"
#include "Screen.h"
#include "Text.h"
#include "Utility.h"

//======================================================================================================
Game::Game(GameState* initialGameState)
{
	gameState.reset(initialGameState);
}
//======================================================================================================
bool Game::Initialize(const std::string& name, int screenWidth, int screenHeight, bool fullscreen)
{
	if (!Screen::Instance()->Initialize(name.c_str(), screenWidth, screenHeight, fullscreen))
	{
		return false;
	}

	Screen::Instance()->SetClearColor(100, 149, 237);

	if (!(Music::Initialize()))
	{
		//Not serious - game does not need to end
		//Add your own outcome/messages here...
	}

	if (!Text::Initialize())
	{
		//Not serious - game does not need to end
		//Add your own outcome/messages here...
	}

	Utility::SetWindowHandle(Screen::Instance()->GetWindowHandle());
	return true;
}
//======================================================================================================
bool Game::Run()
{
	gameState->OnEnter();

	while (gameState)
	{
		int startTime = SDL_GetTicks();

		Screen::Instance()->Clear();
		Input::Instance()->Update();

		GameState* nextState = gameState->Update(deltaTime);

		gameState->Render();

		Screen::Instance()->Present();

		if (nextState != gameState.get())
		{
			gameState->OnExit();
			gameState.reset(nextState);

			if (gameState)
			{
				gameState->OnEnter();
			}
		}

		deltaTime = SDL_GetTicks() - startTime;
	}

	return true;
}
//======================================================================================================
void Game::Shutdown()
{
	Text::Shutdown();
	Music::Shutdown();
	Screen::Instance()->Shutdown();
}