#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include "Object.h"
#include "Vector2D.h"
#include "TextureManager.h"
#include "GameInit.h"

class GameObject : public Object
{
public:
    GameObject(const loadParam* Params);
    virtual void draw();
    virtual void update();
    virtual void clean();
protected :
    Vector2D Position;
    Vector2D Velocity;
    Vector2D Akselerasi;

    int mHeight;
    int mWidth;
    int mCurrentFrame;
    int mCurrentRaw;
    std::string m_textureID;
};
#endif // GAMEOBJECT_H_INCLUDED
