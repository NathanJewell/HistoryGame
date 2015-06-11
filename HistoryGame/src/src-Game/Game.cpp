#include "Game.h"

Game::Game(int startingEvent)
{
    recMan.loadFilesFromDirectory("C:\\OpenFrameworks\\apps\\HistoryGame\\HistoryGame\\bin\\data\\historyTextures");

    gamePlayer.initHat(ofVec2f(ofGetWindowWidth()/2, ofGetWindowHeight()-138), recMan.getTexturePointer("ClassicHat"));
    gamePlayer.initPant(ofVec2f(ofGetWindowWidth()/2, ofGetWindowHeight()-10), recMan.getTexturePointer("ClassicSlacks"));
    gamePlayer.initShirt(ofVec2f(ofGetWindowWidth()/2, ofGetWindowHeight()-74), recMan.getTexturePointer("ClassicSuit"));
    gameRoom.initBG(ofVec2f(240,135), recMan.getTexturePointer("CongressModern"), ofVec2f(ofGetWindowWidth(), ofGetWindowHeight()));
    gameRoom.initPERT(ofVec2f((ofGetWindowWidth()/5)*4 + 15, (ofGetWindowHeight()/4)+7), recMan.getTexturePointer("DefaultPicRight"), ofVec2f(198, 264));
    gameRoom.initPELT(ofVec2f((ofGetWindowWidth()/5)-150+15-50, (ofGetWindowHeight()/4)+7), recMan.getTexturePointer("DefaultPicLeft"), ofVec2f(198, 264));
    gameRoom.initFlag(ofVec2f(ofGetWindowWidth()/2-112, 170), recMan.getTexturePointer("MuricanFlag"), ofVec2f(300, 400));
    gameRoom.initFrames(ofVec2f((ofGetWindowWidth()/5)*4, (ofGetWindowHeight()/4)), ofVec2f((ofGetWindowWidth()/5)-150-50, (ofGetWindowHeight()/4)), recMan.getTexturePointer("frame"), ofVec2f(300, 366));
    currentEvent = loadEvent(startingEvent);    //load first event of chain
    adjustRoomToEvent();
    currentState = MMENU;
    std::cout << currentEvent.getDescription() << std::endl;
    GUI.enablePopup();

    bgSound.loadSound("courtBG.wav");
    bgSound.setLoop(true);
    bgSound.setVolume(.6);
    bgSound.play();
    currentScore = 100;

    lossSound.loadSound("ending.mp3");
    lossSound.setLoop(false);
    lossSound.setVolume(.5);

    boos.loadSound("booing.wav");
    boos.setMultiPlay(false);
    boos.setLoop(false);
    boos.setVolume(1);

    applause.loadSound("applause.wav");
    applause.setMultiPlay(false);
    applause.setLoop(false);
    applause.setVolume(1);

    endSound = false;

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
        GUI.setScore("Patriot Points: " + typeToString(currentScore));
        eventState = GUI.update(mousePos, clicked, pressed);    //0 is no 1 is yes 3 is nothing
        GUI.setPopupText(currentEvent.getDescription());
        if(eventState == 0)
        {
            dif = currentScore;
            currentScore += currentEvent.getPointValue(false);
            if(currentScore <= 0)
            {
                lossSound.play();
                if(currentEvent.getNextEventNum(false) < 100)
                {
                    currentEvent = currentEvent.doNextEvent(false);
                    adjustRoomToEvent();
                }
                else
                {
                    currentEvent = loadEvent(0);
                    adjustRoomToEvent();
                }

            }
            else
            {
                currentEvent = currentEvent.doNextEvent(false);
                adjustRoomToEvent();
            }
            if(currentScore-dif > 0)
            {
                applause.play();
            }
            else if(currentScore > 0)
            {
                boos.play();
            }

        }
        else if(eventState == 1)
        {
            currentScore += currentEvent.getPointValue(true);
            if(currentScore <= 0)
            {
                endSound = true;
                if(currentEvent.getNextEventNum(true) < 100)
                {
                    currentEvent = currentEvent.doNextEvent(true);
                    adjustRoomToEvent();
                }
                else
                {
                    currentEvent = loadEvent(0);
                    adjustRoomToEvent();
                }

            }
            else
            {
                currentEvent = currentEvent.doNextEvent(true);
                adjustRoomToEvent();
            }
            if(currentScore-dif > 0)
            {
                applause.play();
            }
            else if(currentScore > 0)
            {
                boos.play();
            }


        }
        else if(eventState == 4)
        {
            endSound = false;
            mainMenu.restartMenu();
            currentState = MMENU;
        }
        else if(eventState == 5)
        {
            endSound = false;
            GUI.toggleYNButs();
            GUI.toggleEndScreen();
            currentEvent = loadEvent(100);
            currentScore = 100;
            adjustRoomToEvent();
        }
    }
    if(if)
    {
        lossSound.stop();
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
    GUI.setInfoText(currentEvent.getName() + ", \n" + typeToString(currentEvent.getDate()));

    if(currentEvent.getEventNum() < 100)
    {
        GUI.toggleYNButs();
        GUI.toggleEndScreen();
    }
}
