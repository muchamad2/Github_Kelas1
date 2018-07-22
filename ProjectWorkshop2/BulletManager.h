#ifndef BULLETMANAGER_H
#define BULLETMANAGER_H
#include "Bullet.h"
#include "SDLGameObject.h"
#include <vector>
#include "Vector2D.h"
//#include "Player.h"
class BulletManager
{
private:
    std::vector<Bullet*> mBullets;
    Bullet* pBullet;
    float bX;
    float bY;
    BulletManager(){}
    bool active;
    static BulletManager* pinstance;
public:

    void addBulet(int x,int y,int width,int height,std::string textureID,Vector2D heading);
    void update();
    static BulletManager* Instance(){
        if(pinstance == 0){
            pinstance = new BulletManager;
            return pinstance;
        }
        return pinstance;
    }
    Bullet* getObject(){return pBullet;}
    void activeFire(bool act){active = act;}
    bool getActive(){return active;}
    void setBulletPosition(float x,float y);
    float getBX(){return bX;}
    float getBY() {return bY;}
};


#endif // BULLETMANAGER_H
