#include "Game.h"

Game::Game(int startingEvent)
{
    recMan.loadFilesFromDirectory("C:\\OpenFrameworks\\apps\\HistoryGame\\HistoryGame\\bin\\data\\historyTextures");

    gamePlayer.initHat(ofVec2f(ofGetWindowWidth()/2, ofGetWindowHeight()-138), recMan.getTexturePointer("ClassicHat"));
    gamePlayer.initPant(ofVec2f(ofGetWindowWidth()/2, ofGetWindowHeight()-10), recMan.getTexturePointer("ClassicSlacks"));
    gamePlayer.initShirt(ofVec2f(ofGetWindowWidth()/2, ofGetWindowHeight()-74), recMan.getTexturePointer("ClassicSuit"));
    gameRoom.initBG(ofVec2f(240,135), recMan.getTexturePointer("CongressModern"), ofVec2f(ofGetWindowWidth(), ofGetWindowHeight()));
    gameRoom.initPERT(ofVec2f((ofGetWindowWidth()/3)*2, (ofGetWindowHeight()/2)), recMan.getTexturePointer("DefaultPicRight"), ofVec2f(0, 0));
    gameRoom.initPELT(ofVec2f((ofGetWindowWidth()/3), (ofGetWindowHeight()/2)), recMan.getTexturePointer("DefaultPicLeft"), ofVec2f(0, 0));
    gameRoom.initFlag(ofVec2f(ofGetWindowWidth()/2-112, 170), recMan.getTexturePointer("MuricanFlag"), ofVec2f(300, 400));
    currentEvent = loadEvent(startingEvent);    //load first event of chain
    adjustRoomToEvent();
    currentState = MMENU;
    std::cout << currentEvent.getDescription() << std::endl;
    GUI.enablePopup();


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
        eventState = GUI.update(mousePos, clicked, pressed);    //0 is no 1 is yes 3 is nothing
        GUI.setPopupText(currentEvent.getDescription());
        if(eventState == 0)
        {
            currentEvent = currentEvent.doNextEvent(false);
            adjustRoomToEvent();
        }
        else if(eventState == 1)
        {
            currentEvent = currentEvent.doNextEvent(true);
            adjustRoomToEvent();
        }
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
        gamePlayer.draw();
        GUI.draw();
    }
    else if(currentState == MMENU)
    {
        mainMenu.draw();
    }
}

void Game::adjustRoomToEvent()
{
    std::vector<std::string> roomData = currentEvent.getRoomTextureData();
    for(int ii =0; ii<roomData.size(); ii++)
    {
        if(roomData[ii]!="SAME" && roomData[ii]!="&&&")
        {
            switch(ii)
            {
            case 0:
                gameRoom.setBGTexture(recMan.getTexturePointer(roomData[ii])); //example
            case 1:
                gameRoom.setPIRTTexture(recMan.getTexturePointer(roomData[ii]));
            case 2:
                gameRoom.setPILTTexture(recMan.getTexturePointer(roomData[ii]));
            case 3:
                gameRoom.setFlagTexture(recMan.getTexturePointer(roomData[ii]));
            }
        }
    }
}
