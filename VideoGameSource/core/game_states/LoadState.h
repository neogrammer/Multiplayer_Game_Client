#pragma once
#include "../GameState.h"

class LoadState : public GameState {
public:
    LoadState();

    void Input() override;
    void Update(float deltaTime) override;
    void Render() override;
};
