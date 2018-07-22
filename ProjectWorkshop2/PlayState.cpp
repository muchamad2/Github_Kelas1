#include "PlayState.h"

#include <iostream>
#include "BackgroundScroller.h"
const std::string PlayState::playID = "PLAY";


void PlayState::update()
{
    for(std::vector<Object*>::size_type i=0; i < gameObjects.size();i++)
    {
        if(gameObjects[i]->getPosition().getX() < 0 - offScreen_Buffer || gameObjects[i]->getPosition().getX() > 5000 + offScreen_Buffer)
           {
               gameObjects[i]->getPosition();
           }
           else
           {
               gameObjects[i]->update();
           }

    }
    for(std::vector<Object*>::size_type i=0; i < gameObjects.size()-1;i++)
    {
        if(checkCollision(dynamic_cast<SDLGameObject*>(gameObjects[0]),dynamic_cast<SDLGameObject*>(gameObjects[i+1])))
        {
            gameObjects[i+1]->setPosition();
            Lpoint = Lpoint - 1;
            std::cout<<Lpoint;
            //Mix_PlayChannel(1,)

        }
    }

}
void PlayState::render()
{
    TextureManager::Instance()->draw("background",0,0,1600,400,Inited::Instance()->getRender());
    for(std::vector<Object*>::size_type i=0; i < gameObjects.size(); i++)
    {
        gameObjects[i]->draw();
    }

}
bool PlayState::onEnter()
{
    if(!TextureManager::Instance()->load("asset/PlayerSprite.png","charPlay",Inited::Instance()->getRender()))
        return false;
    if(!TextureManager::Instance()->load("asset/MeteorSprite.png","meteor1",Inited::Instance()->getRender()))
        return false;
    if(!TextureManager::Instance()->load("asset/MeteorSprite2.png","meteor2",Inited::Instance()->getRender()))
        return false;
    if(!TextureManager::Instance()->load("asset/BackgroundSprite.png","background",Inited::Instance()->getRender()))
        return false;

    Object* player = new Player(new loadParam(0,200,64,27,"charPlay"));
    Enemy * enemy = new Enemy(new loadParam(800,0,64,64,"meteor1"));
    Enemy * enemy1 = new Enemy(new loadParam(1000,200,64,64,"meteor2"));
    Enemy * enemy2 = new Enemy(new loadParam(900,100,64,64,"meteor1"));
    Enemy * enemy3 = new Enemy(new loadParam(1100,350,64,64,"meteor2"));
    gameObjects.push_back(player);
    gameObjects.push_back(enemy);
    gameObjects.push_back(enemy1);
    gameObjects.push_back(enemy2);
    gameObjects.push_back(enemy3);
    Lpoint = Inited::Instance()->getLeftPoint();

    return true;
}
bool PlayState::onExit()
{
    for(std::vector<Object*>::size_type i=0;i<gameObjects.size();i++)
    {
        gameObjects[i]->clean();
    }
    gameObjects.clear();
    TextureManager::Instance()->clearFromTexureMap("charPlay");
    return true;
}
