#ifndef MENUSTATE_H
#define MENUSTATE_H

#include "GameState.h"
#include <vector>
#include "Object.h"
class MenuState : public GameState
{
    public:
        virtual void update();
        virtual void render();
        virtual bool onEnter();
        virtual bool onExit();

        virtual std::string getStateID() const {return menuID;}

    private:
        static const std::string menuID;
        std::vector<Object*> menuObjects;
        static void menuToPlay();
        static void exitFromMenu();

};

#endif // MENUSTATE_H
