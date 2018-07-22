#ifndef TEXTUREMANAGER_H_INCLUDED
#define TEXTUREMANAGER_H_INCLUDED
#include "SDL_image.h"
#include <string>
#include <map>
#include "SDL.h"

class Manager{
public:
    bool load(std::string fileName,std::string id,SDL_Renderer* pRender);
    void draw(std::string id,int x,int y,int width,int height,SDL_Renderer* render,SDL_RendererFlip flip = SDL_FLIP_NONE);

    void drawFrame(std::string id,int x,int y,int width,int height,int currentRaw,int currentFrame,SDL_Renderer* Render,SDL_RendererFlip flip = SDL_FLIP_NONE);
    std::map<std::string,SDL_Texture*> textureMap;
    static Manager* Instance(){
        if(sInstance == 0){
            sInstance = new Manager();
            return sInstance;
        }
        return sInstance;
    }
    void clearFromTexureMap(std::string id);
private:
    Manager(){}
    ~Manager(){}
    static Manager *sInstance;
};
typedef Manager TextureManager;
#endif // TEXTUREMANAGER_H_INCLUDED
