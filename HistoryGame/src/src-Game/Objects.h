#pragma once

#include "ofMain.h"

class Object
{
public:
    Object();
    Object(ofVec2f pos, ofTexture& tex);
    ofTexture* getTexture();
    void setTexture(ofTexture&);

    void getPosition();
    ofVec2f setTexture(ofVec2f);

    void update();
    void draw();
private:
    ofVec2f position;
    ofVec2f drawPosition;
    ofTexture* objectTexture;
};

class AnimObject : public Object
{
public:
    AnimObject();
    AnimObject(ofVec2f pos, ofTexture& tex, ofVec2f texSize, int FPS, int numFrames);
    AnimObject(ofVec2f pos, ofTexture& tex, ofTexture& animTex, ofVec2f texSize, int FPS, int numFrames);

    void update();      //void and update functions from Object will be overwritten
    void draw();
private:
    Animation objectAnim;   //declare animation
    bool bgIsAnim;
};
