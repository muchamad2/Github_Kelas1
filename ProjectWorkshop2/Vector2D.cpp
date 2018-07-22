#include "Vector2D.h"

Vector2D Vector2D::operator+(const Vector2D& v2) const
{
    return Vector2D(mx+v2.mx,my+v2.my);
}
Vector2D Vector2D::operator-(const Vector2D& v2) const
{
    return Vector2D(mx-v2.mx,my-v2.my);
}
Vector2D Vector2D::operator*(float scalar)
{
    return Vector2D(mx*scalar,my*scalar);
}
Vector2D Vector2D::operator/(float scalar)
{
    return Vector2D(mx/scalar,my/scalar);
}
void Vector2D::normalize()
{
    float l = length();
    if(1>0){
        (*this) = (*this) * (1/l);
    }
}
