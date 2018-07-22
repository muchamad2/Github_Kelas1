#include "GameInit.h"

using namespace std;
const int fps = 60;
const int delayTime = 1000.0f/fps;
int main(int argc, char* argv[])
{
    Uint32 frameStart, frameTime;
    if(Inited::Instance()->init("Game Shooter",50,20,800,400,false)){
        while(Inited::Instance()->running()){
            frameStart = SDL_GetTicks();
            Inited::Instance()->render();
            Inited::Instance()->update();
            Inited::Instance()->handleEvent();
            frameTime = SDL_GetTicks() - frameStart;
            if(frameTime < delayTime)
                SDL_Delay((int)(delayTime - frameTime));
        }
    }
    else{
        return -1;
    }
    Inited::Instance()->clean();
    return 0;
}
