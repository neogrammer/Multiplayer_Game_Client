#pragma once
#include "CidWindow.h"
#include <entities/Player.h>

class VideoGame
{
public:
	CidWindow* cwnd;
	Player* guest, * host;

	VideoGame(CidWindow* cwnd_, Player* host_, Player* guest_);

	void Initialize(CidWindow& cwnd_, Player& guest_);
	bool update(sf::Time dt_, Player* host_, Player* guest_);
	bool handleCollisions();
	bool adjustPositions();
	bool animate();
	bool render();
};
