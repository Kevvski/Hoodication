#pragma once
#ifndef COLLISION_H
#define COLLISION_H
#include "GameWindow.h"

class Collision
{
public:
	Collision();
	~Collision();

	static const bool mouseCollision(sf::Sprite* sprite);
	static const bool collisionAABB(const sf::FloatRect& firstRect, const sf::FloatRect& secondRect);
};

#endif // !COLLISION_H

