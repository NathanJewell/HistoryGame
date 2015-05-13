#pragma once

#include "ofMain.h"
#include <iostream>
#include "Player.h"
#include "Event.h"
#include "../src-MenuAPI/MenuManager.h"

class Game
{
public:
    Game(int startingEvent);
    Event getCurrentEvent();
    void setCurrentEvent(Event e);

    void update();
    void draw();

private:
    Event currentEvent;
    Player gamePlayer;
    MenuManager GUI;

};
