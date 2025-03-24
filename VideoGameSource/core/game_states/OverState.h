#pragma once
#include "../GameState.h"

class OverState : public GameState {
public:
    OverState();
    OverState(GameStateManager* mgr_, Player* host_, Player* guest_, sf::RenderWindow* wnd_);
    ~OverState() override;
    OverState(const OverState& o);
    OverState& operator=(const OverState& o);
    void Input() override;
    void Update(sf::Time dt_) override;
    void Render(sf::RenderWindow& wnd_) override;
};
