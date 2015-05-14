#pragma once

#include "ofMain.h"

class Animation
{
public:
    Animation();
    Animation(ofTexture*, ofVec2f, ofVec2f pos, int, int);
    void init(ofTexture*, ofVec2f, ofVec2f pos, int, int);
    ofTexture* getTextureSheet();
    void setTextureSheet(ofTexture*);
    void calcSheetDimensions();

    ofVec2f getPosition();
    void setPosition(ofVec2f);

    void update();
    void doNextOffset();

    void drawCurrentFrame();
private:
    ofVec2f position;
    ofTexture* sheet;
    ofVec2f frameSize, sheetDimensions, offset;
    int animationFPS;
    int numAnimationFrames;
    int currentFrameNum;
    long lastFrameTime;
};
