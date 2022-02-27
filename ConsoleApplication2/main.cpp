#include <iostream>
#include "Game.h"


int main()
{
	//init srand
	std::srand(static_cast<unsigned>(time(NULL)));

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
