#include "EndState.h"
#include "Input.h"
#include "StartState.h"
#include "PlayState.h"

//======================================================================================================
bool PlayState::OnEnter()
{
	image.Load("Backgrounds/City_1920x1080.png", "Aircord.ogg");

	player.SetPosition(100, 670);

	coins.reserve(15);

	//If we use 'push_back' here, a copy is made and the old version is destroyed
	//and when that happens, the Collectible dtor is invoked, unloading the texture
	coins.emplace_back(Vector<int>{ 100, 670 });
	coins.emplace_back(Vector<int>{ 350, 470 });
	coins.emplace_back(Vector<int>{ 475, 580 });
	coins.emplace_back(Vector<int>{ 600, 650 });
	coins.emplace_back(Vector<int>{ 850, 550 });

	return true;
}
//======================================================================================================
GameState* PlayState::Update(int deltaTime)
{
	image.PlayMusic();

	if (Input::Instance()->IsKeyPressed(HM_KEY_M))
	{
		image.StopMusic();
		return new StartState;
	}

	if (Input::Instance()->IsKeyPressed(HM_KEY_Q))
	{
		image.StopMusic();
		return new EndState;
	}

	for (auto& gameObject : gameObjects)
	{
		if (gameObject.IsActive())
		{
			gameObject.Update(deltaTime);
		}
	}

	player.Update(deltaTime);

	for (auto& coin : coins)
	{
		coin.Update(deltaTime);

		if (player.GetBound().IsColliding(coin.GetBound()))
		{
			coin.IsVisible(false);
		}
	}

	return this;
}
//======================================================================================================
bool PlayState::Render()
{
	image.Render();

	for (auto& gameObject : gameObjects)
	{
		if (gameObject.IsActive() && gameObject.IsVisible())
		{
			gameObject.Render();
		}
	}

	player.Render();

	for (auto& coin : coins)
	{
		if (coin.IsVisible())
		{
			coin.Render();
		}
	}

	return true;
}
//======================================================================================================
void PlayState::OnExit()
{
	gameObjects.clear();
	coins.clear();
}