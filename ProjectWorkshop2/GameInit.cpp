#include "GameInit.h"
#include <iostream>

GameInit* GameInit::pInstance = 0;
bool GameInit::init(const char* title,int xpos,int ypos,int width,int height,int flags)
{
    if(SDL_Init(SDL_INIT_EVERYTHING)== 0)
    {
        std::cout<<"Init Success \n";
        gWindow = SDL_CreateWindow(title,xpos,ypos,width,height,flags);
        if(gWindow != 0)
        {
            std::cout<<"Window Success \n";
            gRender = SDL_CreateRenderer(gWindow,-1,0);
            if(gRender != 0)
            {
                std::cout<<"render success \n";
                SDL_SetRenderDrawColor(gRender,0,0,0,255);
                InputHandle::Instance()->initialize();
                GameStateMachine = new GStateMachine();
                GameStateMachine->changeState(new MenuState());
                gameWidth = width;
                gameHeight = height;
                lifePoint = 100;
                if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,2,2048) < 0)
                {
                    std::cout<<"Error : "<<Mix_GetError();
                }
                bgm = Mix_LoadMUS("asset/BGM.mp3");
                //sfx = Mix_LoadWAV_RW()
                Mix_PlayMusic(bgm,0);

            }
            else
                return false;
        }
    }
    else
        return false;
    mRun = true;
    return true;
}
void GameInit::update(){
    GameStateMachine->update();
}
void GameInit::render()
{
    SDL_RenderClear(gRender);
    GameStateMachine->render();
    SDL_RenderPresent(gRender);
}
void GameInit::clean()
{
    SDL_DestroyWindow(gWindow);
    SDL_DestroyRenderer(gRender);

    SDL_Quit();
}
void GameInit::handleEvent()
{
    InputHandle::Instance()->update();
    if(InputHandle::Instance()->isKeyDown(SDL_SCANCODE_RETURN))
    {
        GameStateMachine->changeState(new SelectDificult());
    }

}
