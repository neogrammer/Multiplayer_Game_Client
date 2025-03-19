#pragma once
#include "../GameState.h"

class PausedState : public GameState {
public:
    PausedState();

    void Input() override;
    void Update(float deltaTime) override;
    void Render() override;
};
