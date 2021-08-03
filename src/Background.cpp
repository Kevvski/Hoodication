#include "pch.h"
#include "Background.h"


Background::Background() : changeColorSpeed(0), firstColorChange(0, 0, 0), secondColorChange(0, 0, 0), bgSprite(nullptr)
{
}


Background::~Background()
{
}


void Background::initialize(const sf::Color& firstColor, const sf::Color& secondColor) {
	for (int i = 0; i < 4; i++)
		vertices.push_back(sf::Vertex());

	firstColorChange = firstColor;
	secondColorChange = secondColor;

	vertices.at(0).color = firstColorChange;
	vertices.at(0).position = sf::Vector2f(0.0f, 0.0f);

	vertices.at(1).color = firstColorChange;
	vertices.at(1).position = sf::Vector2f(static_cast<float>(GameWindow::getWindowSize().x), 0.0f);

	vertices.at(2).color = secondColorChange;
	vertices.at(2).position = sf::Vector2f(0.0f, static_cast<float>(GameWindow::getWindowSize().y));

	vertices.at(3).color = secondColorChange;
	vertices.at(3).position = sf::Vector2f(static_cast<float>(GameWindow::getWindowSize().x), static_cast<float>(GameWindow::getWindowSize().y));
}


bool Background::initialize(const std::string& fileName, float scale) {
	if (!bgTexture.loadFromFile(fileName)) {
		std::cerr << "Load file: " << fileName << " failed\n";
		return false;
	}
	else {
		bgSprite = new sf::Sprite();
		bgSprite->setTexture(bgTexture);
		bgSprite->setScale(sf::Vector2f(scale, scale));
		bgSprite->setColor(sf::Color(255, 255, 255, 0));
		return true;
	}
}


void Background::setChangeColorSpeed(int speed) {
	changeColorSpeed = speed;
}


void Background::smoothChange(const sf::Color& firstTargetColor, const sf::Color& secondTargetColor) {
	//Color coord: R
	//--------------
	if (firstColorChange.r < firstTargetColor.r) 
		firstColorChange.r += changeColorSpeed;
	else if(firstColorChange.r > firstTargetColor.r)
		firstColorChange.r -= changeColorSpeed;

	if (secondColorChange.r < secondTargetColor.r) 
		secondColorChange.r += changeColorSpeed;
	else if(secondColorChange.r > secondTargetColor.r)
		secondColorChange.r -= changeColorSpeed;

	//Color coord: G
	//--------------
	if (firstColorChange.g < firstTargetColor.g) 
		firstColorChange.g += changeColorSpeed;
	else if(firstColorChange.g > firstTargetColor.g)
		firstColorChange.g -= changeColorSpeed;

	if (secondColorChange.g < secondTargetColor.g) 
		secondColorChange.g += changeColorSpeed;
	else if(secondColorChange.g > secondTargetColor.g)
		secondColorChange.g -= changeColorSpeed;

	//Color coord: B
	//--------------
	if (firstColorChange.b < firstTargetColor.b ) 
		firstColorChange.b += changeColorSpeed;
	else if(firstColorChange.b > firstTargetColor.b)
		firstColorChange.b -= changeColorSpeed;

	if (secondColorChange.b < secondTargetColor.b) 
		secondColorChange.b += changeColorSpeed;
	else if(secondColorChange.b > secondTargetColor.b)
		secondColorChange.b -= changeColorSpeed;

	setColors();
}


void Background::outTransparent() {
	static sf::Color changeColor(255, 255, 255, 0);
	changeColor.a += 1;
	bgSprite->setColor(changeColor);
}


void Background::draw() {
	if(vertices.size() != 0)
		GameWindow::draw(&vertices.at(0), vertices.size(), sf::TrianglesStrip);

	if (bgSprite != nullptr)
		GameWindow::draw(*bgSprite);
}


void Background::setColors() {
	vertices.at(0).color = firstColorChange;
	vertices.at(1).color = firstColorChange;
	vertices.at(2).color = secondColorChange;
	vertices.at(3).color = secondColorChange;
}
