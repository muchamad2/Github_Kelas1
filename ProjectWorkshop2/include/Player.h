#ifndef PLAYER_H
#define PLAYER_H

#include "../GameObject.h"


class Player : public GameObject
{
    public:
        Player(const loadParam *Params);
        virtual void draw();
        virtual void update();
        virtual void clean();
        virtual void inputEvent();


};

#endif // PLAYER_H
