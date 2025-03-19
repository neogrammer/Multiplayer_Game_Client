#pragma once
#include "../GameState.h"

class SplashState : public GameState {
public:
    SplashState();

    void Input() override;
    void Update(float deltaTime) override;
    void Render() override;
};
