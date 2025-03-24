#pragma once
#include "../GameState.h"
#include <core/resources/Cfg.h>

class TitleState : public GameState 
{
    Cfg::Textures bgSpr;

public:
    TitleState();
    TitleState(GameStateManager* mgr_, Player* host_, Player* guest_, sf::RenderWindow* wnd_);
    TitleState(const TitleState& o);
    TitleState& operator=(const TitleState& o);
    ~TitleState() override;
    void Input() override;
    void Update(sf::Time deltaTime) override;
    void Render(sf::RenderWindow& wnd_) override;
};
