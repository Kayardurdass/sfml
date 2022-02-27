#include "Game.h"

//private Variables
void Game::InitVariables()
{
	this->window = nullptr;

	//game Logic
	this->points = 0;
	this->enemySpawnTimer = this->enemySpawnTimerMax;
	this->enemySpawnTimerMax = 40.f;
	this->maxEnemies = 10;
	this->score = 0;
}

void Game::InitWindow()
{
	this->videoMode.height = 600;
	this->videoMode.width = 400;
	this->window = new sf::RenderWindow(this->videoMode, "ShittyGame", sf::Style::Titlebar | sf::Style::Close);

	this->window->setFramerateLimit(60);
}

void Game::InitEnemies()
{
	this->enemy.setPosition(sf::Vector2f(10.f, 10.f));
	this->enemy.setSize(sf::Vector2f(50.f, 50.f));
	this->enemy.setFillColor(sf::Color::Cyan);
}

void Game::InitPlayer()
{
	this->playerBody.setPosition(sf::Vector2f((this->window->getSize().x/2), (this->window->getSize().y) - 10));
	this->playerBody.setSize(sf::Vector2f(50.f, 50.f));
	this->playerBody.setFillColor(sf::Color::Green);
}

//Constructors / Destructors
Game::Game()
{
	this->InitVariables();
	this->InitWindow();
	this->InitEnemies();
	this->InitPlayer();
}

Game::~Game() 
{
	delete this->window;
}

const bool Game::GetWindowOpen() const
{
	return this->window->isOpen();
}

void Game::SpawnEnemy()
{
	this->enemy.setPosition(
		static_cast<float>(rand() % static_cast<int>(this->window->getSize().x - this->enemy.getSize().x)), 0.f);

	this->enemy.setFillColor(sf::Color::Green);

	this->enemies.push_back(this->enemy);
}

void Game::PollEvents()
{
	while(this->window->pollEvent(this->ev))
	{
		switch (this->ev.type)
		{
		case sf::Event::Closed:
			this->window->close();
		case sf::Event::KeyPressed:
			if (this->ev.key.code == sf::Keyboard::Escape)
				this->window->close();
			if (this->ev.key.code == sf::Keyboard::D)
				this->xPos += 10.f;
			if (this->ev.key.code == sf::Keyboard::Q)
				this->xPos -= 10.f;
		}
	}
}

// Functions
void Game::Update()
{
	this->PollEvents();

	this->UpdatePlayer();

	this->UpdateEnemies();
	
}

void Game::UpdateEnemies()
{ 
	//Update the timer
	if (this->enemies.size() < this->maxEnemies) {
		if (this->enemySpawnTimer >= this->enemySpawnTimerMax) {
			//spawns the enemy
			this->SpawnEnemy();
			this->enemySpawnTimer = 0.f;
		}
		else {
			this->enemySpawnTimer += 1.f;
		}
	}

	//Move the enemies
	for (int i = 0; i < this->enemies.size(); i++) {

		bool deleted = false;

		this->enemies[i].move(0.f, 3.f);

		if (this->enemies[i].getPosition().y > this->window->getSize().y) {
			this->score -= 1;
			deleted = true;
		}
		if (this->playerBody.getGlobalBounds().intersects(this->enemies[i].getGlobalBounds())) {
			this->score += 1;
			deleted = true;
		}

		if (deleted) {
			this->enemies.erase(this->enemies.begin() + i);
		}
	}
}

void Game::UpdatePlayer()
{
	playerBody.setPosition(xPos, this->playerBody.getPosition().y);
	std::cout << to_string(xPos) << "\n";
}

void Game::UpdateVariables()
{
	this->enemySpawnTimerMax -= score;
}

void Game::Render()
{
	//clear the window
	this->window->clear();

	this->RenderEnemies();

	this->RenderPlayer();

	this->renderUI();

	//Update and display the things
	this->window->display();
}

void Game::RenderEnemies()
{
	//rendering all the enemies

	for (auto &e : this->enemies) {
		this->window->draw(e);
	}
}

void Game::RenderPlayer()
{
	this->window->draw(this->playerBody);
}

void Game::renderUI()
{
	sf::Font font;
	font.loadFromFile("C:/Users/Admin/AppData/Local/Temp/Rar$DRa13708.15504/arial.ttf");
	// Create a text
	sf::Text scoreText(to_string(this->score), font);
	scoreText.setCharacterSize(30);
	scoreText.setStyle(sf::Text::Bold);
	scoreText.setFillColor(sf::Color::Red);

	this->window->draw(scoreText);
}
