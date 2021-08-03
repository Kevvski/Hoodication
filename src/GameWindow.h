#pragma once
#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H
#include <SFML/Graphics.hpp>

class GameWindow
{
public:
	GameWindow();
	~GameWindow();

	static void initialize(const std::string& title, int antialiasLevel = 4, int fps = 30);
	static void draw(const sf::Drawable& drawableObject);
	static void draw(const sf::Vertex *vertices, std::size_t vertexCount, sf::PrimitiveType type);
	static void display();
	static void clear(const sf::Color& color = sf::Color(0, 0, 0, 255));
	static void close();

	static const bool isOpen();
	static bool pollEvent(sf::Event& event);
	static sf::Vector2u getWindowSize();
	static const sf::RenderWindow& getWindow();

private:
	static sf::ContextSettings windowSettings;
	static sf::RenderWindow window;
};

#endif // !GAMEWINDOW_H

