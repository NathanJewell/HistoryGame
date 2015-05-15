#include "Player.h"

Player::Player()
{

}

void Player::update()
{
    //normal objects dont update
}

void Player::draw()
{
    hat.draw();
    pants.draw();
    shirt.draw();
}

void Player::initHat(ofVec2f pos, ofTexture* tex)
{
    hat.initObject(pos, tex, ofVec2f(2, 2));
}

void Player::initPant(ofVec2f pos, ofTexture* tex)
{
    pants.initObject(pos, tex, ofVec2f(2, 2));
}

void Player::initShirt(ofVec2f pos, ofTexture* tex)
{
    shirt.initObject(pos, tex, ofVec2f(2, 2));
}

void Player::setHatTexture(ofTexture* newT)
{
    hat.setTexture(newT);
}
void Player::setPantTexture(ofTexture* newT)
{
    pants.setTexture(newT);
}
void Player::setShirtTexture(ofTexture* newT)
{
    shirt.setTexture(newT);
}

void Player::addMoney(int amount)
{
    money+=amount;
}

void Player::subMoney(int amount)
{
    money-=amount;
}

int Player::getMoney()
{
    return money;
}

void Player::setMoney(int amount)
{
    money = amount;
}
