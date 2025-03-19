#pragma once
#include <unordered_map>
#include <vector>
#include <memory>
#include <utility>
#include <stack>
#include "StateIDs.h"
#include <SFML/Graphics/RenderWindow.hpp>

class GameState;
class GameStateManager {
public:
    GameStateManager();
    ~GameStateManager() = default;

    void RegisterStates();   // Initialize all states and populate the statePool

    void PushState(StateID id);  // Push a weak_ptr onto the stateStack
    void PopState();             // Pop top state
    void ChangeState(StateID id); // Replace top state with a different one

    void Input();    // Only top state handles input
    void Update(float deltaTime); // Maybe all states update
    void Render(sf::RenderWindow& window); // All states render for layering

    bool IsEmpty() const;

private:
    std::unordered_map<StateID, std::shared_ptr<GameState>> statePool;
    std::vector<std::weak_ptr<GameState>> stateStack;

    std::shared_ptr<GameState> GetState(StateID id);
};
