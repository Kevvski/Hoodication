#pragma once
#ifndef BACKGROUND_H
#define BACKGROUND_H
#include <vector>
#include <iostream>
#include "GameWindow.h"

class Background
{
public:
	Background();
	~Background();

	//Initialize and settings
	void initialize(const sf::Color& firstColor, const sf::Color& secondColor);
	bool initialize(const std::string& fileName, float scale);
	void setChangeColorSpeed(int speed);

	//Edition
	void smoothChange(const sf::Color& firstTargetColor, const sf::Color& secondTargetColor);
	void outTransparent();

	void draw();

private:
	//Gradient background
	std::vector<sf::Vertex> vertices;
	int changeColorSpeed;
	sf::Color firstColorChange;
	sf::Color secondColorChange;

	//Image background
	sf::Texture bgTexture;
	sf::Sprite* bgSprite;

private:
	void setColors();
};

#endif // !BACKGROUND_H

