#pragma once
#include "CidWindow.h"
#include <entities/Player.h>

class VideoGame
{
public:
	CidWindow* cwnd;
	Player* guest, * host;

	VideoGame(CidWindow* cwnd_, Player* guest_, Player* host_);

	void Initialize(CidWindow& cwnd_, Player& guest_);
	bool update(sf::Time dt_);
	bool handleCollisions();
	bool adjustPositions();
	bool animate();
	bool render();
};
