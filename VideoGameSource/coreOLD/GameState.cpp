#include "GameState.h"
#include <core/GameStateManager.h>
GameState::GameState(StateID stateID_, GameStateManager* mgr_, Player* host_, Player* guest_, sf::RenderWindow& wnd_)
	: _sid{ stateID_ }
	, host{host_}
	, guest{guest_}
	, stateViews{}
	, gStateMgr{mgr_}
{
	stateViews.clear();
	stateViews.push_back(wnd_.getDefaultView());
	
}

GameState& GameState::operator=(const GameState& o)
{
	this->host = nullptr;
	this->guest = nullptr;
	this->host = o.host;
	this->guest = o.guest;
	stateViews.clear();
	stateViews.reserve(o.stateViews.size());
	for (auto& st : o.stateViews)
	{
		stateViews.push_back(st);
	}
	return *this;
	// TODO: insert return statement here
}

StateID GameState::getStateID()
{
	return _sid;
}

GameState::GameState()
	: _sid{StateID::Splash}
{
}

GameState::GameState(StateID stateID_)
	: _sid{stateID_}
{

}

GameState::~GameState() {}

GameState::GameState(const GameState&)
{
}
