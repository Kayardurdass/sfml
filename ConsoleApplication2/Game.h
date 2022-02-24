#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/system.hpp>
#include <SFML/Network.hpp>

class Game
{
private:
	//variables
	//window
	sf::RenderWindow* window;
	sf::VideoMode videoMode;
	sf::Event ev;

	//GameObjects
	sf::RectangleShape enemy;

	//private Variables
	void InitVariables();
	void InitWindow();
	void InitEnemies();
public:
	//Constructors / Destructors
	Game();
	virtual ~Game();

	//Accessors
	const bool GetWindowOpen() const;

	// Functions
	void PollEvents();
	void Update();
	void Render();
};

