#ifndef PLAYSTATE_H
#define PLAYSTATE_H

#include "GameState.h"
#include <vector>
#include "Object.h"
#include "SDLGameObject.h"
#include "TextureManager.h"
#include "GameInit.h"
#include "Enemy.h"
#include "Player.h"

class PlayState : public GameState
{
    public:
        virtual void update();
        virtual void render();

        virtual bool onEnter();
        virtual bool onExit();

        virtual std::string getStateID() const {return playID;}

        bool checkCollision(SDLGameObject* p1,SDLGameObject* p2)
        {
            int leftA,leftB;
            int rightA,rightB;
            int buttomA,buttomB;
            int topA,topB;
            leftA = p1->getPosition().getX();
            rightA = p1->getPosition().getX() + p1->getWidth();
            topA = p1->getPosition().getY();
            buttomA = p1->getPosition().getY() + p1->getHeight();

            leftB = p2->getPosition().getX();
            rightB = p2->getPosition().getX() + p2->getWidth();
            topB = p2->getPosition().getY();
            buttomB = p2->getPosition().getY() + p2->getHeight();

            if(buttomA <= topB){return false;}
            if(topA >= buttomB){return false;}
            if(rightA <= leftB){return false;}
            if(leftA >= rightB){return false;}

            return true;

        }
    private:
        static const std::string playID;
        std::vector<Object*> gameObjects;
        std::vector<Object*> arrayOfBullet;
        int offScreen_Buffer = 500;
        Player* p;

        int Lpoint;
        bool active;

};

#endif // PLAYSTATE_H
