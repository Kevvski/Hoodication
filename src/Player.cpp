#include "pch.h"
#include "Player.h"


//Initialize and settings
//--------------------------------------------------------------------------------------------------------------
Player::Player() : chances(0), score(0)
{
}


Player::~Player()
{
}


void Player::initialize(sf::Texture* texture, const sf::IntRect& firstFrame) {
	playerSprite.setTexture(*texture);
	playerSprite.setTextureRect(firstFrame);
	playerAnimation.initialize(firstFrame, TILE_SIZE, 6, 100);
	playerAnimation.turnOff();
}


void Player::setScale(float scale) {
	playerSprite.setScale(sf::Vector2f(scale, scale));
}


void Player::setPosition(const sf::Vector2f& position) {
	playerSprite.setPosition(position);
}


void Player::setChances(int chances) {
	this->chances = chances;
}


void Player::setScore(int value) {
	score = value;
}


void Player::deincrementChances() {
	chances--;
}


void Player::addScore(int score) {
	this->score += score;
}


void Player::move(const sf::Vector2f& moving) {
	playerSprite.move(moving);
}

//Animation
//--------------------------------------------------------------------------------------------------------------
void Player::startAnimation() {
	playerAnimation.turnOn();
}


void Player::stopAnimation() {
	playerSprite.setTextureRect(sf::IntRect(TILE_SIZE * 2, 26, TILE_SIZE, 6));
	playerAnimation.turnOff();
}


//Drawing and update
//--------------------------------------------------------------------------------------------------------------
void Player::draw() {
	GameWindow::draw(playerSprite);
}


void Player::update() {
	playerAnimation.animate(&playerSprite);
}


//Callbacks
//--------------------------------------------------------------------------------------------------------------
sf::FloatRect Player::getRect() const {
	return playerSprite.getGlobalBounds();
}


const sf::Vector2f& Player::getPosition() const {
	return playerSprite.getPosition();
}


const bool Player::isAnimating() const {
	return playerAnimation.isWorking();
}


const int Player::getChances() const {
	return chances;
}


const int Player::getScore() const {
	return score;
}