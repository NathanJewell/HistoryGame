#include "Animation.h"

Animation::Animation()
{
    currentFrameNum = 0;
}

Animation::Animation(ofTexture* she, ofVec2f fS, ofVec2f pos, int FPS, int numFrames)
{
    sheet = she;
    calcSheetDimensions();
    frameSize = fS;
    animationFPS = FPS;
    numAnimationFrames = numFrames;
    position = pos;
}

void Animation::init(ofTexture* she, ofVec2f fS, ofVec2f pos, int FPS, int numFrames)
{
    sheet = she;
    calcSheetDimensions();
    frameSize = fS;
    animationFPS = FPS;
    numAnimationFrames = numFrames;
    position = pos;
}

ofTexture* Animation::getTextureSheet()
{
    return sheet;
}

void Animation::setTextureSheet(ofTexture* tex)
{
    sheet = tex;
    calcSheetDimensions();
}

void Animation::calcSheetDimensions()
{
    sheetDimensions = ofVec2f(sheet->getWidth()/frameSize.x, sheet->getHeight()/frameSize.y);
}

void Animation::update()
{
    if(ofGetElapsedTimeMillis()-lastFrameTime >= (long)1000/animationFPS)
    {
        std::cout << currentFrameNum << std::endl;
        currentFrameNum++;
        if(currentFrameNum > numAnimationFrames)
        {
            currentFrameNum=1;
        }
        doNextOffset();
        lastFrameTime = ofGetElapsedTimeMillis();
    }
}

void Animation::doNextOffset()
{
    float row = (currentFrameNum/sheetDimensions.x);
    row = trunc(row);
    float fcolumn = currentFrameNum%(int)sheetDimensions.x;
    int icolumn = fcolumn;
    offset = ofVec2f(icolumn*frameSize.x, row*frameSize.y);
}

void Animation::drawCurrentFrame()
{
    sheet->drawSubsection(position.x, position.y, frameSize.x, frameSize.y, offset.x, offset.y);
}

