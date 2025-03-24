#include "SplashState.h"
#include <SFML/Graphics.hpp>
#include "../Globals.h"

SplashState::SplashState()
    : GameState{}
    , bgSpr{Cfg::Textures::SplashBG}
{

    stateViews.resize(1);
    stateViews[0] = sf::View(sf::FloatRect({ 0.f, 0.f }, { glb::WINW, glb::WINH })); // Example view setup
}

SplashState::~SplashState()
{
}

SplashState::SplashState(GameStateManager* gStateMgr_, Player* host_, Player* guest_,sf::RenderWindow* wnd_) : GameState{StateID::Splash, gStateMgr_,host_, guest_, wnd_},  bgSpr { Cfg::Textures::SplashBG }
{
    // Single main view for the splash screen
    stateViews.resize(1);
    stateViews[0] = sf::View(sf::FloatRect({ 0.f, 0.f }, { glb::WINW, glb::WINH })); // Example view setup
}

SplashState::SplashState(const SplashState& o)
    : GameState{dynamic_cast<const GameState&>(o)}
    , bgSpr{Cfg::Textures::SplashBG}
{
    for (auto& vw : o.stateViews)
        stateViews.push_back(vw);
}

SplashState& SplashState::operator=(const SplashState& o)
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

void SplashState::Input() {

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter))
    {
        stateInWait = StateID::Title;
        needsToSwitchOut = true;
        needsToAddOn = false;
    }
    // Handle skip/continue inputs (ex: keypress, mouse click)
}

void SplashState::Update(sf::Time dt_)
{
    GameState::Update(dt_);
    


}


void SplashState::Render(sf::RenderWindow& wnd_) {
    sf::Sprite bg{ Cfg::textures.get((int)bgSpr) };
    bg.setPosition({ 0.f,0.f });
    wnd_.draw(bg);
    // Will draw splash screen elements (placeholder for now)
}
