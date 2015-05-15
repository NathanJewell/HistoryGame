#pragma once
#include "Objects.h"
class Player
{
    public:
        Player();
        void update();
        void draw();

        void initHat(ofVec2f, ofTexture*);
        void initPant(ofVec2f, ofTexture*);
        void initShirt(ofVec2f, ofTexture*);
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
