#include "Player.h"
#include "../InputHandle.h"

Player::Player(const loadParam* Params) : GameObject(Params)
{
    //ctor
}
void Player::draw(){
    GameObject::draw();
}
void Player::update(){
    Velocity.setX(0);
    inputEvent();
    GameObject::update();
}
void Player::clean(){

}
void Player::inputEvent()
{
    if(InputHandle::Instance()->isKeyDown(SDL_SCANCODE_RIGHT))
        Velocity.setX(2);
    else if(InputHandle::Instance()->isKeyDown(SDL_SCANCODE_LEFT))
        Velocity.setX(-2);
}
