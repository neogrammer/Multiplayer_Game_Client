#include "MenuState.h"
#include <SFML/Graphics.hpp>
#include "../Globals.h"

MenuState::MenuState() {
    // Single main view for the splash screen
    stateViews.resize(1);
    stateViews[0] = sf::View(sf::FloatRect({ 0.f, 0.f }, { glb::WINW, glb::WINH })); // Example view setup
}

void MenuState::Input() {
    // Handle skip/continue inputs (ex: keypress, mouse click)
}

void MenuState::Update(sf::Time dt_, Player* host_, Player* guest_)
{
}
void MenuState::Render(sf::RenderWindow& wnd_) {
    // Will draw splash screen elements (placeholder for now)
}
