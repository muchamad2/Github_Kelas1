#include "Player.h"
#include "InputHandle.h"

#include <iostream>
Player::Player(const loadParam* pParams) : SDLGameObject(pParams)
{
    fireCount = 0;
}
void Player::draw()
{

	SDLGameObject::draw();

}
void Player::update()
{

	mCurrentFrame = int ((SDL_GetTicks()/100)%6);
    mVelocity.setX(0);
    mVelocity.setY(0);
    eventHandle();

	SDLGameObject::update();
}
void Player::eventHandle()
{
      if(InputHandle::Instance()->isKeyDown(SDL_SCANCODE_UP))
      {
        if(mPosition.getY() < 0)
        {
            mVelocity.setY(0);
        }
        else
        {
            mVelocity.setY(-4);
        }
      }
      else if(InputHandle::Instance()->isKeyDown(SDL_SCANCODE_RIGHT))
      {
          if(mPosition.getX() >= 700)
          {
              mVelocity.setX(0);
          }
          else{
            mVelocity.setX(4);
          }
      }

      if(InputHandle::Instance()->isKeyDown(SDL_SCANCODE_DOWN))
      {
        if(mPosition.getY() > 340)
        {
            mVelocity.setY(0);
        }
        else
        {
          mVelocity.setY(4);
        }
      }
      else if(InputHandle::Instance()->isKeyDown(SDL_SCANCODE_LEFT))
      {
          if(mPosition.getX() < 0)
          {
              mVelocity.setX(0);
          }
          else
          {
              mVelocity.setX(-4);
          }
      }





}
void Player::clean()
{}
