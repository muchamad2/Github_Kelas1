#include "MenuButton.h"
#include "InputHandle.h"
MenuButton::MenuButton(const loadParam* pParams, void (*m_callback)()) : SDLGameObject(pParams), callback(m_callback)
{
    mCurrentFrame = MOUSEOUT;
}
void MenuButton::draw()
{
    SDLGameObject::draw();
}
void MenuButton::update()
{
    Vector2D* mousePos = InputHandle::Instance()->getMousePosition();
    if(mousePos->getX() < (mPosition.getX() + mwidth)&&mousePos->getX()>mPosition.getX()
       && mousePos->getY() < (mPosition.getY() + mheight)&& mousePos->getY() > mPosition.getY())
    {
        mCurrentFrame = MOUSEOVER;
        if(InputHandle::Instance()->getMouseButtonState(LEFT))
        {
            mCurrentFrame = CLICKED;
            callback();
        }
    }
    else{
        mCurrentFrame = MOUSEOUT;
    }
    if(InputHandle::Instance()->isKeyDown(SDL_SCANCODE_1))
    {
        callback();
    }
}
void MenuButton::clean()
{
    SDLGameObject::clean();
}
