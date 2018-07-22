#ifndef BULLET_H
#define BULLET_H

#include "SDLGameObject.h"
//#include <string>
#include "Vector2D.h"

class Bullet : public SDLGameObject
{
	public:
	Bullet(const loadParam* pParams,Vector2D heading);
	virtual void draw();
	virtual void update();
	virtual void clean();
	virtual void setPosition(){}

	virtual std::string type() {return "Bullet";}
	private:
        Vector2D mHeading;

};

#endif // BULLET_H
