#pragma once
#ifndef BULLET_H
#define BULLET_H
#define _USE_MATH_DEFINES
#include "GameWindow.h"
#include "States.h"
#include "Weapon.h"
#include <cmath>

class Bullet
{
public:
	Bullet();
	~Bullet();

	void initialize(sf::Texture* texture, const sf::IntRect& textureRect);
	void setPosition(const sf::Vector2f& position);
	void setScale(float scale);
	void setOrigin(const sf::Vector2f& origin);
	void setSpeed(float speed);
	void setState(const BulletState& state);
	void move(const sf::Vector2f& move);
	void draw();
	void update(Weapon* weapon);

	const sf::Vector2f& getPosition() const;
	sf::FloatRect getRect() const;
	const BulletState& getState() const;

private:
	sf::Sprite bullet;
	float speed;
	double angle;
	sf::Vector2f moveVector;
	BulletState state;
};

#endif //BULLET_H

