#pragma once
#ifndef GUI_H
#define GUI_H
#include "Player.h"
#include <iostream>
#include <vector>

class GUI
{
public:
	GUI();
	~GUI();

	bool initialize(const std::string& fontName, Player* player, sf::Texture* texture);
	void draw(Player* player);
	void update(Player* player);

private:
	sf::Font font;
	sf::Text textScore;
	sf::Text score;

	std::vector<sf::Sprite> chancesSprite;

	sf::RectangleShape pauseRect;
	sf::Text gameOverText;
	sf::Text pressText;
};

#endif // !GUI_H

