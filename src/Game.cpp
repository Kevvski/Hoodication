#include "pch.h"
#include "Game.h"


Game::Game() : gameState(GameState::INTRO)
{
}


Game::~Game()
{
}


void Game::run() {
	const int FPS = 60;
	const int ALIAS_LEVEL = 8;
	GameWindow::initialize("Hoodication", ALIAS_LEVEL, FPS);
	sf::Event event;


	if (!introScene.initialize("res/fonts/swis.ttf"))
		std::cerr << "Initialize Intro Scene failed!\n";
	introScene.setAlphaColorSpeed(2);


	if (!textureSheet.loadFromFile("res/assets/sprite-sheet.png"))
		std::cerr << "Load sprite sheet failed\n";


	if (!mountains.initialize("res/assets/mountains-bg.png", 1.5f))
		std::cerr << "Load mountains background failed\n";


	background.initialize(sf::Color(0, 15, 40), sf::Color(0, 60, 100));
	background.setChangeColorSpeed(1);


	groundLayer.initialize(&textureSheet, 
		sf::IntRect(0, 0, TILE_SIZE, TILE_SIZE), 
		sf::Vector2f(0.0f, GameWindow::getWindowSize().y - TILE_SIZE * 4.0f),
		4.0f,
		15);


	if(!menuScene.initialize(&textureSheet))
		std::cerr << "Initialize Menu Scene failed!\n";


	player.initialize(&textureSheet, sf::IntRect(TILE_SIZE * 2, 0, TILE_SIZE, TILE_SIZE));
	player.setScale(5.0f);
	player.setPosition(sf::Vector2f(GameWindow::getWindowSize().x / 2 - player.getRect().width * 1.5f, groundLayer.getPosition().y - player.getRect().height));
	player.setChances(3);


	if (!gameplayScene.initialize(&player, &textureSheet))
		std::cerr << "Initialize gameplay scene failed\n";


	if (!globalMusic.openFromFile("res/sounds/globalMusic.wav"))
		std::cerr << "Open globalMusic.wav failed\n";
	globalMusic.setLoop(true);
	globalMusic.setVolume(30);


	//Copryright text initialization
	//-------------------------------------------------------------------------------------------------------
	if (!font.loadFromFile("res/fonts/pixelFont.ttf"))
		std::cerr << "Load pixel font failed!\n";

	copyrightText.setFont(font);
	copyrightText.setString("Copyright (c) - Kewin Wozny 2019");
	copyrightText.setCharacterSize(20);
	copyrightText.setPosition(sf::Vector2f(
		GameWindow::getWindowSize().x / 2 - copyrightText.getGlobalBounds().width / 2,
		GameWindow::getWindowSize().y - copyrightText.getGlobalBounds().height - 10.0f));

	while (GameWindow::isOpen()) {
		draw();
		update(event);
	}
}


void Game::draw() {
	switch (gameState) 
	{
	case GameState::INTRO: 
		introScene.draw();
		break;

	case GameState::MENU:
		background.draw();
		mountains.draw();
		menuScene.draw();
		groundLayer.draw();
		player.draw();
		GameWindow::draw(copyrightText);
		break;

	case GameState::GAMEPLAY:
		background.draw();
		mountains.draw();
		groundLayer.draw();
		player.draw();
		gameplayScene.draw(&player);
		break;
	}
}


void Game::update(sf::Event& event) {
	while (GameWindow::pollEvent(event)) {
		if (event.type == sf::Event::Closed) GameWindow::close();
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) GameWindow::close();

	GameWindow::display();

	switch (gameState)
	{
	case GameState::INTRO: 
		introScene.update(&gameState, &globalMusic); 
		break;

	case GameState::MENU:
		menuScene.update(&gameState, &player, &background, &mountains);
		player.update();
		break;

	case GameState::GAMEPLAY:
		player.update();
		gameplayScene.update(&player, &groundLayer);
		break;

	case GameState::EXIT:
		GameWindow::close();
		break;
	}

	GameWindow::clear();
}
