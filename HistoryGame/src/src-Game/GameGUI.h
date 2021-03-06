#pragma once
#include "ofMain.h"
#include "../src-MenuAPI/MenuInclude.h"


class GameGUI
{
public:
    // in public, we have simple functions
    GameGUI();
    void draw();
    int update(ofVec2f& mousePos, bool& clicked, bool& pressed);
    void setPopupText(std::string);
    void enablePopup();
    void setInfoText(std::string);
    void toggleYNButs();
    void toggleEndScreen();
    void setScore(std::string);
//    void switchActive();
//    bool getActive();

private:
   MenuManager *Manager; // this is the menumanager for the main menu
   Menu* GUIMenu; // pointer to options menu
   Menu* PopupMenu;
   Menu* YNMenu;
   Menu* EndMenu;

   // make pointers to every button
   HoverButton* YesButton; // pointer to exit button
   HoverButton* NoButton; // pointer to options button, etc...

   TextBox* PopupText;
   TextBox* InfoText;
   HoverButton* popupButton;
   HoverButton* shopButton;
   HoverButton* mainMenuBut;
   HoverButton* EndButton;
   TextBox* scoreBox;
};

