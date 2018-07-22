#ifndef IMAGEMANAGER_H
#define IMAGEMANAGER_H
#include "TextureManager.h"
#include "SDLGameObject.h"
class ImageManager : public Object
{
    public:
        ImageManager(const loadParam* pParams);
        virtual ~ImageManager(){}
        virtual void update(){}
        virtual void setPosition(){}
        Vector2D getPosition(){return mPosition;}
        void draw();
        void clean();
        virtual std::string type(){return "ImageContainer";}
    private:
        Vector2D mPosition;
		Vector2D mVelocity;
		Vector2D mAkselerasi;

		int mheight;
		int mwidth;
		int mCurrentFrame;
		int mCurrentRow;
		std::string m_textureID;
};

#endif // IMAGEMANAGER_H
