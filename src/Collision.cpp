#include "pch.h"
#include "Collision.h"


Collision::Collision()
{
}


Collision::~Collision()
{
}


const bool Collision::mouseCollision(sf::Sprite* sprite) {
	sf::Vector2i mousePosition = sf::Mouse::getPosition(GameWindow::getWindow());
	bool left = mousePosition.x >= sprite->getPosition().x;
	bool right = mousePosition.x <= sprite->getPosition().x + sprite->getGlobalBounds().width;
	bool top = mousePosition.y >= sprite->getPosition().y;
	bool bottom = mousePosition.y <= sprite->getPosition().y + sprite->getGlobalBounds().height;
	return left && right && top && bottom;
}


const bool Collision::collisionAABB(const sf::FloatRect& firstRect, const sf::FloatRect& secondRect) {
	bool leftToRight = firstRect.left + firstRect.width >= secondRect.left;
	bool rightToLeft = firstRect.left <= secondRect.left + secondRect.width;
	bool topToBottom = firstRect.top <= secondRect.top + secondRect.height;
	bool bottomToTop = firstRect.top + firstRect.height >= secondRect.top;

	return leftToRight && rightToLeft && topToBottom && bottomToTop;
}
