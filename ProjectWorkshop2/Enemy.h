#include "SDL.h"
#include "SDLGameObject.h"
#include <string>
#ifndef _Enemy_
#define _Enemy_

class Enemy : public SDLGameObject
{
	public:
	Enemy(const loadParam* pParams);
	virtual void draw();
	virtual void update();
	virtual void clean();
	virtual void setPosition();
	void setPosition(Vector2D pos){ mPosition = pos;}
	virtual std::string type(){return "Enemy";}

	private:
        int setYpos;
};
#endif
