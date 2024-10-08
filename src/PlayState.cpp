#include "EndState.h"
#include "Input.h"
#include "StartState.h"
#include "PlayState.h"

//======================================================================================================
bool PlayState::OnEnter()
{
	image.Load("Backgrounds/City_1920x1080.png", "Aircord.ogg");

	player.SetPosition(10, 674);

	coins.reserve(10);
	obstacles.reserve(25);
	bounds.reserve(10);

	//--------------------------------------------------------
	//Coins
	//--------------------------------------------------------

	//If we use 'push_back' here, a copy is made and the old version is destroyed
	//and when that happens, the Collectible dtor is invoked, unloading the texture
	coins.emplace_back(Vector<int>(200, 370), Collectible::Type::GoldCoin);
	coins.emplace_back(Vector<int>(350, 370), Collectible::Type::SilverCoin);
	coins.emplace_back(Vector<int>(475, 380), Collectible::Type::BronzeCoin);
	coins.emplace_back(Vector<int>(600, 350), Collectible::Type::GoldCoin);
	coins.emplace_back(Vector<int>(850, 350), Collectible::Type::BronzeCoin);
	coins.emplace_back(Vector<int>(1000, 350), Collectible::Type::GoldCoin);
	coins.emplace_back(Vector<int>(1250, 325), Collectible::Type::BronzeCoin);
	coins.emplace_back(Vector<int>(1400, 345), Collectible::Type::BronzeCoin);
	coins.emplace_back(Vector<int>(1600, 345), Collectible::Type::GoldCoin);
	coins.emplace_back(Vector<int>(1775, 345), Collectible::Type::SilverCoin);
	
	//--------------------------------------------------------
	//Obstacles
	//--------------------------------------------------------

	//First four stone slabs on the floor
	obstacles.emplace_back(Vector<int>(350, 745), Obstacle::Type::Stone);
	obstacles.emplace_back(Vector<int>(450, 745), Obstacle::Type::Stone);
	obstacles.emplace_back(Vector<int>(550, 745), Obstacle::Type::Stone);
	obstacles.emplace_back(Vector<int>(650, 745), Obstacle::Type::Stone);
	
	//Two extra stones one layer up
	obstacles.emplace_back(Vector<int>(550, 647), Obstacle::Type::Stone);
	obstacles.emplace_back(Vector<int>(650, 647), Obstacle::Type::Stone);
	
	//Six stone slabs in the middle of the scene
	obstacles.emplace_back(Vector<int>(650, 549), Obstacle::Type::Stone);
	obstacles.emplace_back(Vector<int>(750, 549), Obstacle::Type::Stone);
	obstacles.emplace_back(Vector<int>(850, 549), Obstacle::Type::Stone);
	obstacles.emplace_back(Vector<int>(950, 549), Obstacle::Type::Stone);
	obstacles.emplace_back(Vector<int>(1050, 549), Obstacle::Type::Stone);
	obstacles.emplace_back(Vector<int>(1150, 549), Obstacle::Type::Stone);
	
	//Three extra stone slabs on the right
	obstacles.emplace_back(Vector<int>(1400, 350), Obstacle::Type::Stone);
	obstacles.emplace_back(Vector<int>(1500, 350), Obstacle::Type::Stone);
	obstacles.emplace_back(Vector<int>(1600, 350), Obstacle::Type::Stone);
	
	//Top right two stones (for treasure?)
	obstacles.emplace_back(Vector<int>(1675, 150), Obstacle::Type::Stone);
	obstacles.emplace_back(Vector<int>(1775, 150), Obstacle::Type::Stone);

	//--------------------------------------------------------
	//Colliders
	//--------------------------------------------------------

	//Floor and sides 
	bounds.emplace_back(0, 849, 1920, 100, "Bound");
	bounds.emplace_back(0, 0, 10, 849, "Bound");
	bounds.emplace_back(1910, 0, 10, 849, "Bound");
	
	//Bottom three stones on floor
	bounds.emplace_back(375, 749, 200, 100, "Bound");  //+25, +4, 100x100 pixels per stone slab
	
	//Block of four stones above that
	bounds.emplace_back(575, 651, 200, 198, "Bound");

	//Block of six stone slabs in middle
	bounds.emplace_back(675, 553, 600, 100, "Bound");
	
	//Block of three stones on right
	bounds.emplace_back(1425, 354, 300, 100, "Bound");

	//Block of two on top-right
	bounds.emplace_back(1700, 154, 200, 100, "Bound");

	//--------------------------------------------------------
	//Triggers
	//--------------------------------------------------------

	bounds.emplace_back(210, 625, 50, 50, "Trigger");  //-165, -124, 50x50

	bounds.emplace_back(410, 527, 50, 50, "Trigger");
	
	bounds.emplace_back(510, 429, 50, 50, "Trigger");
	
	bounds.emplace_back(1390, 429, 50, 50, "Trigger");
	
	bounds.emplace_back(1260, 230, 50, 50, "Trigger");
	
	bounds.emplace_back(1535, 30, 50, 50, "Trigger");
	


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

	for (auto& bound : bounds)
	{
		bound.Update();

		if (player.GetBound().IsColliding(bound))
		{
			player.OnCollision(bound);
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

	for (auto& obstacle : obstacles)
	{
		if (obstacle.IsVisible())
		{
			obstacle.Render();
		}
	}

	for (auto& bound : bounds)
	{
		bound.Render();
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