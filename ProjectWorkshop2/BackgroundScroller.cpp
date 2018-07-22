#include "BackgroundScroller.h"
#include "TextureManager.h"
#include "GameInit.h"
BackgroundScroller::BackgroundScroller(const loadParam* pParams) : Object(pParams),mPosition(pParams->GetX(),pParams->GetY()),mVelocity(-1,0)
{
    mwidth = pParams->getWidth();
    mheight = pParams->getWidth();
    mCurrentRow = 1;
    mCurrentFrame = 1;
    m_textureID = pParams->getTexture();
}
void BackgroundScroller::draw()
{
    TextureManager::Instance()->drawFrame(m_textureID,(int)mPosition.getX(),
	                                      (int)mPosition.getY(),mwidth,mheight,
	                                      mCurrentRow,mCurrentFrame,Inited::Instance()->getRender());
}
void BackgroundScroller::update()
{

}
void BackgroundScroller::clean()
{

}
