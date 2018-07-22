#include "BulletManager.h"
BulletManager* BulletManager::pinstance = NULL;
void BulletManager::addBulet(int x,int y,int width,int height,std::string textureID,Vector2D heading)
{
    pBullet = new Bullet(new loadParam(x,y,width,height,textureID),heading);
    mBullets.push_back(pBullet);
}
void BulletManager::setBulletPosition(float x,float y)
{
    bX = x;
    bY = y;
}
