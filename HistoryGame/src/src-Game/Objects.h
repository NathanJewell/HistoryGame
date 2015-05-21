#pragma once

#include "ofMain.h"
#include "Animation.h"
class Object
{
public:
    Object();
    Object(ofVec2f pos, ofTexture* tex, ofVec2f dSize);
    void initObject(ofVec2f pos, ofTexture* tex, ofVec2f dSize);
    ofTexture* getTexture();
    void setTexture(ofTexture*, bool);

    ofVec2f getPosition();
    void setPosition(ofVec2f pos);

    ofVec2f getDrawSize();
    void setDrawSize(ofVec2f);


    void update();
    void draw();
protected:
    ofVec2f position;
    ofVec2f drawPosition;
    ofTexture* objectTexture;
    ofVec2f drawSize;
};

class AnimObject : public Object
{
public:
    AnimObject();
    AnimObject(ofVec2f pos, ofTexture* tex, ofVec2f texSize, int FPS, int numFrames, bool alwaysOn);
    AnimObject(ofVec2f pos, ofTexture* tex, ofTexture* animTex, ofVec2f texSize, int FPS, int numFrames, bool alwaysOn);

    void update();      //void and update functions from Object will be overwritten
    void draw();

    Animation objectAnim;   //declare animation
private:

    bool bgIsAnim;
};
