#pragma once
#include "../GameState.h"
#include <core/resources/Cfg.h>
class GameStateMgr;
class SplashState : public GameState 
{
    Player* host;
    Player* guest;
    Cfg::Textures bgSpr;
public:
    SplashState();

    void Input() override;
    void Update(sf::Time dt_, Player* host_, Player* guest_) override;
    void Render(sf::RenderWindow& wnd_) override;
};
