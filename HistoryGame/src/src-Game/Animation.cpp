#include "Animation.h"

Animation::Animation()
{
    currentFrameNum = 0;
}

Animation::Animation(ofTexture* she, ofVec2f fS, ofVec2f pos, int FPS, int numFrames, bool onnes)
{
    init(she, fS, pos, FPS, numFrames, onnes);
}

void Animation::init(ofTexture* she, ofVec2f fS, ofVec2f pos, int FPS, int numFrames, bool onnes)
{
    sheet = she;

    frameSize = fS;
    animationFPS = FPS;
    numAnimationFrames = numFrames;
    position = pos;
    calcSheetDimensions();
    alwaysOn = onnes;
    nowOn = true;
    if(!alwaysOn)
    {
        nowOn = false;
    }
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

void Animation::doAnimation(int times)
{
    nowOn = true;
    numRequested = times;
}

void Animation::toggleAlwaysOn()
{
    alwaysOn = !alwaysOn;
}

void Animation::calcSheetDimensions()
{
    sheetDimensions = ofVec2f(sheet->getWidth()/frameSize.x, sheet->getHeight()/frameSize.y);
}

void Animation::update()
{
    if(ofGetElapsedTimeMillis()-lastFrameTime >= (long)1000/animationFPS && nowOn)
    {
//        std::cout << currentFrameNum << std::endl;
        currentFrameNum++;
        if(currentFrameNum > numAnimationFrames)
        {
            currentFrameNum=0;
            if(!alwaysOn)
            {
                numDone++;
                if(numDone >= numRequested)
                {
                    nowOn = false;
                    numDone = 0;
                }

            }
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
    if(nowOn)
    {
        sheet->drawSubsection(position.x, position.y, frameSize.x, frameSize.y, offset.x, offset.y);
    }
}

