#include "CidWindow.h"

CidWindow::~CidWindow()
{
}

void CidWindow::create(int width_, int height_, std::string title_, sf::State state_)
{
	sf::RenderWindow::create(sf::VideoMode{ sf::Vector2u(width_,height_), 32U }, title_, sf::State::Windowed);
	this->setPosition({ 400u,100u });
}
