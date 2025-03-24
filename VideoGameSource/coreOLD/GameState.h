#pragma once
#include <vector>
#include <SFML/Graphics/View.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <core/StateIDs.h>

struct Player;
class GameStateManager;

class GameState {
    
public:
    GameState();
    GameState(StateID stateID_, GameStateManager* mgr, Player* host_, Player* guest_, sf::RenderWindow& wnd_);
    // Pure virtual destructor makes the class abstract and polymorphic
    virtual ~GameState() = 0;
    GameState(const GameState&);
    GameState& operator=(const GameState& o);
    bool needsToSwitchOut{ false };
    bool needsToAddOn{ false };
    StateID stateInWait{ StateID::Count};
    // Required functions for all game states
    virtual void Input() = 0;
    virtual void Update( sf::Time deltaTime) = 0;
    virtual void Render(sf::RenderWindow& wnd_) = 0;
    StateID getStateID();
    inline size_t GetNumViews() const { return stateViews.size(); }
    inline const std::vector<sf::View>& GetStateViews() const { return stateViews; }
protected:
    StateID _sid{ StateID::Splash };

    Player* host{ nullptr };
    Player* guest{ nullptr };
    GameStateManager* gStateMgr{};
    sf::Time gameTime{};
    std::vector<sf::View> stateViews{};
    Player* host{ nullptr };
    Player* guest{ nullptr };
};

// You still need to define the destructor somewhere (even if it's empty)



