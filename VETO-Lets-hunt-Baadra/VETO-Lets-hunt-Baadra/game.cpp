#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <iostream>
#include <cmath>
#include <vector>
#include <stdlib.h>
#include <string>

#include "object.h"

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
	sf::Texture txt_enemy;
	txt_enemy.loadFromFile("textures/enemy.png");

	sf::Sprite backgroundTop;
	backgroundTop.setTexture(txt_bckgTop);
	backgroundTop.setPosition(0, 0);
	sf::Sprite backgroundBottom;
	backgroundBottom.setTexture(txt_bckgBottom);
	backgroundBottom.setPosition(0, 0);
	sf::Sprite enemy;
	enemy.setTexture(txt_enemy);
	enemy.setScale(1, 1);

	//Vector
	std::vector <mapSlot> vSlot;
	std::vector <computerEnemy> vEnemy;

	//Create map positions
	vSlot.push_back(mapSlot(647,470,1.4));
	vSlot.push_back(mapSlot(961, 510, 1));
	vSlot.push_back(mapSlot(1053, 572, 1.2));
	vSlot.push_back(mapSlot(1205, 567, 1.8));
	vSlot.push_back(mapSlot(1338, 566, 1.6));
	vSlot.push_back(mapSlot(1750, 357, 3.5));
	
	for (int i = 0; i < vSlot.size(); i++) {
		vEnemy.push_back(computerEnemy(vSlot[i].x, vSlot[i].y, vSlot[i].modifier));
	}

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
		for (int i = 0; i < vEnemy.size(); i++) {
			enemy.setPosition(vEnemy[i].x,vEnemy[i].y);
			gameWindow.draw(enemy);
		}
		gameWindow.draw(backgroundBottom);
		gameWindow.display();
	}

	return 0;
}