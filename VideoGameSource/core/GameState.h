#pragma once
#include <vector>
#include <SFML/Graphics/View.hpp>

class GameState {
public:
    // Pure virtual destructor makes the class abstract and polymorphic
    virtual ~GameState() = 0;

    // Required functions for all game states
    virtual void Input() = 0;
    virtual void Update(float deltaTime) = 0;
    virtual void Render() = 0;

    inline size_t GetNumViews() const { return stateViews.size(); }
    inline const std::vector<sf::View>& GetStateViews() const { return stateViews; }
protected:
    std::vector<sf::View> stateViews{};
};

// You still need to define the destructor somewhere (even if it's empty)
inline GameState::~GameState() {}