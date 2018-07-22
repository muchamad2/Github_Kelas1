#ifndef OBJECT_H
#define OBJECT_H
#include "SDL.h"
#include "LoadParams.h"
#include "Vector2D.h"
class Object{

public:
    virtual ~Object(){}
    virtual void draw() = 0;
    virtual void update() = 0;
    virtual void clean() = 0;
    virtual Vector2D getPosition() = 0;
    virtual void setPosition() = 0;
    //    virtual void collision() = 0;
    virtual std::string type() = 0;

protected :
    Object(const loadParam* pParams){}




};

#endif // OBJECT_H_INCLUDED
