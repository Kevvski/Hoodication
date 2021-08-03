#pragma once
#ifndef OBJECTANIMATION_H
#define OBJECTANIMATION_H
#include "Constants.h"


class ObjectAnimation
{
public:
	ObjectAnimation();
	~ObjectAnimation();

	void initialize(const sf::IntRect& textureRect, int startPosition = 0, int count = 1, int speed = 100);
	void turnOn();
	void turnOff();
	void animate(sf::Sprite* sprite);

	const bool isWorking() const;
	const bool isDone() const;

private:
	sf::IntRect textureRect;
	sf::Clock clock;
	bool workAnimation;
	bool done;
	int startPosition;
	int frameCount;
	int frameSpeed;

};

#endif // !OBJECTANIMATION_H

