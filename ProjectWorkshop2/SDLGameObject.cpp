#include "SDLGameObject.h"
#include "TextureManager.h"
#include "GameInit.h"
SDLGameObject::SDLGameObject(const loadParam* pParams) : Object(pParams),
	mPosition(pParams->GetX(),pParams->GetY()),mVelocity(0,0),mAkselerasi(0,0)
{
    mwidth = pParams->getWidth();
    mheight = pParams->getWidth();
    mCurrentRow = 1;
    mCurrentFrame = 1;
    m_textureID = pParams->getTexture();
}
void SDLGameObject::draw()
{
	TextureManager::Instance()->drawFrame(m_textureID,(int)mPosition.getX(),
	                                      (int)mPosition.getY(),mwidth,mheight,
	                                      mCurrentRow,mCurrentFrame,Inited::Instance()->getRender());
}
void SDLGameObject::update()
{
	mVelocity = mVelocity + mAkselerasi;
	mPosition = mPosition + mVelocity;
}
void SDLGameObject::clean()
{

}
