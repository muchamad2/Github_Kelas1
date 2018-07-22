#include "Bullet.h"
#include "InputHandle.h"
Bullet::Bullet(const loadParam* pParams,Vector2D heading) : SDLGameObject(pParams),mHeading(heading)
{

}
void Bullet::draw()
{
	SDLGameObject::draw();

}
void Bullet::update()
{

	mCurrentFrame = int ((SDL_GetTicks()/100)%1);
    mVelocity.setX(mHeading.getX());
    mVelocity.setY(mHeading.getY());


	SDLGameObject::update();
}

void Bullet::clean()
{}
