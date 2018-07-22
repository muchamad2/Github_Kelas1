#include "MenuState.h"
#include "TextureManager.h"
#include "GameInit.h"
#include "PlayState.h"
#include "MenuButton.h"
#include "GStateMachine.h"
#include "ImageManager.h"
const std::string MenuState::menuID = "MENU";

void MenuState::update()
{
    for(std::vector<Object*>::size_type i=0; i < menuObjects.size(); i++)
    {
        menuObjects[i]->update();
    }
}
void MenuState::render()
{
    for(std::vector<Object*>::size_type i=0; i < menuObjects.size(); i++)
    {
        menuObjects[i]->draw();
    }
    TextureManager::Instance()->draw("mainmenu",0,0,800,400,Inited::Instance()->getRender());
}
bool MenuState::onEnter()
{
    if(!TextureManager::Instance()->load("asset/MainMenu.png","mainmenu",GameInit::Instance()->getRender()))
    {
        return false;
    }
    Object* selectMenu = new MenuButton(new loadParam(0,100,25,25,"mainmenu"),menuToPlay);
    menuObjects.push_back(selectMenu);
    return true;
}
bool MenuState::onExit()
{
    for(std::vector<Object*>::size_type i=0; i < menuObjects.size(); i++)
    {
        menuObjects[i]->clean();
    }
    menuObjects.clear();
    TextureManager::Instance()->clearFromTexureMap("playButton");
    TextureManager::Instance()->clearFromTexureMap("exitButton");

    return true;
}
void MenuState::menuToPlay(){

    GameInit::Instance()->getStateMachine()->changeState(new SelectDificult());
}
void MenuState::exitFromMenu()
{
    Inited::Instance()->quit();
}
