#pragma once
#include "../GameState.h"
#include "PlayViewID.h"


#include <entities/PlayerSprite.h>

class PlayState : public GameState {
public:
    sf::Texture idle{ "Assets/Textures/Knight_player/Idle_KG_2.png" };
    sf::Texture walk{ "Assets/Textures/Knight_player/Walking_KG_2.png" };
    PlayerSprite* player;

    PlayState();
    PlayState(GameStateManager* mgr_, Player* host_, Player* guest_, sf::RenderWindow* wnd_);
    ~PlayState() override;
    PlayState(const PlayState& o);
    PlayState& operator=(const PlayState& o);
    void Input() override;
    void Update(sf::Time dt_) override;
    void Render(sf::RenderWindow& wnd_) override;

    // Optional: specific accessor for views
    sf::View& GetView(PlayViewID id);
};
