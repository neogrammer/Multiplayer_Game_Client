#include "PlayState.h"
#include "../Globals.h"

PlayState::PlayState() {
    stateViews.resize(static_cast<size_t>(PlayViewID::Count));

    // Initialize each view with appropriate sizes and centers
    stateViews[static_cast<size_t>(PlayViewID::FarBG)] = sf::View(sf::FloatRect({ 0.f, 0.f }, { glb::WINW, glb::WINH })); // Example view setup
    stateViews[static_cast<size_t>(PlayViewID::MidBG)] = sf::View(sf::FloatRect({ 0.f, 0.f }, { glb::WINW, glb::WINH })); // Example view setup
    // ... Initialize remaining views
}

void PlayState::Input() {
    // Player controls, attacks, etc.
}

void PlayState::Update(sf::Time deltaTime, Player* host_, Player* guest_)
{
}

void PlayState::Render(sf::RenderWindow& wnd_) {
    // Draw backgrounds, players, effects, HUD layer by layer
}

sf::View& PlayState::GetView(PlayViewID id)
{
    return stateViews.at((size_t)id);
}
