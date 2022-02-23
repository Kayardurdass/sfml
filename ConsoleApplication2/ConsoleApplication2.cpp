#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/system.hpp>
#include <SFML/Network.hpp>


int main()
{
	sf::RenderWindow window(sf::VideoMode(640, 480), "My first sfml window", sf::Style::Titlebar | sf::Style::Close);
	sf::Event ev;

	while (window.isOpen())
	{
		//Event Polling
		while (window.pollEvent(ev)) 
		{

			switch (ev.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::KeyPressed:
				if (ev.key.code == sf::Keyboard::Escape)
					window.close();
				break;
			}
		}

		//Update

		//Render
		window.clear(sf::Color::Blue);  //clear old frame


		window.display();  //draw the new frame
	}

}
