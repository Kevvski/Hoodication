#include "pch.h"
#include "IntroScene.h"


IntroScene::IntroScene() : alphaColor(255, 255, 255, 0), alphaSpeed(0), change(false)
{
}


IntroScene::~IntroScene()
{
}


bool IntroScene::initialize(const std::string& fontFileName) {
	if (!font.loadFromFile(fontFileName)) {
		std::cerr << "Load file in Intro Scene : " << fontFileName << " failed!\n";
		return false;
	}

	logoText.setFont(font);
	logoText.setCharacterSize(resizer(60, 40));
	logoText.setCharacterSize(60);
	logoText.setString("Kevo Games");
	logoText.setFillColor(alphaColor);
	logoText.setPosition(sf::Vector2f(
		GameWindow::getWindowSize().x / 2 - logoText.getGlobalBounds().width / 2,
		GameWindow::getWindowSize().y / 2 - logoText.getGlobalBounds().height
	));

	presentText.setFont(font);
/presentText.setCharacterSize(resizer(40, 20));
	presentText.setString("Present");
	presentText.setFillColor(alphaColor);
	presentText.setPosition(sf::Vector2f(
		GameWindow::getWindowSize().x / 2 - presentText.getGlobalBounds().width / 2,
		logoText.getPosition().y + logoText.getGlobalBounds().height + 15.0f
	));

	return true;
}


void IntroScene::setAlphaColorSpeed(int speed) {
	alphaSpeed = speed;
}


void IntroScene::draw() {
	GameWindow::draw(logoText);
	GameWindow::draw(presentText);
}


void IntroScene::update(GameState* gameState, sf::Music* globalMusic) {
	if (!change) {
		alphaColor.a += alphaSpeed;
		logoText.setFillColor(alphaColor);
		presentText.setFillColor(alphaColor);

		if (alphaColor.a >= 254)
			change = true;
	}
	else if (change) {
		alphaColor.a -= alphaSpeed;
		logoText.setFillColor(alphaColor);
		presentText.setFillColor(alphaColor);

		if (alphaColor.a <= 0) {
			globalMusic->play();
			*gameState = GameState::MENU;
		}
	}
}
