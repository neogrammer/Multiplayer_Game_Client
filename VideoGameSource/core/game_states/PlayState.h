#pragma once
#include "../GameState.h"
#include "PlayViewID.h"

class PlayState : public GameState {
public:


    PlayState();
    PlayState(GameStateManager* mgr_, Player* host_, Player* guest_, sf::RenderWindow* wnd_);
    ~PlayState() override;
    PlayState(const PlayState& o);
    PlayState& operator=(const PlayState& o);
    void Input() override;
    void Update(sf::Time dt_) override;
    void Render(sf::RenderWindow& wnd_) override;

    // Optional: specific accessor for views
    sf::View& GetView(PlayViewID id);
};
