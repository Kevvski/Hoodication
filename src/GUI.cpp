#include "pch.h"
#include "GUI.h"


GUI::GUI()
{
}


GUI::~GUI()
{
}


bool GUI::initialize(const std::string& fontName, Player* player, sf::Texture* texture) {
	if (!font.loadFromFile(fontName)) {
		std::cerr << "Load font in GUI: " << fontName << " failed!\n";
		return false;
	}

	sf::Sprite localSprite;
	localSprite.setTexture(*texture);
	localSprite.setTextureRect(sf::IntRect(TILE_SIZE * 3, 0, TILE_SIZE, TILE_SIZE));
	localSprite.setScale(sf::Vector2f(3.0f, 3.0f));
	localSprite.setRotation(-45.0f);
	localSprite.setPosition(sf::Vector2f(0.0f, 70.0f));

	textScore.setFont(font);
	textScore.setString("Score:");
	textScore.setFillColor(sf::Color::Green);
	textScore.setCharacterSize(40);
	textScore.setPosition(
		sf::Vector2f(
			localSprite.getPosition().x + 10.0f, 
			localSprite.getPosition().y + localSprite.getGlobalBounds().height - 60.0f));

	score.setFont(font);
	score.setString(std::to_string(player->getScore()));
	score.setFillColor(textScore.getFillColor());
	score.setCharacterSize(textScore.getCharacterSize());
	score.setPosition(
		sf::Vector2f(
			textScore.getPosition().x + textScore.getGlobalBounds().width + 20.0f, 
			textScore.getPosition().y));

	for (int i = 0; i < player->getChances(); i++) {
		if (i != 0) localSprite.setPosition(
			sf::Vector2f(
				chancesSprite.at(i - 1).getPosition().x + chancesSprite.at(i - 1).getGlobalBounds().width - 10.0f, 
				chancesSprite.at(i - 1).getPosition().y));
		chancesSprite.push_back(localSprite);
	}

	pauseRect.setSize(sf::Vector2f(GameWindow::getWindowSize().x, GameWindow::getWindowSize().y));
	pauseRect.setFillColor(sf::Color(0, 0, 0, 100));

	gameOverText.setFont(font);
	gameOverText.setString("Game Over");
	gameOverText.setCharacterSize(50);
	gameOverText.setPosition(sf::Vector2f(
		GameWindow::getWindowSize().x / 2 - gameOverText.getGlobalBounds().width / 2,
		GameWindow::getWindowSize().y / 2 - gameOverText.getGlobalBounds().height / 2
		));

	pressText.setFont(font);
	pressText.setString("Press \"SPACE\" to try again");
	pressText.setCharacterSize(30);
	pressText.setPosition(sf::Vector2f(
		GameWindow::getWindowSize().x / 2 - pressText.getGlobalBounds().width / 2,
		gameOverText.getPosition().y + gameOverText.getGlobalBounds().height + 20.0f
	));

	return true;
}


void GUI::draw(Player* player) {
	for (int i = 0; i < player->getChances(); i++)
		GameWindow::draw(chancesSprite.at(i));

	GameWindow::draw(textScore);
	GameWindow::draw(score);

	if (player->getChances() == 0) {
		GameWindow::draw(pauseRect);
		GameWindow::draw(gameOverText);
		GameWindow::draw(pressText);
	}
}


void GUI::update(Player* player) {
	score.setString(std::to_string(player->getScore()));
}


