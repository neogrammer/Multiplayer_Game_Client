#include "LoadState.h"
#include <SFML/Graphics/Rect.hpp>
#include "../Globals.h"
LoadState::LoadState() {
    // Single main view for the splash screen
    stateViews.resize(1);
    stateViews[0] = sf::View(sf::FloatRect({ 0.f, 0.f }, { glb::WINW, glb::WINH})); // Example view setup
}

void LoadState::Input() {
    // Handle skip/continue inputs (ex: keypress, mouse click)
}

void LoadState::Update(float deltaTime) {
    // Timer or animation updates here
}

void LoadState::Render() {
    // Will draw splash screen elements (placeholder for now)
}
