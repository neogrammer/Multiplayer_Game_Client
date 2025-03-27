#include "TitleState.h"
#include "../Globals.h"

TitleState::TitleState() : GameState{}, bgSpr{ Cfg::Textures::TitleBG } {
    stateViews.resize(1);
    stateViews[0] = sf::View(sf::FloatRect({ 0.f, 0.f }, { glb::WINW, glb::WINH })); // Example view setup
}

TitleState::TitleState(GameStateManager* mgr_, Player* host_, Player* guest_, sf::RenderWindow* wnd_)
    : GameState{StateID::Title, mgr_, host_, guest_, wnd_}
    , bgSpr{ Cfg::Textures::TitleBG }
{
    stateViews.resize(1);
    stateViews[0] = sf::View(sf::FloatRect({ 0.f, 0.f }, { glb::WINW, glb::WINH })); // Example view setup
}

TitleState::~TitleState()
{

}

TitleState::TitleState(const TitleState& o)
    : GameState{ dynamic_cast<const GameState&>(o) }
    , bgSpr{ Cfg::Textures::SplashBG }
{
    for (auto& vw : o.stateViews)
        stateViews.push_back(vw);
}

TitleState& TitleState::operator=(const TitleState& o)
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
    bgSpr = o.bgSpr;
    // TODO: insert return statement here

  
    return *this;
}

void TitleState::Input() {
    // Start game, options, etc.
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::H))
    {
        stateInWait = StateID::Play;
        needsToSwitchOut = true;
        needsToAddOn = false;
    }
}

void TitleState::Update(sf::Time dt_)
{
    GameState::Update(dt_);

}

void TitleState::Render(sf::RenderWindow& wnd_) {
    sf::Sprite bg{ Cfg::textures.get((int)bgSpr) };
    bg.setPosition({ 0.f,0.f });
    wnd_.draw(bg);
    // Draw the title screen logo, buttons
}
