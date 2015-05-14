#include "Game.h"

Game::Game(int startingEvent)
{
    std::cout << startingEvent << std::endl;
    currentEvent = loadEvent(startingEvent);    //load first event of chain
    currentState = MMENU;
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
        std::string input;
        std::cout << currentEvent.getName() << ", " << currentEvent.getDate() << ": " << std::endl << currentEvent.getDescription();
        std::cout << std::endl << "Do you agree with this or nah? y/n";
        std::cin >> input;

        if(input == "y")
        {
            currentEvent = currentEvent.doNextEvent(true);
        }
        else if(input == "n")
        {
            currentEvent = currentEvent.doNextEvent(false);
        }
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
    }
    else if(currentState == MMENU)
    {
        mainMenu.draw();
    }
}
