#include "pch.h"
#include "Bullet.h"


Bullet::Bullet() : speed(0.0f), angle(0.0), state(BulletState::NOT_SHOOT)
{
}


Bullet::~Bullet()
{
}


void Bullet::initialize(sf::Texture* texture, const sf::IntRect& textureRect) {
	bullet.setTexture(*texture);
	bullet.setTextureRect(textureRect);
}


void Bullet::setPosition(const sf::Vector2f& position) {
	bullet.setPosition(position);
}


void Bullet::setScale(float scale) {
	bullet.setScale(sf::Vector2f(scale, scale));
}


void Bullet::setOrigin(const sf::Vector2f& origin) {
	bullet.setOrigin(origin);
}


void Bullet::setSpeed(float speed) {
	this->speed = speed;
}


void Bullet::setState(const BulletState& state) {
	this->state = state;
}


void Bullet::move(const sf::Vector2f& move) {
	bullet.move(move);
}


void Bullet::draw() {
	GameWindow::draw(bullet);
}


void Bullet::update(Weapon* weapon) {
	if (state == BulletState::NOT_SHOOT) {
		moveVector.x = static_cast<float>(sf::Mouse::getPosition(GameWindow::getWindow()).x - bullet.getPosition().x);
		moveVector.y = static_cast<float>(sf::Mouse::getPosition(GameWindow::getWindow()).y - bullet.getPosition().y);
		angle = (std::atan2(moveVector.y, moveVector.x) * 180.0) / M_PI;
		bullet.setRotation(angle);
		bullet.setPosition(weapon->getPosition().x, weapon->getPosition().y);
	}
	else if (state == BulletState::SHOOT) {
		moveVector.y += 5.0f;
		angle += 0.4;
		bullet.move(sf::Vector2f(moveVector.x * speed, moveVector.y * speed));
		bullet.setRotation(static_cast<float>(angle));

		if (bullet.getPosition().x > GameWindow::getWindowSize().x) state = BulletState::NOT_SHOOT;
	}
}


const sf::Vector2f& Bullet::getPosition() const {
	return bullet.getPosition();
}


sf::FloatRect Bullet::getRect() const {
	return bullet.getGlobalBounds();
}


const BulletState& Bullet::getState() const {
	return state;
}