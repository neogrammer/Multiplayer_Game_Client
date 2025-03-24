#pragma once
#include "../GameState.h"
#include <core/resources/Cfg.h>


class SplashState : public GameState 
{
    
    Cfg::Textures bgSpr;

public:
    SplashState();
    ~SplashState() override;
    SplashState(GameStateManager* mgr_, Player* host_, Player* guest_, sf::RenderWindow* wnd_);
    SplashState(const SplashState& o);
    SplashState& operator=(const SplashState& o);

    void Input() override;
    void Update(sf::Time dt_) override;
    void Render(sf::RenderWindow& wnd_) override;
};
