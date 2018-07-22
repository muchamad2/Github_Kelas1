#ifndef _SDLGAMEOBJECT_
#define _SDLGAMEOBJECT_

#include "Object.h"
#include "Vector2D.h"

class SDLGameObject : public Object
{
	public:
		SDLGameObject(const loadParam* pParams);
		virtual void draw();
		virtual void update();
		virtual void clean();
		Vector2D getPosition(){return mPosition;}
		int getWidth(){return mwidth;}
		int getHeight() {return mheight;}
		virtual void setPosition(){}

		virtual std::string type() {return "SDLGameObject";}

	protected:
		Vector2D mPosition;
		Vector2D mVelocity;
		Vector2D mAkselerasi;

		int mheight;
		int mwidth;
		int mCurrentFrame;
		int mCurrentRow;
		std::string m_textureID;


};
#endif
