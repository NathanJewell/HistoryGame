#pragma once

#include "ofMain.h"
#include "Objects.h"
class Room
{
public:
    Room();
    //Room(ofTexture* roomBGT, ofTexture* peRT, ofTexture* peLT, ofTexture* piRT, ofTexture* perFT, ofTexture* flagT);

    void update();
    void draw();

    void setBGTexture(ofTexture* newTex);
//    void setPERTexture(ofTexture* newTex)
//    void setPELTexture(ofTexture* newTex)
//    void setPILTexture(ofTexture* newTex)
//    void setPIRTTexture(ofTexture* newTex)
//    void setPEFTexture(ofTexture* newTex)
//    void setFlagTexture(ofTexture* newTex)
private:
    Object roomBG;          //BG
//    Object peopleRight;     //PER
//    Object peopleLeft;      //PEL
//    Object pictureRight;    //PIR
//    Object pictureLeft;     //PIL
//    Object personFront;     //PFT
//    Object flag;

};
