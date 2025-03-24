#pragma once
#include "../GameState.h"

class LoadState : public GameState {
public:
    LoadState();
    LoadState(GameStateManager* mgr_, Player* host_, Player* guest_, sf::RenderWindow* wnd_);
    ~LoadState() override;
    LoadState(const LoadState& o);
    LoadState& operator=(const LoadState& o);
    void Input() override;
    void Update(sf::Time dt_) override;
    void Render(sf::RenderWindow& wnd_) override;
};
