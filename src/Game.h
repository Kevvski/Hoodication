#pragma once
#ifndef GAME_H
#define GAME_H
#include <iostream>
#include "GameWindow.h"
#include "States.h"
#include "IntroScene.h"
#include "Background.h"
#include "TileLayer.h"
#include "MenuScene.h"
#include "Player.h"
#include "GameplayScene.h"

class Game
{
public:
	Game();
	~Game();

	void run();
	void draw();
	void update(sf::Event& event);

private:
	//Game statment
	GameState gameState;

	//Game objects and components
	sf::Texture textureSheet;
	Background background;
	Background mountains;
	TileLayer groundLayer;
	Player player;

	//Statments
	IntroScene introScene;
	MenuScene menuScene;
	GameplayScene gameplayScene;

	//Music
	sf::Music globalMusic;

	//Copyright
	sf::Font font;
	sf::Text copyrightText;
};

#endif // !GAME_H

