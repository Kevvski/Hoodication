#include "pch.h"
#include "Particle.h"


Particle::Particle() : color(255, 255, 255, 10), pulseSpeed(0), changeColorAlpha(false)
{
}


Particle::Particle(const sf::Vector2f& size, const sf::Vector2f& position, int pulseSpeed) : color(255, 255, 255, 10), changeColorAlpha(false)
{
	rect.setSize(size);
	rect.setPosition(position);
	rect.setFillColor(color);
	this->pulseSpeed = pulseSpeed;
}


Particle::~Particle()
{
}


void Particle::create(const sf::Vector2f& size, const sf::Vector2f& position, int pulseSpeed) {
	rect.setSize(size);
	rect.setPosition(position);
	rect.setFillColor(color);
	this->pulseSpeed = pulseSpeed;
}


void Particle::draw() {
	GameWindow::draw(rect);
}


void Particle::pulse() {
	if (!changeColorAlpha) {
		color.a += pulseSpeed;
		rect.setFillColor(color);
		if (color.a >= 254) changeColorAlpha = true;
	}
	else {
		color.a -= pulseSpeed;
		rect.setFillColor(color);
		if (color.a <= 40) changeColorAlpha = false;
	}
}
