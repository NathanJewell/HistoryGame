#include "Player.h"

Player::Player()
{

}

Player::Player(ofTexture* hatT, ofTexture* pantsT, ofTexture* shirtT, int initMoney)
{
    setHatTexture(hatT);
    setPantTexture(pantsT);
    setShirtTexture(shirtT);
    setMoney(initMoney);
}
void Player::update()
{
    //objects dont update
}

void Player::draw()
{
    hat.draw();
    pants.draw();
    shirt.draw();
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
