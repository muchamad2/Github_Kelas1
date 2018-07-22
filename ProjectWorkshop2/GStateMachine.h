#ifndef GSTATEMACHINE_H
#define GSTATEMACHINE_H
#include "GameState.h"
#include <vector>
class GStateMachine
{
    public:
        void pushState(GameState* pState);
        void changeState(GameState* pState);
        void popState();
        void update();
        void render();
    private:
        std::vector<GameState*> gameStates;
};

#endif // GSTATEMACHINE_H
