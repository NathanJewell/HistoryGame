#pragma once

#include "ofMain.h"
#include <iostream>
#include "Player.h"
#include "Event.h"
#include "GameGUI.h"
#include "MainMenu.h"

class Game
{
public:
    Game(int startingEvent);
    Event getCurrentEvent();
    void setCurrentEvent(Event e);

    void update(ofVec2f&, bool&, bool&);
    void draw();

private:
    Event currentEvent;
    Player gamePlayer;
    GameGUI GUI;
    MainMenu mainMenu;
    enum gameState{MMENU, GAME, SHOP};
    gameState currentState;

};
