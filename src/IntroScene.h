#pragma once
#ifndef INTROSCENE_H
#define INTROSCENE_H
#include <iostream>
#include <SFML/Audio.hpp>
#include "Constants.h"
#include "States.h"

class IntroScene
{
public:
	IntroScene();
	~IntroScene();

	bool initialize(const std::string& fontFileName);
	void setAlphaColorSpeed(int speed);
	void draw();
	void update(GameState* gameState, sf::Music* globalMusic);

private:
	sf::Font font;
	sf::Text logoText;
	sf::Text presentText;

	sf::Color alphaColor;
	int alphaSpeed;
	bool change;
};

#endif // !INTROSCENE_H

