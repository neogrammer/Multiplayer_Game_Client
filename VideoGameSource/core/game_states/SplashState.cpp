#include "SplashState.h"
#include <SFML/Graphics.hpp>
#include "../Globals.h"
#include <core/resources/Cfg.h>

SplashState::SplashState() 
: GameState {}
, bgSpr{Cfg::Textures::SplashBG}
{
    // Single main view for the splash screen
    stateViews.resize(1);
    stateViews[0] = sf::View(sf::FloatRect({ 0.f, 0.f }, { glb::WINW, glb::WINH })); // Example view setup
}

void SplashState::Input() {
    // Handle skip/continue inputs (ex: keypress, mouse click)
}

void SplashState::Update(sf::Time dt_, Player* host_, Player* guest_)
{
}


void SplashState::Render(sf::RenderWindow& wnd_) {
    // Will draw splash screen elements (placeholder for now)
    sf::Sprite bg{ Cfg::textures.get((int)bgSpr) };
    bg.setPosition({ 0.f,0.f });
    wnd_.draw(bg);
}
