#include "GameObject.h"


GameObject::GameObject(const loadParam* pParam) : Object(pParam),Position(pParam->GetX(),pParam->GetY()),
Velocity(0,0),Akselerasi(0,0)
{
    mWidth = pParam->getWidth();
    mHeight = pParam->getHeight();
    m_textureID = pParam->getTexture();
    mCurrentFrame = 1;
    mCurrentRaw = 1;
}
void GameObject::draw()
{
    TextureManager::Instance()->drawFrame(m_textureID,(int)Position.getX(),(int)Position.getY(),mWidth,mHeight,
                                          mCurrentRaw,mCurrentFrame,GameInit::Instance()->getRender());
}
void GameObject::clean(){
}
void GameObject::update()
{
    Velocity = Velocity + Akselerasi;
    Position = Position + Velocity;
}
