#include "GameStateManager.h"
#include "game_states/LoadState.h"
#include "game_states/SaveState.h"
#include "game_states/PlayState.h"
#include "game_states/OverState.h"
#include "game_states/MenuState.h"
#include "game_states/TitleState.h"
#include "game_states/SplashState.h"
#include "game_states/PausedState.h"




GameStateManager::GameStateManager()
{
    registerStates();
    ChangeState(StateID::Splash);
}

void GameStateManager::registerStates()
{
    statePool.clear();
    statePool[StateID::Splash] = std::make_shared<SplashState>();
    statePool[StateID::Title] = std::make_shared<TitleState>();
    statePool[StateID::Menu] = std::make_shared<MenuState>();
    statePool[StateID::Play] = std::make_shared<PlayState>();
    statePool[StateID::Paused] = std::make_shared<PausedState>();
    statePool[StateID::Over] = std::make_shared<OverState>();
    statePool[StateID::Save] = std::make_shared<SaveState>();
    statePool[StateID::Load] = std::make_shared<LoadState>();
}

void GameStateManager::PushState(StateID id)
{
    auto state = GetState(id);
    if (state) {
        stateStack.push_back(state);
    }
}

void GameStateManager::PopState()
{
    if (!stateStack.empty()) {
        stateStack.pop_back();
    }
}

void GameStateManager::ChangeState(StateID id)
{


    PopState();
    PushState(id);
}

void GameStateManager::Input()
{
    for (auto& st : stateStack)
    {
        st.lock()->Input();
    }
}

void GameStateManager::Update(sf::Time dt_, Player* host_, Player* guest_)
{
    for (auto& st : stateStack)
    {
        st.lock()->Update(dt_, host_, guest_);
     }
}

void GameStateManager::Render(sf::RenderWindow& window)
{
    for (auto& st : stateStack)
    {
        st.lock()->Render(window);
    }
}

bool GameStateManager::IsEmpty() const
{
    return false;
}

std::shared_ptr<GameState> GameStateManager::GetState(StateID id)
{
    auto found = statePool.find(id);
    if (found != statePool.end()) {
        return found->second;
    }
    return nullptr;
}
