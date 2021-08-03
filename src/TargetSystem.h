#pragma once
#ifndef TARGETSYTEM_H
#define TARGETSYSTEM_H
#include "Target.h"
#include "Constants.h"
#include "Collision.h"
#include "WeaponSystem.h"
#include "Player.h"
#include <vector>
#include <iostream>
#include <cstdio>
#include <ctime>

class TargetSystem
{
public:
	TargetSystem();
	~TargetSystem();

	bool initialize(sf::Texture* texture);
	void draw();
	void update(Player* player, WeaponSystem* weaponSystem);

private:
	sf::Font font;
	std::vector<Target> targets;

	//Game Logic
	sf::Text operation;
	int number;
	int multiply;
	int result;
	size_t index;

	//Sounds
	sf::SoundBuffer arrowCollisionBuffer;
	sf::Sound arrowCollisionSound;

private:
	void random();
};

#endif //TARGETSYSTEM_H

