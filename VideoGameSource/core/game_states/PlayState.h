#pragma once
#include "../GameState.h"
#include "PlayViewID.h"

class PlayState : public GameState {
public:
    PlayState();

    void Input() override;
    void Update(float deltaTime) override;
    void Render() override;

    // Optional: specific accessor for views
    sf::View& GetView(PlayViewID id);
};
