#include "ImageManager.h"
#include "GameInit.h"
ImageManager::ImageManager(const loadParam* pParams) : Object(pParams),mVelocity(0,0),mPosition(pParams->GetX(),pParams->GetY()),
mAkselerasi(0,0)

{
    mwidth = pParams->getWidth();
    mheight = pParams->getWidth();
    mCurrentRow = 1;
    mCurrentFrame = 1;
    m_textureID = pParams->getTexture();
}
void ImageManager::draw()
{
    TextureManager::Instance()->drawFrame(m_textureID,(int)mPosition.getX(),
                                    (int)mPosition.getY(),mwidth,mheight,
	                                      mCurrentRow,mCurrentFrame,Inited::Instance()->getRender());
}
void ImageManager::clean()
{

}
