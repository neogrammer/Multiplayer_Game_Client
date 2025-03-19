#pragma once
#include "../GameState.h"

class MenuState : public GameState {
public:
    MenuState();

    void Input() override;
    void Update(float deltaTime) override;
    void Render() override;
};

