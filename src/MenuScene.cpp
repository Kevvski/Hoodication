#include "pch.h"
#include "MenuScene.h"


MenuScene::MenuScene()
{
}


MenuScene::~MenuScene()
{
}


bool MenuScene::initialize(sf::Texture* objectsTexture) {
	//Menu sprites initialization
	//-------------------------------------------------------------------------------------------------------
	auto loadImage = [&](const std::string& fileName, sf::Texture& texture) {
		sf::Sprite sprite;

		if (!texture.loadFromFile(fileName))
			std::cerr << "Load file: " << fileName << " failed\n";

		sprite.setTexture(texture);
		return sprite;
	};

	logoSprite = loadImage("res/assets/Logo.png", textureLogo);
	playSprite = loadImage("res/assets/Play.png", playTexture);
	exitSprite = loadImage("res/assets/Exit.png", exitTexture);

	const sf::Vector2f logoResizer(resizer(0.65f, 0.45f), resizer(0.65f, 0.45f));
	const sf::Vector2f buttonsResizer(resizer(0.45f, 0.35f), resizer(0.45f, 0.35f));

	logoSprite.scale(logoResizer);
	logoSprite.setPosition(sf::Vector2f(
		20.0f,
		20.0f));

	playSprite.scale(buttonsResizer);
	playSprite.setPosition(sf::Vector2f(
		20.0f,
		logoSprite.getPosition().y + logoSprite.getGlobalBounds().height + 100.0f));

	exitSprite.scale(buttonsResizer);
	exitSprite.setPosition(sf::Vector2f(
		playSprite.getPosition().x,
		playSprite.getPosition().y + playSprite.getGlobalBounds().height + 20.0f));

	underline.initialize(sf::Color::Green, 5.0f, 10.0f);


	//Campfire initialization
	//-------------------------------------------------------------------------------------------------------
	campfire.setTexture(*objectsTexture);
	campfire.setTextureRect(sf::IntRect(TILE_SIZE, 0, TILE_SIZE, TILE_SIZE));;
	campfire.setScale(sf::Vector2f(resizer(4.0f, 3.0f), resizer(4.0f, 3.0f)));
	campfire.setPosition(sf::Vector2f(GameWindow::getWindowSize().x / 2 - campfire.getGlobalBounds().width / 2, GameWindow::getWindowSize().y - TILE_SIZE * resizer(8.0f, 5.0f)));
	campfireAnimation.initialize(campfire.getTextureRect(), 0, 5, 100);
	campfireAnimation.turnOn();


	//Particle system(stars) initialization
	//-------------------------------------------------------------------------------------------------------
	particleSystem.initialize(100);


	//Sounds initialization
	//-------------------------------------------------------------------------------------------------------
	if (!clickBuffer.loadFromFile("res/sounds/click.wav"))
		return false;
	clickSound.setBuffer(clickBuffer);
	clickSound.setVolume(50);

	if (!campfireMusic.openFromFile("res/sounds/campfire.ogg"))
		return false;
	campfireMusic.setLoop(true);
	campfireMusic.setVolume(60);
	campfireMusic.play();

	if (!walkBuffer.loadFromFile("res/sounds/walking.wav"))
		return false;
	walkSound.setBuffer(walkBuffer);
	walkSound.setVolume(50);

	return true;
}


void MenuScene::draw() {
	particleSystem.draw();
	GameWindow::draw(logoSprite);
	GameWindow::draw(playSprite);
	GameWindow::draw(exitSprite);
	underline.draw();
	GameWindow::draw(campfire);
}


void MenuScene::update(GameState* gameState, Player* player, Background* bg, Background* mountains) {
	campfireAnimation.animate(&campfire);
	underline.update(&playSprite, &exitSprite);
	particleSystem.update();

	if (Collision::mouseCollision(&exitSprite) && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		clickSound.play();
		*gameState = GameState::EXIT;
	}
	else if (Collision::mouseCollision(&playSprite) && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		clickSound.play();
		walkSound.play();
		player->startAnimation();
	}

	if (player->isAnimating()) {
		const sf::Vector2f moving(-10.0f, 0.0f);
		logoSprite.move(moving);
		playSprite.move(moving);
		exitSprite.move(moving);
		campfire.move(moving);
		bg->smoothChange(sf::Color::Cyan, sf::Color(0, 181, 255));
		mountains->outTransparent();

		if (campfire.getPosition().x + campfire.getGlobalBounds().width < 0.0f && player->getPosition().x > 50.0f) {
			player->move(moving);
		}
		if (player->getPosition().x <= 50.0f) {
			player->stopAnimation();
			campfireMusic.stop();
			walkSound.stop();
			*gameState = GameState::GAMEPLAY;
		}
	}
}
