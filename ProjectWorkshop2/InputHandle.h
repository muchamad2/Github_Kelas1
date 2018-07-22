#ifndef INPUTHANDLE_H_INCLUDED
#define INPUTHANDLE_H_INCLUDED
#include "SDL.h"
#include "vector"
#include "Vector2D.h"
#include "GameInit.h"
enum mouseButton{
    LEFT = 0,
    MIDDLE = 1,
    RIGHT = 2
};
class InputHandle
{
public:
    static InputHandle* Instance(){
        if(sInstance == 0)
            sInstance = new InputHandle();
        return sInstance;
    }
    void initialize();
    void update();
    bool isKeyDown(SDL_Scancode maped){
        if(key !=0 ){
            if(key[maped] == 1)
                return true;
            else
                return false;
        }
        return false;
    }
    void onMouseMove(SDL_Event& event);
    void onMouseButtonDown(SDL_Event& event);
    void onMouseButtonUp(SDL_Event& event);
    bool getMouseButtonState(int numberState){return mouseButtonState[numberState];}
    Vector2D* getMousePosition(){return mousePosition;}
    void clean();
private:
    InputHandle(){}
    ~InputHandle(){}
    const Uint8 *key;
    std::vector<bool> mouseButtonState;
    Vector2D* mousePosition;
    static InputHandle* sInstance;
};
typedef InputHandle Handler;

#endif // INPUTHANDLE_H_INCLUDED
