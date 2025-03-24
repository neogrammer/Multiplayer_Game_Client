#include "GameStateManager.h"
#include "game_states/LoadState.h"
#include "game_states/SaveState.h"
#include "game_states/PlayState.h"
#include "game_states/OverState.h"
#include "game_states/MenuState.h"
#include "game_states/TitleState.h"
#include "game_states/SplashState.h"
#include "game_states/PausedState.h"




GameStateManager::GameStateManager(Player* host_, Player* guest_, sf::RenderWindow* wnd_)
{
    registerStates(host_,guest_,wnd_);
    PushState(StateID::Splash);
}

GameStateManager::GameStateManager(GameStateManager&& o)
  :   gameTime{o.gameTime}
  ,   statePool{}
  ,   stateStack{}
{

    statePool.reserve(o.statePool.size()); 
    stateStack.reserve(o.stateStack.size());

    for (auto& st : o.statePool)
    {
        statePool[st.first] = st.second;
    }

    for (auto& st : o.stateStack)
    {
        PushState(st.lock()->getStateID());
    }
      
}

GameStateManager& GameStateManager::operator=(GameStateManager&& o)
{
    gameTime = o.gameTime;
    statePool = {};
    stateStack = {  };
    statePool.reserve(o.statePool.size());
    stateStack.reserve(o.stateStack.size());

    for (auto& st : o.statePool)
    {
        statePool[st.first] = st.second;
    }

    for (auto& st : o.stateStack)
    {
        PushState(st.lock()->getStateID());
    }
    // TODO: insert return statement here

    return *this;
}

void GameStateManager::registerStates(Player* host_, Player* guest_, sf::RenderWindow* wnd_)
{
    statePool.clear();
    statePool[StateID::Splash] = std::make_shared<SplashState>(this, host_,guest_, wnd_);
    statePool[StateID::Title] = std::make_shared<TitleState>(this, host_, guest_, wnd_);
    statePool[StateID::Menu] = std::make_shared<MenuState>(this, host_, guest_, wnd_);
    statePool[StateID::Play] = std::make_shared<PlayState>(this, host_, guest_, wnd_);
    statePool[StateID::Paused] = std::make_shared<PausedState>(this, host_, guest_, wnd_);
    statePool[StateID::Over] = std::make_shared<OverState>(this, host_, guest_, wnd_);
    statePool[StateID::Save] = std::make_shared<SaveState>(this, host_, guest_, wnd_);
    statePool[StateID::Load] = std::make_shared<LoadState>(this, host_, guest_, wnd_);
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

void GameStateManager::Update(sf::Time dt_)
{
gameTime = dt_;

    if (stateStack.back().lock()->stateInWait != StateID::Count)
    {
        if (stateStack.back().lock()->needsToSwitchOut)
        {
            auto state = stateStack.back().lock()->stateInWait;
            stateStack.back().lock()->stateInWait = StateID::Count;
            stateStack.back().lock()->needsToSwitchOut = false;
            stateStack.back().lock()->needsToAddOn = false;
            ChangeState(state);
        }
        else
        {
            if (stateStack.back().lock()->needsToAddOn)
            {
                auto& state = stateStack.back().lock()->stateInWait;
                stateStack.back().lock()->stateInWait = StateID::Count;
                stateStack.back().lock()->needsToSwitchOut = false;
                stateStack.back().lock()->needsToAddOn = false;
                PushState(state);
            }
        }
    }

    for (auto& st : stateStack)
    {
        st.lock()->Update(dt_);
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
