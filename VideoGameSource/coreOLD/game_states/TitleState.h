#pragma once
#include "../GameState.h"
#include <core/resources/Cfg.h>
class TitleState : public GameState 
{
    Cfg::Textures bgSpr;
public:
    TitleState();
    ~TitleState() override {}
    void Input() override;
    void Update(sf::Time dt_, Player* host_, Player* guest_) override;
    void Render(sf::RenderWindow& wnd_) override;
};
