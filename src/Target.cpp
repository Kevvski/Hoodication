#include "pch.h"
#include "Target.h"


Target::Target() : number(0)
{
}


Target::~Target()
{
}


void Target::initialize(sf::Texture* texture, const sf::IntRect& textureRect, const sf::Font& font) {
	targetSprite.setTexture(*texture);
	targetSprite.setTextureRect(textureRect);
	numberText.setFont(font);
}


void Target::initializeText(int charSize, const sf::Color& color) {
	numberText.setCharacterSize(charSize);
	numberText.setFillColor(color);
}


void Target::setNumber(int number) {
	this->number = number;
}


void Target::setStringNumber() {
	numberText.setString(std::to_string(number));
}


void Target::setPosition(const sf::Vector2f& position) {
	targetSprite.setPosition(position);
	numberText.setPosition(sf::Vector2f(
		targetSprite.getPosition().x + targetSprite.getGlobalBounds().width / 2, 
		targetSprite.getPosition().y + targetSprite.getGlobalBounds().height / 2 - 30.0f));
}


void Target::setScale(float scale) {
	targetSprite.setScale(sf::Vector2f(scale, scale));
}


void Target::setTextSize(int size) {
	numberText.setCharacterSize(size);
}


void Target::setTextColor(const sf::Color& color) {
	numberText.setFillColor(color);
}


void Target::move(const sf::Vector2f& move) {
	targetSprite.move(move);
	numberText.move(move);
}


void Target::draw() {
	GameWindow::draw(targetSprite);
	GameWindow::draw(numberText);
}


const int Target::getNumber() const {
	return number;
}


const sf::Vector2f& Target::getPosition() const {
	return targetSprite.getPosition();
}


sf::FloatRect Target::getRect() const {
	return targetSprite.getGlobalBounds();
}
