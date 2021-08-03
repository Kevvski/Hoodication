#pragma once
#ifndef TILE_LAYER
#define TILE_LAYER
#include <SFML/Graphics.hpp>
#include <vector>
#include "Constants.h"

class TileLayer
{
public:
	TileLayer();
	~TileLayer();

	void initialize(sf::Texture* texture, const sf::IntRect& tileSize, const sf::Vector2f& startPosition, float scale = 1.0f, int count = 1);
	void draw();

	const sf::Vector2f& getPosition() const;

private:
	std::vector<sf::Sprite> tiles;
};

#endif // !TILE_LAYER

