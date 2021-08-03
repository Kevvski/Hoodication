#pragma once
#ifndef WEAPON_H
#define WEAPON_H
#define _USE_MATH_DEFINES
#include "ObjectAnimation.h"
#include "Player.h"
#include <cmath>

class Weapon
{
public:
	Weapon();
	~Weapon();

	void initialize(sf::Texture* texture, const sf::IntRect& textureRect);
	void setPosition(const sf::Vector2f& position);
	void setScale(float scale);
	void setAngle(float angle);
	void setOrigin(const sf::Vector2f& origin);

	void draw();
	void update(Player* player);

	const sf::Vector2f& getPosition() const;
	sf::FloatRect getRect() const;

private:
	sf::Sprite weaponSprite;
	ObjectAnimation weaponAnimation;
	sf::Vector2f moveVector;
	double angle;
};

#endif // !WEAPON_H

