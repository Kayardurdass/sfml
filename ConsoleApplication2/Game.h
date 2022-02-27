#pragma once
using namespace std;

#include <iostream>
#include <vector>
#include <ctime>
#include <string>

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

	//Player
	float xPos;
	sf::RectangleShape playerBody;

	//game Logic
	int points;
	float enemySpawnTimer;
	float enemySpawnTimerMax;
	int maxEnemies;
	int score;

	//GameObjects
	std::vector < sf::RectangleShape> enemies;
	sf::RectangleShape enemy;

	//private Variables
	void InitVariables();
	void InitWindow();
	void InitEnemies();
	void InitPlayer();
public:
	//Constructors / Destructors
	Game();
	virtual ~Game();

	//Accessors
	const bool GetWindowOpen() const;

	// Functions
	void SpawnEnemy();
	void PollEvents();
	void Update();
	void UpdateEnemies();
	void UpdatePlayer();
	void UpdateVariables();
	void Render();
	void RenderEnemies();
	void RenderPlayer();
	void renderUI();
};

