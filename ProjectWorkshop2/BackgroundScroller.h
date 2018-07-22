#ifndef BACKGROUNDSCROLLER_H
#define BACKGROUNDSCROLLER_H
#include "Object.h"

class BackgroundScroller : public Object
{
    public:
        BackgroundScroller(const loadParam* pParams);
       virtual void update();
        virtual void clean();
        virtual void draw();
        Vector2D getPosition(){return mPosition;}
        virtual void setPosition(){}
        virtual std::string type(){return "backgroundScroller";}


    private:
        Vector2D mPosition;
        Vector2D mVelocity;
        int mheight;
		int mwidth;
		int mCurrentFrame;
		int mCurrentRow;
		std::string m_textureID;
        SDL_Rect srcRect1,dstRect1;
        SDL_Rect srcRect2,dstRect2;

};

#endif // BACKGROUNDSCROLLER_H
