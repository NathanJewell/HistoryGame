#include "Room.h"

Room::Room()
{

}

void Room::initBG(ofVec2f pos, ofTexture* tex, ofVec2f dSize)
{
    roomBG.initObject(pos, tex, dSize);
}

void Room::initPERT(ofVec2f pos, ofTexture* tex, ofVec2f dSize)
{
    pictureRight.initObject(pos, tex, dSize);
}

void Room::initPELT(ofVec2f pos, ofTexture* tex, ofVec2f dSize)
{
    pictureLeft.initObject(pos, tex, dSize);
}

void Room::initFlag(ofVec2f pos, ofTexture* tex, ofVec2f dSize)
{
    flag.initObject(pos,tex,dSize);
}

void Room::setBGTexture(ofTexture* newTex)
{
    roomBG.setTexture(newTex, false);
}

void Room::setPIRTTexture(ofTexture* newTex)
{
    pictureRight.setTexture(newTex, true);
}

void Room::setPILTTexture(ofTexture* newTex)
{
    pictureLeft.setTexture(newTex, true);
}

void Room::setFlagTexture(ofTexture* newTex)
{
    flag.setTexture(newTex, false);
}

void Room::draw()
{
    roomBG.draw();
    pictureLeft.draw();
    pictureRight.draw();
    flag.draw();
}
