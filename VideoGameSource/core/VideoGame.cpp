#include "videogame.h"

bool VideoGame::update(sf::Time dt_)
{


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
	{
		host->xpos += 300.f * dt_.asSeconds();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
	{
		host->xpos -= 300.f * dt_.asSeconds();
	}

	gStateMgr.Update(dt_);
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


VideoGame::VideoGame( Player* host_, Player* guest_, CidWindow* cwnd_)
	: cwnd{cwnd_}
	, guest{ guest_ }
	, host{host_}
	, gStateMgr{host_, guest_, cwnd_}
{
	
}


void VideoGame::Initialize(Player* host_, Player* guest_, CidWindow* cwnd_)
{
	cwnd = cwnd_;
	host = host_;
	guest = guest_;
	gStateMgr = GameStateManager{ host_,guest_,cwnd_ };
}

bool VideoGame::input()
{
	gStateMgr.Input();
	return true;
}
