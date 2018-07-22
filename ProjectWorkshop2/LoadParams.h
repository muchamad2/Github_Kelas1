#ifndef LOADPARAMS_H_INCLUDED
#define LOADPARAMS_H_INCLUDED
#include <string>
class loadParam{
public:
    loadParam(int x,int y,int width,int height,std::string textureID): mx(x),my(y),mwidth(width),mheight(height),mTextureID(textureID){}
    int GetX() const {return mx;}
    int GetY() const {return my;}

    int getWidth() const {return mwidth;}
    int getHeight() const {return mheight;}
    std::string getTexture() const {return mTextureID;}
private:
    int mx;
    int my;
    int mwidth;
    int mheight;
    std::string mTextureID;
};


#endif // LOADPARAMS_H_INCLUDED
