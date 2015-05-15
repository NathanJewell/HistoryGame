#pragma once

#include "ofMain.h"

class Animation
{
public:
    Animation();
    Animation(ofTexture*, ofVec2f, ofVec2f pos, int, int, bool);
    void init(ofTexture*, ofVec2f, ofVec2f pos, int, int, bool);
    ofTexture* getTextureSheet();
    void setTextureSheet(ofTexture*);
    void calcSheetDimensions();

    ofVec2f getPosition();
    void setPosition(ofVec2f);

    void update();
    void doNextOffset();

    void doAnimation(int);
    void toggleAlwaysOn();

    void drawCurrentFrame();
private:
    ofVec2f position;
    ofTexture* sheet;
    ofVec2f frameSize, sheetDimensions, offset;
    int animationFPS;
    int numAnimationFrames;
    int currentFrameNum;
    long lastFrameTime;
    bool alwaysOn, nowOn;
    int numDone, numRequested;
};
