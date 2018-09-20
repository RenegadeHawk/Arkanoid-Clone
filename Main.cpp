#include <SFML/Graphics.hpp>
#include "Game.h"
constexpr int width = 1366, height = 768;

//float getFPS(const sf::Time& time) {
//	return (1000000.0f / time.asMicroseconds());
//}

int main()
{
	sf::RenderWindow window(sf::VideoMode(width, height), "Break Brix");
	window.setFramerateLimit(60);
	Game game = Game(window);

	sf::Clock FPSClock;

	while (window.isOpen())
	{

		window.clear(sf::Color(57, 62, 65, 255));
		sf::Event event;

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			game.HandleEvents(event);

		}
		game.Update();
		window.display();
	/*	float fps = getFPS(FPSClock.restart());
		std::cout << "FPS : " << fps << std::endl;*/
	}
	
	return 0;
}
