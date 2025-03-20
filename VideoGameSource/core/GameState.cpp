#include "GameState.h"

GameState::GameState(const GameState& o)
	: host{o.host}
	, guest{o.guest}
	, stateViews{}
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
	stateViews.clear();
	stateViews.reserve(o.stateViews.size());
	for (auto& st : o.stateViews)
	{
		stateViews.push_back(st);
	}
	return *this;
	// TODO: insert return statement here
}

GameState::~GameState() {}