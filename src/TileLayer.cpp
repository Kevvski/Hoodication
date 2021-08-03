#include "pch.h"
#include "TileLayer.h"


TileLayer::TileLayer()
{
}


TileLayer::~TileLayer()
{
}


void TileLayer::initialize(sf::Texture* texture, const sf::IntRect& tileSize, const sf::Vector2f& startPosition, float scale, int count) {
	sf::Sprite tile;
	tile.setTexture(*texture);
	tile.setTextureRect(tileSize);
	tile.setPosition(startPosition);
	tile.setScale(sf::Vector2f(scale, scale));

	for (int i = 0; i < count; i++)
		tiles.push_back(tile);

	for (int i = 1; i < tiles.size(); i++) {
		tiles.at(i).setPosition(sf::Vector2f(
			tiles.at(i - 1).getPosition().x + tiles.at(i - 1).getGlobalBounds().width,
			tiles.at(i - 1).getPosition().y
		));
	}
}


void TileLayer::draw() {
	for (const auto tile : tiles)
		GameWindow::draw(tile);
}


const sf::Vector2f& TileLayer::getPosition() const {
	return tiles.at(0).getPosition();
}
