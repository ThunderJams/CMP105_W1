#include "Level.h"

Level::Level(sf::RenderWindow* hwnd)
{
	window = hwnd;

	// initialise game objects
	rect.setSize(sf::Vector2f(50, 50));
	rect.setPosition(100, 100);
	rect.setFillColor(sf::Color::Red);

	rect2.setSize(sf::Vector2f(25, 25));
	rect2.setPosition(115, 115);
	rect2.setFillColor(sf::Color::Green);

	rect3.setSize(sf::Vector2f(10, 10));
	rect3.setPosition(125, 125);
	rect3.setFillColor(sf::Color::Blue);

	rectCorner.setSize(sf::Vector2f(100, 50));
	rectCorner.setPosition(0,0);
	rectCorner.setFillColor(sf::Color::Green);

	circle.setRadius(50);
	circle.setPosition(600, 337);
	circle.setFillColor(sf::Color::Blue);
	circle.setOutlineColor(sf::Color::Red);
	circle.setOutlineThickness(2.f);

	if (!font.loadFromFile("font/arial.ttf")) {
		std::cout << "Error\n";
	}

	text.setFont(font);
	text.setString("Hello World");
	text.setCharacterSize(24);
	text.setFillColor(sf::Color::Red);
}

Level::~Level()
{
}

// handle user input
void Level::handleInput()
{

}

// Update game objects
void Level::update()
{
	sf::Vector2u pos = window->getSize();
	rectCorner.setPosition((pos.x-100), (pos.y-50));
}

// Render level
void Level::render()
{
	beginDraw();

	window->draw(rect);
	window->draw(rect2);
	window->draw(rect3);
	
	window->draw(circle);
	window->draw(text);

	window->draw(rectCorner);

	endDraw();
}

void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}