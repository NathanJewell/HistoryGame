#include "Game.h"

Game::Game(int startingEvent)
{
    std::cout << startingEvent << std::endl;
    currentEvent = loadEvent(startingEvent);    //load first event of chain
}

Event Game::getCurrentEvent()
{
    return currentEvent;
}

void Game::setCurrentEvent(Event e)
{
    currentEvent = e;
}

void Game::update()
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


}

void Game::draw()
{

}
