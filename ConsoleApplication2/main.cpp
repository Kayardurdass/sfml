#include <iostream>
#include "Game.h"


int main()
{
	//init game Engine
	Game game;

	while (game.GetWindowOpen())
	{
		//Update
		game.Update();

		//Render
		game.Render();
	}

}
