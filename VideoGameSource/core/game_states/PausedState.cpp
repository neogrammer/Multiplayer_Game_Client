#include "PausedState.h"
#include <SFML/Graphics.hpp>
#include "../Globals.h"

PausedState::PausedState() : GameState{} {
    // Single main view for the splash screen
    stateViews.resize(1);
    stateViews[0] = sf::View(sf::FloatRect({ 0.f, 0.f }, { glb::WINW, glb::WINH })); // Example view setup
}

PausedState::PausedState(GameStateManager* mgr_, Player* host_, Player* guest_, sf::RenderWindow* wnd_)
    : GameState{ StateID::Save, mgr_, host_, guest_, wnd_ }
{
    stateViews.resize(1);
    stateViews[0] = sf::View(sf::FloatRect({ 0.f, 0.f }, { glb::WINW, glb::WINH })); // Example view setup
}

PausedState::~PausedState()
{
}

PausedState::PausedState(const PausedState& o)
    : GameState{ StateID::Save,o.gStateMgr,o.host,o.guest,o.window }
{
    for (auto& vw : o.stateViews)
        stateViews.push_back(vw);
}

PausedState& PausedState::operator=(const PausedState& o)
{
    window = o.window;
    needsToAddOn = o.needsToAddOn;
    needsToSwitchOut = o.needsToSwitchOut;
    stateInWait = o.stateInWait;
    gameTime = o.gameTime;
    _sid = o._sid;
    guest = o.guest;
    host = o.host;
    gStateMgr = o.gStateMgr;
    for (auto& vw : o.stateViews)
        stateViews.push_back(vw);

    //// TODO: insert return statement here
    //bgSpr = o.bgSpr;
    //stateViews.resize(1);
    //stateViews[0] = sf::View(sf::FloatRect({ 0.f, 0.f }, { glb::WINW, glb::WINH })); // Example view setup
    return *this;
    // TODO: insert return statement here
}

void PausedState::Input() {
    // Handle skip/continue inputs (ex: keypress, mouse click)
}

void PausedState::Update(sf::Time dt_)
{
    GameState::Update(dt_);

}
void PausedState::Render(sf::RenderWindow& wnd_) {
    // Will draw splash screen elements (placeholder for now)
}
