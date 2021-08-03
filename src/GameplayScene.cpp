#include "pch.h"
#include "GameplayScene.h"


GameplayScene::GameplayScene()
{
}


GameplayScene::~GameplayScene()
{
}


bool GameplayScene::initialize(Player* player, sf::Texture* texture) {
	if (!gui.initialize("res/fonts/pixelFont.ttf", player, texture)) {
		std::cerr << "Initialize Gui failed!\n";
		return false;
	}

	weaponSystem.initialize(texture);

	if (!targetSystem.initialize(texture))
		return false;

	return true;
}


void GameplayScene::draw(Player* player) {
	targetSystem.draw();
	weaponSystem.draw();
	gui.draw(player);
}


void GameplayScene::update(Player* player, TileLayer* ground) {
	player->setPosition(sf::Vector2f(player->getPosition().x, ground->getPosition().y - player->getRect().height));
	gui.update(player);
	weaponSystem.update(player);
	targetSystem.update(player, &weaponSystem);
}
