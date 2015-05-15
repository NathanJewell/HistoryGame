#include "Objects.h"

//-----------------------OBJECT-----------------------------
Object::Object()
{

}

Object::Object(ofVec2f pos, ofTexture* tex, ofVec2f dSize)
{
    initObject(pos, tex, dSize);
}

void Object::initObject(ofVec2f pos, ofTexture* tex, ofVec2f dScale)
{
    objectTexture = tex;
    setDrawScale(dScale);
    setPosition(pos);

}
ofTexture* Object::getTexture()
{
    return objectTexture;
}

void Object::setTexture(ofTexture* newTexture)
{
    objectTexture = newTexture;
}

ofVec2f Object::getPosition()
{
    return position;
}

void Object::setPosition(ofVec2f pos)
{
    position = pos;
    std::cout << position.x << ", " << position.y << std::endl;
    drawPosition = ofVec2f(position.x-(objectTexture->getWidth()/2), position.y-(objectTexture->getHeight()/2));
}

ofVec2f Object::getDrawSize()
{
    return drawSize;
}

void Object::setDrawScale(ofVec2f dScale)
{
    drawSize = ofVec2f(objectTexture->getWidth()*dScale.x, objectTexture->getHeight()*dScale.y);
}

void Object::update()
{
    //nothing here for now
}

void Object::draw()     //draws object centered on position
{
    objectTexture->draw(drawPosition.x, drawPosition.y, drawSize.x, drawSize.y);
}



//--------------------ANIM OBJECT--------------------------

AnimObject::AnimObject(ofVec2f pos, ofTexture* tex, ofVec2f texSize, int FPS, int numFrames, bool alwaysOn)
{
    setPosition(pos);
    setTexture(tex);
    bgIsAnim = false;
    objectAnim.init(tex, texSize, position, FPS, numFrames, alwaysOn);
}

AnimObject::AnimObject(ofVec2f pos, ofTexture* tex,ofTexture* animTex, ofVec2f texSize, int FPS, int numFrames, bool alwaysOn)
{
    setPosition(pos);
    setTexture(tex);
    bgIsAnim = true;
    objectAnim.init(animTex, texSize, position, FPS, numFrames, alwaysOn);
}



void AnimObject::update()
{
    objectAnim.update();
}

void AnimObject::draw()
{
    objectAnim.drawCurrentFrame();
    if(!bgIsAnim)
    {
        objectTexture->draw(drawPosition);
    }
}

