#pragma once
#ifndef PARTICLE_H
#define PARTICLE_H
#include "GameWindow.h"

class Particle
{
public:
	Particle();
	Particle(const sf::Vector2f& size, const sf::Vector2f& position, int pulseSpeed = 1);
	~Particle();

	void create(const sf::Vector2f& size, const sf::Vector2f& position, int pulseSpeed = 1);
	void draw();
	void pulse();

private:
	sf::RectangleShape rect;
	sf::Color color;
	float pulseSpeed;
	bool changeColorAlpha;
};

#endif // !PARTICLE_H

