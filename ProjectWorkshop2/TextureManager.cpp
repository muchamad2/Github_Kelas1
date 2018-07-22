#include "TextureManager.h"

Manager* Manager::sInstance = 0;

bool Manager::load(std::string fileName,std::string id,SDL_Renderer* render){
    SDL_Surface* tempSurf = IMG_Load(fileName.c_str());
    if(tempSurf == 0)
        return false;
    SDL_Texture* Texture =  SDL_CreateTextureFromSurface(render,tempSurf);
    SDL_FreeSurface(tempSurf);
    if(Texture != 0){
        textureMap[id]= Texture;
        return true;
    }
    return false;
}
void TextureManager::draw(std::string id,int x,int y, int width, int height,SDL_Renderer* render,SDL_RendererFlip flip){
    SDL_Rect srcRect;
    SDL_Rect dstRect;

    srcRect.x = 0;
    srcRect.y = 0;
    srcRect.w = dstRect.w = width;
    srcRect.h = dstRect.h = height;
    dstRect.x = x;
    dstRect.y = y;

    SDL_RenderCopyEx(render,textureMap[id],&srcRect,&dstRect,0,0,flip);
}
void TextureManager::drawFrame(std::string id,int x,int y,int width,int height,int currentRaw,int currentFrame,SDL_Renderer* render,
                               SDL_RendererFlip flip)
                               {
    SDL_Rect srcRect;
    SDL_Rect dstRect;

    srcRect.x = width*currentFrame;
    srcRect.y = height *(currentRaw-1);
    srcRect.w = dstRect.w = width;
    srcRect.h = dstRect.h = height;
    dstRect.x = x;
    dstRect.y = y;

    SDL_RenderCopyEx(render,textureMap[id],&srcRect,&dstRect,0,0,flip);
                               }
void TextureManager::clearFromTexureMap(std::string id){
    textureMap.erase(id);
}
