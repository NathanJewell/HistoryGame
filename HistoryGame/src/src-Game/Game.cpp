#include "Game.h"

Game::Game(int startingEvent)
{
    currentEvent = loadEvent(startingEvent);    //load first event of chain
    currentState = MMENU;
    recMan.loadFilesFromDirectory("C:\\OpenFrameworks\\apps\\HistoryGame\\HistoryGame\\bin\\data\\historyTextures");
    testAnim.init(recMan.getTexturePointer("testSheet"), ofVec2f(128,128), ofVec2f(300, 300), 1, 5, true);
    //gameRoom.setBGTexture(recMan.getTexturePointer("CongressModern"));
    gamePlayer.initHat(ofVec2f(ofGetWindowWidth()/2, ofGetWindowHeight()-138), recMan.getTexturePointer("ClassicHat"));
    gamePlayer.initPant(ofVec2f(ofGetWindowWidth()/2, ofGetWindowHeight()-10), recMan.getTexturePointer("ClassicSlacks"));
    gamePlayer.initShirt(ofVec2f(ofGetWindowWidth()/2, ofGetWindowHeight()-74), recMan.getTexturePointer("ClassicSuit"));
    gameRoom.initBG(ofVec2f((ofGetWindowHeight()/2)-256-32, (ofGetWindowHeight()/2)-256-32), recMan.getTexturePointer("CongressModern"), ofVec2f(ofGetWindowWidth(), ofGetWindowHeight()));
}

Event Game::getCurrentEvent()
{
    return currentEvent;
}

void Game::setCurrentEvent(Event e)
{
    currentEvent = e;
}

void Game::update(ofVec2f& mousePos, bool& clicked, bool& pressed)
{
    if(currentState == GAME)
    {
        eventState = GUI.update(mousePos, pressed, clicked);    //0 is no 1 is yes 3 is nothing
        if(eventState == 0)
        {
            currentEvent.doNextEvent(false);
            adjustRoomToEvent();
        }
        else if(eventState == 1)
        {
            currentEvent.doNextEvent(true);
            adjustRoomToEvent();
        }
        testAnim.update();
        gamePlayer.update();
    }
    else if(currentState == MMENU)
    {
        if(mainMenu.update(mousePos, clicked, pressed))
        {
            currentState = GAME;
        }
    }
}

void Game::draw()
{
    if(currentState == GAME)
    {
        gameRoom.draw();
        testAnim.drawCurrentFrame();
        gamePlayer.draw();
        GUI.draw();
    }
    else if(currentState == MMENU)
    {
        mainMenu.draw();
    }
}

void adjustRoomToEvent()
{
    std::vector<std::string> roomData = currentEvent.getRoomTextureData();
    for(int ii =0; ii<roomData.size(); ii++)
    {
        if(!roomData[ii].contains("same") && !roomData[ii].contains("&&&"))
        {
            switch(ii)
            {
            case 0:
                gameRoom.setBGTexture(recMaxs
                                      n.getTexturePointer(roomData[ii])); //example
            case 1:

            case 2:

            case 3:
                //continue for all room data things
            }
        }
    }
}
