#pragma once
#include "../GameState.h"

class TitleState : public GameState {
public:
    TitleState();

    void Input() override;
    void Update(float deltaTime) override;
    void Render() override;
};
