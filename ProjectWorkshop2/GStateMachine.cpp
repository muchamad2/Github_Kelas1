#include "GStateMachine.h"

void GStateMachine::pushState(GameState* tState)
{
    gameStates.push_back(tState);
    gameStates.back()->onEnter();
}
void GStateMachine::popState()
{
    if(!gameStates.empty())
    {
        if(gameStates.back()->onExit())
        {
            delete gameStates.back();
            gameStates.pop_back();
        }
    }
}
void GStateMachine::changeState(GameState* tState)
{
    if(!gameStates.empty())
    {
        if(gameStates.back()->getStateID() == tState->getStateID())
        {
            return;
        }
        if(gameStates.back()->onExit())
        {
            delete gameStates.back();
            gameStates.pop_back();
        }
    }
    gameStates.push_back(tState);
    gameStates.back()->onEnter();
}
void GStateMachine::update()
{
    if(!gameStates.empty())
    {
        gameStates.back()->update();
    }
}
void GStateMachine::render()
{
    if(!gameStates.empty()){
        gameStates.back()->render();
    }
}
