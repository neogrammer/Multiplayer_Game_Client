#pragma once
#include "../GameState.h"

class SaveState : public GameState {
public:
    SaveState();

    void Input() override;
    void Update(float deltaTime) override;
    void Render() override;
};
