#pragma once
#include "CidWindow.h"
#include <entities/Player.h>
#include <core/GameStateManager.h>

class VideoGame
{
public:
	CidWindow* cwnd;
	Player* guest, * host;

	GameStateManager gStateMgr{};
	VideoGame(CidWindow* cwnd_, Player* host_, Player* guest_);

	void Initialize(CidWindow& cwnd_, Player& guest_);
	void input();
	bool update(sf::Time dt_, Player* host_, Player* guest_);
	bool handleCollisions();
	bool adjustPositions();
	bool animate();
	bool render();
};
