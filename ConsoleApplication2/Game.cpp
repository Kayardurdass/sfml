#include "Game.h"

//private Variables
void Game::InitVariables()
{
	this->window = nullptr;
}

void Game::InitWindow()
{
	this->videoMode.height = 600;
	this->videoMode.width = 800;
	this->window = new sf::RenderWindow(this->videoMode, "My first sfml window", sf::Style::Titlebar | sf::Style::Close);
}

//Constructors / Destructors
Game::Game()
{
	this->InitVariables();
	this->InitWindow();
}

Game::~Game() 
{
	delete this->window;
}

const bool Game::GetWindowOpen() const
{
	return this->window->isOpen();
}

//Accessors


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
		}
	}
}

// Functions
void Game::Update()
{
	this->PollEvents();
}

void Game::Render()
{
	this->window->clear(sf::Color::Red);

	this->window->display();
}