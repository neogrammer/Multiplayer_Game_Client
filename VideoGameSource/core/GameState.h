#pragma once
#include <vector>
#include <SFML/Graphics/View.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

struct Player;

class GameState {
    
public:
    GameState() = default;
    // Pure virtual destructor makes the class abstract and polymorphic
    virtual ~GameState() = 0;
    GameState(const GameState& o);
    GameState& operator=(const GameState& o);

    // Required functions for all game states
    virtual void Input() = 0;
    virtual void Update( sf::Time deltaTime, Player* host_, Player* guest_) = 0;
    virtual void Render(sf::RenderWindow& wnd_) = 0;

    inline size_t GetNumViews() const { return stateViews.size(); }
    inline const std::vector<sf::View>& GetStateViews() const { return stateViews; }
protected:
    std::vector<sf::View> stateViews{};
    Player* host{ nullptr };
    Player* guest{ nullptr };
};

// You still need to define the destructor somewhere (even if it's empty)



