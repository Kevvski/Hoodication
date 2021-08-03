#pragma once
#ifndef PLAYER_H
#define PLAYER_H
#include "ObjectAnimation.h"
#include "Constants.h"
#include <iostream>

class Player
{
public:
	Player();
	~Player();

	//Initialize and settings
	void initialize(sf::Texture* texture, const sf::IntRect& firstFrame);
	void setScale(float scale);
	void setPosition(const sf::Vector2f& position);
	void setChances(int chances);
	void setScore(int value);
	void deincrementChances();
	void addScore(int score);
	void move(const sf::Vector2f& moving);

	//Animation
	void startAnimation();
	void stopAnimation();

	void draw();
	void update();

	//Callbacks
	sf::FloatRect getRect() const;
	const sf::Vector2f& getPosition() const;
	const bool isAnimating() const;
	const int getChances() const;
	const int getScore() const;

private:
	sf::Sprite playerSprite;
	ObjectAnimation playerAnimation;

	int chances;
	int score;
};


#endif // !PLAYER_H
