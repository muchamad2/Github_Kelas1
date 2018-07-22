#ifndef GAMEINIT_H_INCLUDED
#define GAMEINIT_H_INCLUDED
#include "SDL.h"
#include "SDL_mixer.h"
#include <vector>
#include "SDL_image.h"
#include "Object.h"
#include "InputHandle.h"
#include "MenuState.h"
#include "PlayState.h"
#include "SelectDificult.h"
#include "TextureManager.h"
#include "GStateMachine.h"
class GameInit{
public:
    bool init(const char* title,int xpos,int ypos,int width,int height,int flag);
    void update();
    void handleEvent();
    void clean();
    void render();
    bool running(){
        return mRun;
    }
    static GameInit* Instance(){
        if(pInstance == 0)
        {
            pInstance = new GameInit();
            return pInstance;
        }
        return pInstance;
    }
    SDL_Renderer* getRender() const {
        return gRender;
    }
    void quit(){
        mRun = false;
    }
    int getGameWidth(){return gameWidth;}
    int getGameHeight(){return gameHeight;}
    GStateMachine* getStateMachine() {return GameStateMachine; }
    void setEnemySpeed(float speed){enemySpeed = speed;}
    float getEnemySpeed(){return enemySpeed;}
    int& getLeftPoint(){return lifePoint;}
private:
    bool mRun;
    GameInit(){}
    static GameInit* pInstance;
    SDL_Window* gWindow;
    SDL_Renderer* gRender;
    Object* mPlayer;
    std::vector<Object*> objects;
    GStateMachine* GameStateMachine;
    int gameWidth;
    int gameHeight;
    float enemySpeed;
    int lifePoint;
    Mix_Music *bgm;
    Mix_Chunk *sfx;

};
typedef GameInit Inited;
#endif // GAMEINIT_H_INCLUDED
