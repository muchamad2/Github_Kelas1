#include "InputHandle.h"

InputHandle* InputHandle::sInstance = 0;
void InputHandle::initialize(){
    key = SDL_GetKeyboardState(NULL);
    for(int i=0;i<3;i++){
        mouseButtonState.push_back(false);
    }
}
void InputHandle::update(){
    key = SDL_GetKeyboardState(NULL);
    SDL_Event event;
    if(SDL_PollEvent(&event)){
        switch(event.type){
        case SDL_QUIT:
            Inited::Instance()->quit();
            break;
        case SDL_MOUSEMOTION:
            InputHandle::Instance()->onMouseMove(event);
            break;
        case SDL_MOUSEBUTTONDOWN:
            InputHandle::Instance()->onMouseButtonDown(event);
            break;
        case SDL_MOUSEBUTTONUP:
            InputHandle::Instance()->onMouseButtonUp(event);
            break;
        }
    }
}
void InputHandle::onMouseButtonDown(SDL_Event& event){
    if(event.button.button == SDL_BUTTON_LEFT)
        mouseButtonState[LEFT] = true;
    else if(event.button.button == SDL_BUTTON_MIDDLE)
        mouseButtonState[MIDDLE] = true;
    else if(event.button.button == SDL_BUTTON_RIGHT)
        mouseButtonState[RIGHT] = true;
}
void InputHandle::onMouseButtonUp(SDL_Event& event){
    if(event.button.button == SDL_BUTTON_LEFT)
        mouseButtonState[LEFT] = false;
    else if(event.button.button == SDL_BUTTON_MIDDLE)
        mouseButtonState[MIDDLE] = false;
    else if(event.button.button == SDL_BUTTON_RIGHT)
        mouseButtonState[RIGHT] = false;
}
void InputHandle::onMouseMove(SDL_Event& event){
    mousePosition->setX(event.motion.x);
    mousePosition->setY(event.motion.y);
}
