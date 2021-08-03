#include "pch.h"
#include "Weapon.h"


Weapon::Weapon()
{
}


Weapon::~Weapon()
{
}


void Weapon::initialize(sf::Texture* texture, const sf::IntRect& textureRect) {
	weaponSprite.setTexture(*texture);
	weaponSprite.setTextureRect(textureRect);
	weaponAnimation.initialize(textureRect, 0, 7, 50);
	weaponAnimation.turnOff();
}


void Weapon::setPosition(const sf::Vector2f& position) {
	weaponSprite.setPosition(position);
}


void Weapon::setScale(float scale) {
	weaponSprite.setScale(sf::Vector2f(scale, scale));
}


void Weapon::setAngle(float angle) {
	weaponSprite.setRotation(angle);
}


void Weapon::setOrigin(const sf::Vector2f& origin) {
	weaponSprite.setOrigin(origin);
}


void Weapon::draw() {
	GameWindow::draw(weaponSprite);
}


void Weapon::update(Player* player) {
	weaponAnimation.animate(&weaponSprite);
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		weaponAnimation.turnOn();
	}

	if (weaponAnimation.isDone()) {
		weaponAnimation.turnOff();
	}

	weaponSprite.setPosition(sf::Vector2f(
			resizer(player->getPosition().x + 80.0f, player->getPosition().x + 50.0f),
			resizer(player->getPosition().y - 50.0f, player->getPosition().y - 30.0f)));

	moveVector.x = sf::Mouse::getPosition(GameWindow::getWindow()).x - weaponSprite.getPosition().x;
	moveVector.y = sf::Mouse::getPosition(GameWindow::getWindow()).y - weaponSprite.getPosition().y;
	angle = (std::atan2(moveVector.y, moveVector.x) * 180.0) / M_PI;
	weaponSprite.setRotation(static_cast<float>(angle));
}


const sf::Vector2f& Weapon::getPosition() const {
	return weaponSprite.getPosition();
}


sf::FloatRect Weapon::getRect() const {
	return weaponSprite.getGlobalBounds();
}
