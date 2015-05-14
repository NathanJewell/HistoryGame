#include "GameGUI.h"

GameGUI::GameGUI()
{
    Manager = new MenuManager; // creates a new Menu manager
     Menu GUI(ofVec2f(0,0)); // creating the options menu

    Manager->addTexture("YesExitNormal", "YesButtonNormal.png");
    Manager->addTexture("YesExitPressed", "YesButtonPressed.png");
    Manager->addTexture("YesExitHovered", "YesButtonHovered.png");

    Manager->addTexture("NoExitNormal", "NoButtonNormal.png");
    Manager->addTexture("NoExitPressed", "NoButtonPressed.png");
    Manager->addTexture("NoExitHovered", "NoButtonHovered.png");

    MenuEntity *Yes; //exit game button
    Yes = new HoverButton(
                            ofVec2f(ofGetWindowWidth()/2, ofGetWindowHeight()/3),
                            Manager->getTexturePointer("YesExitNormal"),
                            Manager->getTexturePointer("YesExitHovered"),
                            Manager->getTexturePointer("YesExitPressed"),
                            Manager->getTexturePointer("YesExitPressed"),
                            Manager->getTexturePointer("YesExitPressed"),
                            Manager->getTexturePointer("YesExitPressed")
                                    );

    MenuEntity *No; //return to main menu button
    No = new HoverButton(
                            ofVec2f(ofGetWindowWidth()/2, (ofGetWindowHeight()/3)*2),
                            Manager->getTexturePointer("NoExitNormal"),
                            Manager->getTexturePointer("NoExitHovered"),
                            Manager->getTexturePointer("NoExitPressed"),
                            Manager->getTexturePointer("NoExitPressed"),
                            Manager->getTexturePointer("NoExitPressed"),
                            Manager->getTexturePointer("NoExitPressed")
                                    );

    GUI.addEntity(*No, "NoButton");
    GUI.addEntity(*Yes, "YesButton");

    Manager->addMenu(GUI, "GUIMenu");

    GUIMenu = Manager->getMenuPointerByName("GUIMenu");

    YesButton = GUIMenu->getPointerToChildByName<HoverButton>("YesButton");
    NoButton = GUIMenu->getPointerToChildByName<HoverButton>("NoButton");


}

void GameGUI::draw()
{
    Manager->draw();
}

bool GameGUI::update(ofVec2f& mousePos, bool& clicked, bool& pressed)
{
    Manager->update(mousePos, clicked, pressed);
}
