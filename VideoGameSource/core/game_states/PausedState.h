#pragma once
#include "../GameState.h"

class PausedState : public GameState {
public:
    PausedState();
    PausedState(GameStateManager* mgr_, Player* host_, Player* guest_, sf::RenderWindow* wnd_);
    ~PausedState() override;
   PausedState(const PausedState& o);
   PausedState& operator=(const PausedState& o);
    void Input() override;
    void Update(sf::Time dt_) override;
    void Render(sf::RenderWindow& wnd_) override;
};
