#ifndef MENUBUTTON_H
#define MENUBUTTON_H

#include "SDLGameObject.h"


class MenuButton : public SDLGameObject
{
    public:
        MenuButton(const loadParam* pParams,void (*m_callback)());
        virtual void draw();
        virtual void update();
        virtual void clean();
        virtual void setPosition(){}
        virtual std::string type() {return "MenuButton";}
    private:
        enum buttonState{
            MOUSEOUT = 0,
            MOUSEOVER = 1,
            CLICKED = 2
        };
        void (*callback)();
        bool released;
};

#endif // MENUBUTTON_H
