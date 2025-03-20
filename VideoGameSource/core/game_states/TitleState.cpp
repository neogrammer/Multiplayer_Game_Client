#include "TitleState.h"
#include "../Globals.h"

TitleState::TitleState() : GameState{}, bgSpr{ Cfg::Textures::TitleBG } {
    stateViews.resize(1);
    stateViews[0] = sf::View(sf::FloatRect({ 0.f, 0.f }, { glb::WINW, glb::WINH })); // Example view setup
}

void TitleState::Input() {
    // Start game, options, etc.
}

void TitleState::Update(sf::Time dt_, Player* host_, Player* guest_)
{
}

void TitleState::Render(sf::RenderWindow& wnd_) {
    sf::Sprite bg{ Cfg::textures.get((int)bgSpr) };
    bg.setPosition({ 0.f,0.f });
    wnd_.draw(bg);
    // Draw the title screen logo, buttons
}
