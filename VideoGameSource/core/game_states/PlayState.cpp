#include "PlayState.h"
#include <SFML/Graphics.hpp>
#include "../Globals.h"

PlayState::PlayState() : GameState{}, player{ nullptr }
{
    // Single main view for the splash screen
    stateViews.resize(1);
    stateViews[0] = sf::View(sf::FloatRect({ 0.f, 0.f }, { glb::WINW, glb::WINH })); // Example view setup

    sf::Texture tex{ "Assets/Textures/Knight_player/Idle_KG_2.png" };
    player = new PlayerSprite{ &tex };
}

PlayState::PlayState(GameStateManager* mgr_, Player* host_, Player* guest_, sf::RenderWindow* wnd_)
    : GameState{ StateID::Save, mgr_, host_, guest_, wnd_ }
{
    stateViews.resize(1);
    stateViews[0] = sf::View(sf::FloatRect({ 0.f, 0.f }, { glb::WINW, glb::WINH })); // Example view setup

    sf::Texture tex{ "Assets/Textures/Knight_player/Idle_KG_2.png" };
    player = new PlayerSprite{ &tex };
}

PlayState::~PlayState()
{
}

PlayState::PlayState(const PlayState& o)
    : GameState{ StateID::Save,o.gStateMgr,o.host,o.guest,o.window }
{
    for (auto& vw : o.stateViews)
        stateViews.push_back(vw);
    sf::Texture tex{ "Assets/Textures/Knight_player/Idle_KG_2.png" };
    player = new PlayerSprite{ &tex };
}

PlayState& PlayState::operator=(const PlayState& o)
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

    sf::Texture tex{ "Assets/Textures/Knight_player/Idle_KG_2.png" };
    player = new PlayerSprite{ &tex };



    //// TODO: insert return statement here
    //bgSpr = o.bgSpr;
    //stateViews.resize(1);
    //stateViews[0] = sf::View(sf::FloatRect({ 0.f, 0.f }, { glb::WINW, glb::WINH })); // Example view setup
    return *this;
    // TODO: insert return statement here
}

void PlayState::Input() {
    player->input();
    // Handle skip/continue inputs (ex: keypress, mouse click)
}

void PlayState::Update(sf::Time dt_)
{
    GameState::Update(dt_);
    player->update(dt_);

}
void PlayState::Render(sf::RenderWindow& wnd_) {
    player->render(wnd_);
    // Will draw splash screen elements (placeholder for now)
}

sf::View& PlayState::GetView(PlayViewID id)
{
    return stateViews.at((size_t)id);
}
