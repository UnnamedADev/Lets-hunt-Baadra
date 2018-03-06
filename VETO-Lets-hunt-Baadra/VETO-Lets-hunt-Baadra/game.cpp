#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <cmath>
#include <vector>

int main() {
	
	//Window and settings
	int gWidth = 1920;
	int gHeight = 970;
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	sf::RenderWindow gameWindow(sf::VideoMode(gWidth,gHeight), "VETO Lets hunt Baadra", sf::Style::Default, settings);
	gameWindow.setFramerateLimit(60);

	//Textures and sprites
	sf::Texture txt_bckgTop;
	txt_bckgTop.loadFromFile("textures/background_top.png");
	sf::Texture txt_bckgBottom;
	txt_bckgBottom.loadFromFile("textures/background_bottom.png");

	sf::Sprite backgroundTop;
	backgroundTop.setTexture(txt_bckgTop);
	backgroundTop.setPosition(0, 0);
	sf::Sprite backgroundBottom;
	backgroundBottom.setTexture(txt_bckgBottom);
	backgroundBottom.setPosition(0, 0);

	//Game loop
	while (gameWindow.isOpen()) {
		gameWindow.clear(sf::Color(255,255,255));

		//Events
		sf::Event gameEvent;
		while (gameWindow.pollEvent(gameEvent)) {
			if (gameEvent.type == sf::Event::Closed) {
				gameWindow.close();
			}
			if (gameEvent.type == sf::Event::KeyPressed) {
				switch (gameEvent.key.code) {
					case 71:
						break;
				}
			}
		}

		//Draw
		gameWindow.draw(backgroundTop);
		gameWindow.draw(backgroundBottom);
		gameWindow.draw(myRect);

		gameWindow.display();
	}

	return 0;
}