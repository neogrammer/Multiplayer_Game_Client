#pragma once
#include "../GameState.h"

class MenuState : public GameState {
public:


    MenuState();

    void Input() override;
    void Update(sf::Time dt_, Player* host_, Player* guest_) override;
    void Render(sf::RenderWindow& wnd_) override;
};

