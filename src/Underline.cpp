#include "pch.h"
#include "Underline.h"


Underline::Underline()
{
}


Underline::~Underline()
{
}


void Underline::initialize(const sf::Color& color, float thickness, float speed) {
	underline.setSize(sf::Vector2f(0.0f, thickness));
	underline.setFillColor(color);
	this->speed = speed;
	size = underline.getSize();
}

void Underline::draw() {
	GameWindow::draw(underline);
}


void Underline::update(sf::Sprite* playSprite, sf::Sprite* exitSprite) {
	if (Collision::mouseCollision(playSprite)) {
		size.x += speed;
		underline.setPosition(sf::Vector2f(playSprite->getPosition().x, playSprite->getPosition().y  + playSprite->getGlobalBounds().height - 5.0f));
		underline.setSize(size);
	}
	else if (Collision::mouseCollision(exitSprite)) {
		size.x += speed;
		underline.setPosition(sf::Vector2f(exitSprite->getPosition().x, exitSprite->getPosition().y + exitSprite->getGlobalBounds().height - 5.0f));
		underline.setSize(size);
	}
	else {
		size.x = 0.0f;
		underline.setSize(size);
	}

	if (underline.getSize().x >= playSprite->getGlobalBounds().width || underline.getSize().x >= exitSprite->getGlobalBounds().width) {
		size.x = playSprite->getGlobalBounds().width;
		underline.setSize(size);
	}
}


