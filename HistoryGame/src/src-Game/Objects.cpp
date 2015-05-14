#include "Objects.h"

//-----------------------OBJECT-----------------------------
Object::Object()
{

}

Object::Object(ofVec2f pos, ofTexture& tex)
{
    objectTexture = &tex;
    setPosition(pos);

}

ofTexture* Object::getTexture()
{
    return objectTexture;
}

void Object::setTexture(ofTexture& newTexture)
{
    objectTexture = &newTexture;
}

ofVec2f Object::getPosition()
{
    return position;
}

void Object::setPosition(ofVec2f pos)
{
    position = pos;
    drawPosition = ofVec2f(position.x-(objectTexture->getWidth()/2), position.y-(objectTexture->getHeight()/2));
}

void Object::update()
{
    //nothing here for now
}

void Object::draw()     //draws object centered on position
{
    objectTexture->draw(drawPosition);
}



//--------------------ANIM OBJECT--------------------------

//AnimObject::AnimObject(ofVec2f pos, ofTexture& tex, ofVec2f texSize, int FPS, int numFrames)
//{
//    setPosition(pos);
//    objectTexture = tex;
//    bgIsAnim = false;
//    objectAnim.init(tex, texSize, position, FPS, numFrames);
//}
//
//AnimObject::AnimObject(ofVec2f pos, ofTexture& tex, bool doBG, ofTexture& animTex, ofVec2f texSize, int FPS, int numFrames)
//{
//    setPosition(pos);
//    objectTexture = tex;
//    bgIsAnim = true;
//    objectAnim.init(animTex, texSize, position, FPS, numFrames);
//}
//
//
//void update()
//{
//    objectAnim.update();
//}
//
//void draw()
//{
//    objectAnim.drawCurrentFrame();
//    if(!bgIsAnim)
//    {
//        objectTexture->draw(drawPosition);
//    }
//}
//
