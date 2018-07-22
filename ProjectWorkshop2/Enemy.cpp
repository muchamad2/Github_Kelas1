#include "Enemy.h"
#include "GameInit.h"
#include "stdlib.h"

Enemy::Enemy(const loadParam* pParams) : SDLGameObject(pParams)
{
    mVelocity.setX(2);

}
void Enemy::draw()
{
	SDLGameObject::draw();
}
void Enemy::update()
{
	mCurrentFrame = int((SDL_GetTicks()/100)%4);
	if(mPosition.getX() > 0)
        mVelocity.setX(-10*Inited::Instance()->getEnemySpeed());
    if(mPosition.getX() < -100 )
    {
        int addXPos[3] = {900, 1000, 950};
        int randomX = 0 + (rand()%static_cast<int>(3-0+1));
        mPosition.setX(addXPos[randomX]);
        int randomY = 0 + (rand()%static_cast<int>(350-0+1));
        mPosition.setY(randomY);
    }

   SDLGameObject::update();
}
void Enemy::setPosition(){
    int addXPos[3] = {900, 1000, 950};
    int randomX = 0 + (rand()%static_cast<int>(3-0+1));
    mPosition.setX(addXPos[randomX]);
    int randomY = 0 + (rand()%static_cast<int>(350-0+1));
    mPosition.setY(randomY);
}

void Enemy::clean()
{}
