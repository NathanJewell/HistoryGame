#include "Game.h"

Game::Game(int startingEvent)
{
    currentEvent = loadEvent(startingEvent);    //load first event of chain
    currentState = MMENU;
    recMan.addTexture("testSheet.png", "testSheet");
    testAnim.init(recMan.getTexturePointer("testSheet"), ofVec2f(128,128), ofVec2f(300, 300), 5, 5);
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
//        std::string input;
//        std::cout << currentEvent.getName() << ", " << currentEvent.getDate() << ": " << std::endl << currentEvent.getDescription();
//        std::cout << std::endl << "Do you agree with this or nah? y/n";
//        std::cin >> input;
        testAnim.update();
//        if(input == "y")
//        {
//            currentEvent = currentEvent.doNextEvent(true);
//        }
//        else if(input == "n")
//        {
//            currentEvent = currentEvent.doNextEvent(false);
//        }
        GUI.update(mousePos, pressed, clicked);
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
        GUI.draw();
        testAnim.drawCurrentFrame();
    }
    else if(currentState == MMENU)
    {
        mainMenu.draw();
    }
}
