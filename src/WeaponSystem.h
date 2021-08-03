#pragma once
#ifndef WEAPONSYSTEM_H
#define WEAPONSYSTEM_H
#define _USE_MATH_DEFINES
#include <SFML/Audio.hpp>
#include "Bullet.h"
#include "Player.h"
#include <vector>
#include <cmath>

class WeaponSystem
{
public:
	WeaponSystem();
	~WeaponSystem();

	void initialize(sf::Texture* texture, int count = 10);
	void draw();
	void update(Player* player);

	std::vector<Bullet>& getArrows();

private:
	bool working;
	Weapon bow;
	std::vector<Bullet> arrows;
	size_t index;
	sf::Clock clock;

	//Arrows sounds
	sf::SoundBuffer arrowFlyBuffer;
	sf::Sound arrowFlySound;
};

#endif // !WEAPONSYSTEM_H

