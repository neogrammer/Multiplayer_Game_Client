#include "GameState.h"

#include <core/GameStateManager.h>
GameState::GameState(const GameState& o)
	: gStateMgr{o.gStateMgr}
	, host{o.host}
	, guest{ o.guest }
    , stateViews{}
	, window{o.window}
	, gameTime{ o.gameTime }
	, needsToAddOn{ o.needsToAddOn }
	, needsToSwitchOut{ o.needsToSwitchOut }
    , stateInWait{ StateID::Count }
{
	stateViews.clear();
	stateViews.reserve(o.stateViews.size());
	for (auto& st : o.stateViews)
	{
		stateViews.push_back(st);
	}
}

GameState& GameState::operator=(const GameState& o)
{
	this->host = nullptr;
	this->guest = nullptr;
	this->host = o.host;
	this->guest = o.guest;
	this->gStateMgr = o.gStateMgr;
	gameTime = o.gameTime;
	needsToAddOn = o.needsToAddOn;
	needsToSwitchOut = o.needsToSwitchOut;
	stateInWait = StateID::Count;
	this->window = o.window;
	stateViews.clear();
	stateViews.reserve(o.stateViews.size());
	for (auto& st : o.stateViews)
	{
		stateViews.push_back(st);
	}
	return *this;

}

void GameState::Update(sf::Time deltaTime)
{
	gameTime = deltaTime;


}

StateID GameState::getStateID()
{
	return _sid;
}

GameState::GameState()
	: _sid{ StateID::Count }
	, host{}
	, guest{}
	, stateViews{}
	, gStateMgr{}
	, gameTime{ }
	, needsToAddOn{ }
	, needsToSwitchOut{}
	, window{nullptr}
	, stateInWait{ StateID::Count }
{
}

GameState::GameState(StateID stateID_,  GameStateManager* mgr_, Player* host_, Player* guest_, sf::RenderWindow* wnd_)
	:  _sid{ stateID_ }
	, host{host_}
	, guest{guest_}
	, gStateMgr{mgr_}
	, window{wnd_}
	, stateViews{}
	, gameTime{ }
	, needsToAddOn{ }
	, needsToSwitchOut{}
	, stateInWait{ StateID::Count }
{
	stateViews.clear();
	stateViews.push_back(wnd_->getDefaultView());
}

GameState::~GameState() {}


