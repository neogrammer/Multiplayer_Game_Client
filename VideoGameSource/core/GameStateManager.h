#pragma once
#include <unordered_map>
#include <vector>
#include <memory>
#include <utility>
#include <stack>
#include "StateIDs.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Time.hpp>
#include <entities/Player.h>


class GameState;
class GameStateManager {
public:
    GameStateManager();
    ~GameStateManager() = default;



    void PushState(StateID id);  // Push a weak_ptr onto the stateStack
    void PopState();             // Pop top state
    void ChangeState(StateID id); // Replace top state with a different one

    void Input();    // Only top state handles input
    void Update(sf::Time dt_, Player* host_, Player* guest_); // Maybe all states update
    void Render(sf::RenderWindow& window); // All states render for layering

    bool IsEmpty() const;

private:
    std::unordered_map<StateID, std::shared_ptr<GameState>> statePool;
    std::vector<std::weak_ptr<GameState>> stateStack;

    std::shared_ptr<GameState> GetState(StateID id);
    void registerStates();   // Initialize all states and populate the statePool
};
