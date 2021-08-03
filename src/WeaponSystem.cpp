#include "pch.h"
#include "WeaponSystem.h"


WeaponSystem::WeaponSystem() : working(true), index(0)
{
}


WeaponSystem::~WeaponSystem()
{
}


void WeaponSystem::initialize(sf::Texture* texture, int count) {
	bow.initialize(texture, sf::IntRect(TILE_SIZE * 4, 0, TILE_SIZE, TILE_SIZE));
	bow.setScale(resizer(5.0f, 3.0f));
	bow.setOrigin(sf::Vector2f(TILE_SIZE / 2, TILE_SIZE / 2));

	Bullet arrow;
	arrow.initialize(texture, sf::IntRect(TILE_SIZE * 3, 0, TILE_SIZE, TILE_SIZE));
	arrow.setSpeed(0.035f);
	arrow.setScale(resizer(2.8f, 1.8f));
	arrow.setOrigin(sf::Vector2f(5.0f, TILE_SIZE / 2 - 3.0f));

	for (int i = 0; i < count; i++)
		arrows.push_back(arrow);

	if (!arrowFlyBuffer.loadFromFile("res/sounds/arrow-fly.wav"))
		std::cerr << "Load arrow-fly.wav failed!\n";

	arrowFlySound.setBuffer(arrowFlyBuffer);
}


void WeaponSystem::draw() {
	bow.draw();

	for (auto arrow : arrows)
		arrow.draw();
}


void WeaponSystem::update(Player* player) {
	if (player->getChances() == 0 && sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
		player->setChances(3);
		player->setScore(0);

		for (auto& arrow : arrows)
			arrow.setState(BulletState::NOT_SHOOT);

		working = true;
	}

	if (working) {
		bow.update(player);

		for (auto& arrow : arrows)
			arrow.update(&bow);

		sf::Time time = clock.getElapsedTime();
		if (time.asMilliseconds() >= 500 && sf::Mouse::isButtonPressed(sf::Mouse::Left) && index < arrows.size()) {
			arrows.at(index).setState(BulletState::SHOOT);
			arrowFlySound.play();
			index++;
			clock.restart();
		}

		if (index == arrows.size() - 1) index = 0;
		if (player->getChances() == 0) working = false;
	}
}


std::vector<Bullet>& WeaponSystem::getArrows(){
	return arrows;
}
