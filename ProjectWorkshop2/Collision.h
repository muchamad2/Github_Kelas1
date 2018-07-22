#ifndef COLLISION_H
#define COLLISION_H

class Collision
{
    public:
        Collision(){}
        static Collision* Instance(){
            if(pInstance==0)
            {
                pInstance = new Collision();
                return pInstance;
            }
            return pInstance;
        }
        void setEnYpos(float posY){setYpos = posY;}
        float getYpos(){return setYpos;}
    private:
        float setYpos;
        static Collision* pInstance ;
};

#endif // COLLISION_H
