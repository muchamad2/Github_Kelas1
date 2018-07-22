#ifndef SELECTDIFICULT_H
#define SELECTDIFICULT_H

#include "GameState.h"
#include "TextureManager.h"
#include "GameInit.h"
#include "MenuButton.h"
class SelectDificult : public GameState
{
    public:
        virtual void update();
        virtual void render();
        virtual bool onEnter();
        virtual bool onExit();

        virtual std::string getStateID() const {return SelectID;}

    private:
        static const std::string SelectID;
        std::vector<Object*> menuObjects;
        static void menuToPlay();
        static void exitFromMenu();
};

#endif // SELECTDIFICULT_H
