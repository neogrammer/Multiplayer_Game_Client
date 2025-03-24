#pragma once

#include <SFML/Graphics.hpp>

class CidWindow : public sf::RenderWindow
{
public:
	using sf::RenderWindow::RenderWindow;
	~CidWindow() override final;
	void create(int width_, int height_, std::string title_, sf::State state_);
};