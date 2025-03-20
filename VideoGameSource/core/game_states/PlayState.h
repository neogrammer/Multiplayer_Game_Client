#pragma once
#include "../GameState.h"
#include "PlayViewID.h"

class PlayState : public GameState {
public:


    PlayState();

    void Input() override;
    void Update(sf::Time deltaTime, Player* host_, Player* guest_) override;
    void Render(sf::RenderWindow& wnd_) override;

    // Optional: specific accessor for views
    sf::View& GetView(PlayViewID id);
};
