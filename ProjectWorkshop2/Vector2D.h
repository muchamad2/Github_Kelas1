#ifndef VECTOR2D_H_INCLUDED
#define VECTOR2D_H_INCLUDED
#include <math.h>
class Vector2D{
public:
    Vector2D(float x,float y):mx(x),my(y){}
    float getX(){return mx;}
    float getY(){return my;}
    void setX(float x){
        mx = x;
    }
    void setY(float y){
        my = y;
    }
    //panjang vector
    float length(){
        return sqrt(mx*mx+my*my);
    }
    Vector2D operator+(const Vector2D& v2) const;
    Vector2D operator-(const Vector2D& v2) const;
    Vector2D operator*(float scalar);
    Vector2D operator/(float scalar);
    void normalize();
private:
    float mx;
    float my;
};

#endif // VECTOR2D_H_INCLUDED
