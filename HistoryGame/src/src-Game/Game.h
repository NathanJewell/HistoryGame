#pragma once

#include "ofMain.h"
#include <iostream>
#include "Player.h"
#include "Event.h"
#include "GameGUI.h"
#include "MainMenu.h"
#include "ResourceManager.h"
#include "Room.h"
#include "Util.h"
class Game
{
public:
    Game(int startingEvent);
    Event getCurrentEvent();
    void setCurrentEvent(Event e);
    void adjustRoomToEvent();

    void update(ofVec2f&, bool&, bool&);
    void draw();

private:

    GameGUI GUI;
    MainMenu mainMenu;
    ResourceManager recMan;
    Animation testAnim;
    enum gameState{MMENU, GAME, SHOP};
    gameState currentState;

    Event currentEvent;
    Room gameRoom;
    Player gamePlayer;
    ofSoundPlayer bgSound, lossSound, boos, applause;
    int eventState;
    int currentScore;
    bool endSound;
    int dif;



};
