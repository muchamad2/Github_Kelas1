#include "SelectDificult.h"
const std::string SelectDificult::SelectID = "SELECTLEVEL";
void SelectDificult::update()
{
   /* for(std::vector<Object*>::size_type i=0; i < menuObjects.size(); i++)
    {
        menuObjects[i]->update();
    }*/
    if(InputHandle::Instance()->isKeyDown(SDL_SCANCODE_1))
    {
        Inited::Instance()->getStateMachine()->changeState(new PlayState());
        Inited::Instance()->setEnemySpeed(0.5f);
    }
    else if(InputHandle::Instance()->isKeyDown(SDL_SCANCODE_2))
    {
        Inited::Instance()->getStateMachine()->changeState(new PlayState());
        Inited::Instance()->setEnemySpeed(0.7f);
    }

    else if(InputHandle::Instance()->isKeyDown(SDL_SCANCODE_3))
    {
        Inited::Instance()->getStateMachine()->changeState(new PlayState());
        Inited::Instance()->setEnemySpeed(1.0f);
    }
}
void SelectDificult::render()
{
    TextureManager::Instance()->draw("level",0,0,800,400,Inited::Instance()->getRender());
    for(std::vector<Object*>::size_type i=0; i < menuObjects.size(); i++)
    {
        menuObjects[i]->draw();
    }
}
bool SelectDificult::onEnter()
{
    if(!TextureManager::Instance()->load("asset/LevelSprite.png","level",GameInit::Instance()->getRender()))
    {
        return false;
    }
   // Object* selectMenu = new MenuButton(new loadParam(0,100,25,25,"mainmenu"),menuToPlay);
   // menuObjects.push_back(selectMenu);
    return true;
}
bool SelectDificult::onExit()
{
    for(std::vector<Object*>::size_type i=0; i < menuObjects.size(); i++)
    {
        menuObjects[i]->clean();
    }
    menuObjects.clear();
    TextureManager::Instance()->clearFromTexureMap("mainmenu");
    //TextureManager::Instance()->clearFromTexureMap("exitButton");

    return true;
}
void SelectDificult::menuToPlay(){

    GameInit::Instance()->getStateMachine()->changeState(new PlayState());
}
void SelectDificult::exitFromMenu()
{
    Inited::Instance()->quit();
}
