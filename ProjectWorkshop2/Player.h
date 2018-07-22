
#ifndef _Player_
#define _Player_
#include "SDLGameObject.h"
#include <vector>

class Player : public SDLGameObject
{
	public:
	Player(const loadParam* pParams);
	virtual void draw();
	virtual void update();
	virtual void clean();
	virtual void eventHandle();
	virtual void setPosition(){}
    virtual Vector2D& getPPosition(){return mPosition;}
    virtual std::string type() {return "PLAYER";}
	private:
        std::vector<Object*> bullets;
        bool release;
        int fireCount;

};
#endif

