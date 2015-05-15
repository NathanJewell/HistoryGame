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
    gameRoom.initBG(ofVec2f((ofGetWindowHeight()/2), (ofGetWindowHeight()/2)), recMan.getTexturePointer("CongressModern"), ofVec2f(ofGetWindowWidth(), ofGetWindowHeight()));
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
        GUI.update(mousePos, pressed, clicked);
//        std::string input;
//        std::cout << currentEvent.getName() << ", " << currentEvent.getDate() << ": " << std::endl << currentEvent.getDescription();
//        std::cout << std::endl << "Do you agree with this or nah? y/n";
//        std::cin >> input;
        testAnim.update();
        gamePlayer.update();
//        if(input == "y")
//        {
//            currentEvent = currentEvent.doNextEvent(true);
//        }
//        else if(input == "n")
//        {
//            currentEvent = currentEvent.doNextEvent(false);
//        }

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
