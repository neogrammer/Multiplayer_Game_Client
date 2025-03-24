#pragma once
#include "../GameState.h"

class MenuState : public GameState {
public:


    MenuState();
    MenuState(GameStateManager* mgr_, Player* host_, Player* guest_, sf::RenderWindow* wnd_);
    ~MenuState() override;
    MenuState(const MenuState& o);
    MenuState& operator=(const MenuState& o);
    void Input() override;
    void Update(sf::Time dt_) override;
    void Render(sf::RenderWindow& wnd_) override;
};

