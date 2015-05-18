#include "GameGUI.h"

GameGUI::GameGUI()
{
    Manager = new MenuManager; // creates a new Menu manager
    Menu GUI(ofVec2f(0,0)); // creating the options menu

    Manager->addTexture("YesExitNormal", "Yea.png");
    Manager->addTexture("YesExitPressed", "YeaPressed.png");
    Manager->addTexture("YesExitHovered", "YeaHovered.png");

    Manager->addTexture("NoExitNormal", "Nay.png");
    Manager->addTexture("NoExitPressed", "NayPressed.png");
    Manager->addTexture("NoExitHovered", "NayHovered.png");

    MenuEntity *Yes; //exit game button
    Yes = new HoverButton(
                            ofVec2f(ofGetWindowWidth()/3, ofGetWindowHeight()-100),
                            Manager->getTexturePointer("YesExitNormal"),
                            Manager->getTexturePointer("YesExitHovered"),
                            Manager->getTexturePointer("YesExitPressed"),
                            Manager->getTexturePointer("YesExitPressed"),
                            Manager->getTexturePointer("YesExitPressed"),
                            Manager->getTexturePointer("YesExitPressed")
                                    );

    MenuEntity *No; //return to main menu button
    No = new HoverButton(
                            ofVec2f((ofGetWindowWidth()/3)*2, ofGetWindowHeight()-100),
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
    GUIMenu->setActive();

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
    std::cout << "yes: " << YesButton->getEventDataInt() << std::endl;
    std::cout << "no: " << NoButton->getEventDataInt() << std::endl;

}
