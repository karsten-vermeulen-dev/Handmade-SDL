#include "Game.h"
#include "StartState.h"

//TODO - Add 'assert' where required
//TODO - Consider RAII for class design
//TODO - Load settings from a config file
//TODO - Make sure all code is const correct

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