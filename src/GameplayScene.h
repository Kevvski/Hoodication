#pragma once
#ifndef GAMEPLAYSCENE_H
#define GAMEPLAYSCENE_H
#include "GUI.h"
#include "WeaponSystem.h"
#include "TargetSystem.h"
#include "TileLayer.h"

class GameplayScene
{
public:
	GameplayScene();
	~GameplayScene();

	bool initialize(Player* player, sf::Texture* texture);
	void draw(Player* player);
	void update(Player* player, TileLayer* ground);

private:
	GUI gui;
	WeaponSystem weaponSystem;
	TargetSystem targetSystem;
};

#endif // !GAMEPLAYSCENE_H
