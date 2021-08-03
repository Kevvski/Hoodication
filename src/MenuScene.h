#pragma once
#ifndef MENUSCENE_H
#define MENUSCENE_H
#include <iostream>
#include <SFML/Audio.hpp>
#include "Constants.h"
#include "ObjectAnimation.h"
#include "ParticleSystem.h"
#include "Underline.h"
#include "States.h"
#include "Player.h"
#include "Background.h"

class MenuScene
{
public:
	MenuScene();
	~MenuScene();

	bool initialize(sf::Texture* objectsTexture);
	void draw();
	void update(GameState* gameState, Player* player, Background* bg, Background* mountains);

private:
	//Menu's images
	sf::Texture textureLogo;
	sf::Texture playTexture;
	sf::Texture exitTexture;
	sf::Sprite logoSprite;
	sf::Sprite playSprite;
	sf::Sprite exitSprite;

	//Underline
	Underline underline;

	//Campfire
	sf::Sprite campfire;
	ObjectAnimation campfireAnimation;

	//Particle system(Stars)
	ParticleSystem particleSystem;

	//Sound
	sf::Music campfireMusic;
	sf::SoundBuffer clickBuffer;
	sf::SoundBuffer walkBuffer;
	sf::Sound clickSound;
	sf::Sound walkSound;
};

#endif // !MENUSCENE_H

