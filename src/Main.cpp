#include "Game.h"
#include "StartState.h"

int main(int argc, char* args[])
{
	Game game(new StartState);

	if (game.Initialize("City Slicker", 1920, 1080))
	{
		if (!game.Run())
		{
			game.Shutdown();
		}
	}

	return 0;
}