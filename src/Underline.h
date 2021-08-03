#pragma once
#ifndef UNDERLINE_H
#define UNDERLINE_H
#include "Collision.h"

class Underline
{
public:
	Underline();
	~Underline();

	void initialize(const sf::Color& color = sf::Color(255, 255, 255, 255), float thickness = 1.0f, float speed = 1.0f);
	void draw();
	void update(sf::Sprite* playSprite, sf::Sprite* exitSprite);

private:
	sf::RectangleShape underline;
	sf::Vector2f size;
	float speed;
};

#endif // !UNDERLINE_H

