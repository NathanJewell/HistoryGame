#pragma once
#include "ofMain.h"
#include "../src-MenuAPI/MenuInclude.h"


class GameGUI
{
public:
    // in public, we have simple functions
    GameGUI();
    void draw();
    bool update(ofVec2f& mousePos, bool& clicked, bool& pressed);
//    void switchActive();
//    bool getActive();

private:
   MenuManager *Manager; // this is the menumanager for the main menu
   Menu* GUIMenu; // pointer to options menu
//   Menu* defaultMenu; // pointer to default menu
//   Menu* creditsMenu; // pointer to credits menu
//   Menu* quitGameMenu; //pointer to quit menu
//   bool active; // is the main menu active or not

   // make pointers to every button
   HoverButton* YesButton; // pointer to exit button
   HoverButton* NoButton; // pointer to options button, etc...
//   HoverButton* StartGameButton;
//   HoverButton* CreditsBut;
//   HoverButton* CancelBut;
//   HoverButton* QuitGameBut;
//   HoverButton* YesQuitBut;
//   HoverButton* NoQuitBut;
//    Slider* BrightnessSlider;
//    Slider* VolumeSlider;
};

