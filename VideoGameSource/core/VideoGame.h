#pragma once
#include "CidWindow.h"
#include <entities/Player.h>

#include <core/GameStateManager.h>


class VideoGame
{
public:
	CidWindow* cwnd;
	Player* guest, * host;
	GameStateManager gStateMgr;
	VideoGame(Player* host_, Player* guest_, CidWindow* cwnd_);
	VideoGame(VideoGame&&) = delete;
	VideoGame& operator=(VideoGame&&) = delete;
	VideoGame() = delete;
	void Initialize( Player* host_, Player* guest_, CidWindow* cwnd_);
	bool input();
	bool update(sf::Time dt_);
	bool handleCollisions();
	bool adjustPositions();
	bool animate();
	bool render();
};
