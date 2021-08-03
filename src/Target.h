#pragma once
#ifndef TARGET_H
#define TARGET_H
#include "GameWindow.h"
#include <string>

class Target
{
public:
	Target();
	~Target();

	void initialize(sf::Texture* texture, const sf::IntRect& textureRect, const sf::Font& font);
	void initializeText(int charSize = 10, const sf::Color& color = sf::Color(255, 255,255));
	void setNumber(int number);
	void setStringNumber();
	void setPosition(const sf::Vector2f& position);
	void setScale(float scale);
	void setTextSize(int size);
	void setTextColor(const sf::Color& color);
	void move(const sf::Vector2f& move);

	void draw();
	void update();

	const int getNumber() const;
	const sf::Vector2f& getPosition() const;
	sf::FloatRect getRect() const;

private:
	sf::Sprite targetSprite;
	sf::Text numberText;
	int number;
};

#endif // !TARGET_H

