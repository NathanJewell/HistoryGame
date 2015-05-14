#pragma once
#include "Objects.h"
class Player
{
    public:
        Player();
        Player(ofTexture* hat, ofTexture* pants, ofTexture* shirt, int initMoney);
        void update();
        void draw();

        void setHatTexture(ofTexture*);
        void setPantTexture(ofTexture*);
        void setShirtTexture(ofTexture*);

        void addMoney(int amount);
        void subMoney(int amount);
        int getMoney();
        void setMoney(int amount);

    private:
        Object hat;
        Object pants;
        Object shirt;

        int money;
};
