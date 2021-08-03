#include "pch.h"
#include "GameWindow.h"

sf::ContextSettings GameWindow::windowSettings;
sf::RenderWindow GameWindow::window;


GameWindow::GameWindow()
{
}


GameWindow::~GameWindow()
{
}


void GameWindow::initialize(const std::string& title, int antialiasLevel, int fps) {
	windowSettings.antialiasingLevel = antialiasLevel;
	window.create(sf::VideoMode::getDesktopMode(), title, sf::Style::Fullscreen, windowSettings);
	window.setFramerateLimit(fps);
}


void GameWindow::draw(const sf::Drawable& drawableObject) {
	window.draw(drawableObject);
}


void GameWindow::draw(const sf::Vertex *vertices, std::size_t vertexCount, sf::PrimitiveType type) {
	window.draw(vertices, vertexCount, type);
}


void GameWindow::display() {
	window.display();
}


void GameWindow::clear(const sf::Color& color) {
	window.clear(color);
}


void GameWindow::close() {
	window.close();
}


const bool GameWindow::isOpen() {
	return window.isOpen();
}


bool GameWindow::pollEvent(sf::Event& event) {
	return window.pollEvent(event);
}


sf::Vector2u GameWindow::getWindowSize() {
	return window.getSize();
}


const sf::RenderWindow& GameWindow::getWindow() {
	return window;
}
