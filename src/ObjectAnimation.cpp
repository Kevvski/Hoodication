#include "pch.h"
#include "ObjectAnimation.h"


ObjectAnimation::ObjectAnimation() : textureRect(0, 0, 0, 0), workAnimation(false), done(false), frameCount(0), frameSpeed(0)
{
}


ObjectAnimation::~ObjectAnimation()
{
}


void ObjectAnimation::initialize(const sf::IntRect& textureRect, int startPosition, int count, int speed) {
	this->textureRect = textureRect;
	this->startPosition = startPosition;
	frameCount = count;
	frameSpeed = speed;
}


void ObjectAnimation::turnOn() {
	workAnimation = true;
}


void ObjectAnimation::turnOff() {
	workAnimation = false;
}


void ObjectAnimation::animate(sf::Sprite* sprite) {
	if (done) {
		done = false;
		sprite->setTextureRect(textureRect);
	}

	if (isWorking()) {
		sf::Time time = clock.getElapsedTime();
		if (time.asMilliseconds() >= frameSpeed && !done) {
			sprite->setTextureRect(textureRect);
			textureRect.top += TILE_SIZE;
			clock.restart();
		}

		if (textureRect.top >= TILE_SIZE * frameCount) {
			textureRect.top = startPosition;
			done = true;
		}
	}
}


const bool ObjectAnimation::isWorking() const {
	return workAnimation;
}


const bool ObjectAnimation::isDone() const {
	return done;
}
