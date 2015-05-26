#include "Room.h"

Room::Room()
{

}

void Room::initFrames(ofVec2f lPos, ofVec2f rPos, ofTexture* tex, ofVec2f dSize)
{
    frameL.initObject(lPos, tex, dSize);
    frameR.initObject(rPos, tex, dSize);
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

void Room::setFrameTextures(ofTexture* newTex)
{
    frameL.setTexture(newTex, true);
    frameR.setTexture(newTex, true);
}
void Room::setBGTexture(ofTexture* newTex)
{
    roomBG.setTexture(newTex, false);
}

void Room::setPIRTTexture(ofTexture* newTex)
{
    pictureRight.setTexture(newTex, false);
}

void Room::setPILTTexture(ofTexture* newTex)
{
    pictureLeft.setTexture(newTex, false);
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
    frameR.draw();
    frameL.draw();
}
