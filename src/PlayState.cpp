#include "EndState.h"
#include "Input.h"
#include "StartState.h"
#include "PlayState.h"

//======================================================================================================
bool PlayState::OnEnter()
{
	image.Load("Backgrounds/City_1920x1080.png", "Aircord.ogg");

	player.SetPosition(10, 670);

	coins.reserve(10);

	//If we use 'push_back' here, a copy is made and the old version is destroyed
	//and when that happens, the Collectible dtor is invoked, unloading the texture
	coins.emplace_back(Vector<int>( 200, 670 ), Collectible::Type::GoldCoin);
	coins.emplace_back(Vector<int>( 350, 470 ), Collectible::Type::SilverCoin);
	coins.emplace_back(Vector<int>( 475, 580 ), Collectible::Type::BronzeCoin);
	coins.emplace_back(Vector<int>( 600, 650 ), Collectible::Type::GoldCoin);
	coins.emplace_back(Vector<int>( 850, 550 ), Collectible::Type::BronzeCoin);
	coins.emplace_back(Vector<int>( 1000, 450 ), Collectible::Type::GoldCoin);
	coins.emplace_back(Vector<int>( 1250, 650 ), Collectible::Type::BronzeCoin);
	coins.emplace_back(Vector<int>( 1400, 580 ), Collectible::Type::BronzeCoin);
	coins.emplace_back(Vector<int>( 1600, 670 ), Collectible::Type::GoldCoin);
	coins.emplace_back(Vector<int>( 1775, 470 ), Collectible::Type::SilverCoin);

	message.Load("Impact.ttf", "Impact", Text::FontSize::Large);
	message.SetDimension(1100, 40);
	message.SetFont("Impact");
	message.SetString("Hello, Lila-Rose, welcome to the big city! Find as many coins as you can. And hurry!");
	message.SetColor(240, 240, 240);

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

	message.Render(100, 900);


	return true;
}
//======================================================================================================
void PlayState::OnExit()
{
	gameObjects.clear();
	coins.clear();
}