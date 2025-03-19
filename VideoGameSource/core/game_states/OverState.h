#pragma once
#include "../GameState.h"

class OverState : public GameState {
public:
    OverState();

    void Input() override;
    void Update(float deltaTime) override;
    void Render() override;
};
