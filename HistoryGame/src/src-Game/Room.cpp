#include "Room.h"

Room::Room()
{

}

void Room::initBG(ofVec2f pos, ofTexture* tex, ofVec2f dSize)
{
    roomBG.initObject(pos, tex, dSize);
}
void Room::setBGTexture(ofTexture* newTex)
{
    roomBG.setTexture(newTex);
}

void Room::draw()
{
    roomBG.draw();
}
