#pragma once
#include "../GameState.h"

class SaveState : public GameState {
public:
    SaveState();
    SaveState(GameStateManager* mgr_, Player* host_, Player* guest_, sf::RenderWindow* wnd_);
    ~SaveState() override;
    SaveState(const SaveState& o);
    SaveState& operator=(const SaveState& o);
    void Input() override;
    void Update(sf::Time dt_) override;
    void Render(sf::RenderWindow& wnd_) override;
};
