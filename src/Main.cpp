#include "Game.h"
#include "StartState.h"

int main(int argc, char* args[])
{
	Game game(new StartState);

	if (game.Initialize("<insert game name here>", 1280, 720))
	{
		if (!game.Run())
		{
			game.Shutdown();
		}
	}

	return 0;
}