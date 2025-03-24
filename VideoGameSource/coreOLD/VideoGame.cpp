#include "videogame.h"

bool VideoGame::update(sf::Time dt_, Player* host_, Player* guest_)
{
	gameTime = dt_;
	host = host_;
	guest = guest_;

	if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
	{
	 guest->xpos += 300.f * dt_.asSeconds();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
	{
		guest->xpos -= 300.f * dt_.asSeconds();
	}

	gStateMgr.Update(gameTime, host_, guest_);

	return true;
}

bool VideoGame::handleCollisions()
{
	return true;
}

bool VideoGame::adjustPositions()
{

	return true;
}

bool VideoGame::animate()
{
	return true;
}

bool VideoGame::render()
{

	gStateMgr.Render(*cwnd);

	sf::RectangleShape shp1;
	shp1.setSize({ 100.f, 150.f });
	shp1.setPosition({ host->xpos, host->ypos });
	shp1.setFillColor(sf::Color::Green);

	sf::RectangleShape shp2;
	shp2.setSize({ 100.f, 150.f });
	shp2.setPosition({ guest->xpos, guest->ypos });
	shp2.setFillColor(sf::Color::Yellow);

	cwnd->draw(shp1);
	cwnd->draw(shp2);


	return true;
}


VideoGame::VideoGame(CidWindow* cwnd_, Player* host_, Player* guest_)
	: cwnd{cwnd_}
	, guest{ guest_ }
	, host{host_}
{
}


void VideoGame::Initialize(CidWindow& cwnd_, Player& guest_)
{
	cwnd = &cwnd_;
	guest = &guest_;
}

void VideoGame::input()
{
	gStateMgr.Input();
}
