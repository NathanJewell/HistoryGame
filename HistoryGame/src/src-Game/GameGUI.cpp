#include "GameGUI.h"

GameGUI::GameGUI()
{
    Manager = new MenuManager; // creates a new Menu manager
    Menu GUI(ofVec2f(0,0)); // creating the options menu
    Menu popup(ofVec2f(0, 0));
    Menu YN(ofVec2f(0, 0));
    Menu endMenu(ofVec2f(0, 0));

    Manager->addTexture("OpenHovered", "popupHovered.png");
    Manager->addTexture("OpenClickedHovered", "popupClickedHovered.png");
    Manager->addTexture("OpenClicked", "popupClicked.png");
    Manager->addTexture("OpenNormal", "popup.png");
    Manager->addTexture("PopupBG", "scroll.png");
    Manager->addFont("PopupFont", "Barquet.ttf", 24);

    Manager->addTexture("YesExitNormal", "Yea.png");
    Manager->addTexture("YesExitPressed", "YeaPressed.png");
    Manager->addTexture("YesExitHovered", "YeaHovered.png");

    Manager->addTexture("NoExitNormal", "Nay.png");
    Manager->addTexture("NoExitPressed", "NayPressed.png");
    Manager->addTexture("NoExitHovered", "NayHovered.png");

    Manager->addTexture("MainMenu", "MainMenu.png");
    Manager->addTexture("MainMenuHovered", "MainMenuHovered.png");
    Manager->addTexture("MainMenuClicked", "MainMenuClicked.png");

    Manager->addTexture("restart", "restart.png");
    Manager->addTexture("restartHovered", "restartHovered.png");
    Manager->addTexture("restartClicked", "restartClicked.png");

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

    MenuEntity *popupText;
    popupText = new TextBox(
                            "SWAG",
                            ofVec2f(ofGetWindowWidth()/2, ofGetWindowHeight()/2-300),
                            Manager->getFontPointer("PopupFont")
                                );

    MenuEntity *OKButton;
    OKButton = new HoverButton(
                            ofVec2f(150, ofGetWindowHeight()-70),
                            Manager->getTexturePointer("OpenNormal"),
                            Manager->getTexturePointer("OpenHovered"),
                            Manager->getTexturePointer("OpenClicked"),
                            Manager->getTexturePointer("OpenClicked"),
                            Manager->getTexturePointer("OpenClickedHovered"),
                            Manager->getTexturePointer("OpenClickedHovered")
                                    );
    MenuEntity *MenuButton;
    MenuButton = new HoverButton(
                            ofVec2f(150, ofGetWindowHeight()-220),
                            Manager->getTexturePointer("MainMenu"),
                            Manager->getTexturePointer("MainMenuHovered"),
                            Manager->getTexturePointer("MainMenuClicked"),
                            Manager->getTexturePointer("MainMenuClicked"),
                            Manager->getTexturePointer("MainMenuClicked"),
                            Manager->getTexturePointer("MainMenuClicked")
                                    );

    MenuEntity *restartBut;
    restartBut = new HoverButton(
                            ofVec2f(ofGetWindowWidth()/2, ofGetWindowHeight()-250),
                            Manager->getTexturePointer("restart"),
                            Manager->getTexturePointer("restartHovered"),
                            Manager->getTexturePointer("restartClicked"),
                            Manager->getTexturePointer("restartClicked"),
                            Manager->getTexturePointer("restartClicked"),
                            Manager->getTexturePointer("restartClicked"));

    MenuEntity *PopupBG;
    PopupBG = new MenuBackground(ofVec2f(ofGetWindowWidth()/2, ofGetWindowHeight()/2-75),
                                 Manager->getTexturePointer("PopupBG"),
                                 false
                                    );
    MenuEntity *infoBox;
    infoBox = new TextBox("Swag",
                          ofVec2f(10, 10),
                          Manager->getFontPointer("PopupFont"));

    YN.addEntity(*No, "NoButton");
    YN.addEntity(*Yes, "YesButton");
    GUI.addEntity(*infoBox, "InfoText");
    //GUI.addEntity(*ShopButton, "ShopButton");

    popup.addEntity(*PopupBG, "BG");
    popup.addEntity(*popupText, "popupText");
    GUI.addEntity(*OKButton, "OKButton");
    GUI.addEntity(*MenuButton, "MenuButton");
    endMenu.addEntity(*restartBut, "Restart");

    Manager->addMenu(GUI, "GUIMenu");
    Manager->addMenu(popup, "popupMenu");
    Manager->addMenu(YN, "YNMenu");
    Manager->addMenu(endMenu, "endMenu");


    GUIMenu = Manager->getMenuPointerByName("GUIMenu");
    GUIMenu->setActive();

    PopupMenu = Manager->getMenuPointerByName("popupMenu");
    PopupMenu->setActive();

    YNMenu = Manager->getMenuPointerByName("YNMenu");
    YNMenu->setActive();

    EndMenu = Manager->getMenuPointerByName("endMenu");
    EndMenu->setInactive();

    PopupText = PopupMenu->getPointerToChildByName<TextBox>("popupText");
    popupButton = GUIMenu->getPointerToChildByName<HoverButton>("OKButton");
    InfoText = GUIMenu->getPointerToChildByName<TextBox>("InfoText");
    YesButton = YNMenu->getPointerToChildByName<HoverButton>("YesButton");
    NoButton = YNMenu->getPointerToChildByName<HoverButton>("NoButton");
    shopButton = GUIMenu->getPointerToChildByName<HoverButton>("ShopButton");
    mainMenuBut = GUIMenu->getPointerToChildByName<HoverButton>("MenuButton");
    EndButton = EndMenu->getPointerToChildByName<HoverButton>("Restart");


}

void GameGUI::draw()
{
    Manager->draw();
}

int GameGUI::update(ofVec2f& mousePos, bool& clicked, bool& pressed)
{
    InfoText->setPosition(ofVec2f(ofGetWindowWidth()/2, 50));
    Manager->update(mousePos, clicked, pressed);
    if(NoButton->getEventDataInt() > 2)
    {
        if(clicked)
        {

            NoButton->setClicked(false);

        return 0;
        }

    }
    else if(YesButton->getEventDataInt() > 2)
    {
        if(clicked)
        {
                    YesButton->setClicked(false);

        return 1;
        }

    }

    if(mainMenuBut->getEventDataInt() > 2)
    {
        mainMenuBut->setClicked(false);
        return 4;
    }

    if(EndButton->getEventDataInt() > 2)
    {
        EndButton->setClicked(false);
        return 5;
    }
    //-----------------logic for popup toggle---------------------

    if(popupButton->getClicked())
    {
        PopupMenu->setActive();

    }
    else
    {
        PopupMenu->setInactive();
    }
    return 3;

}

void GameGUI::setPopupText(std::string newText)
{
    PopupText->newSetText(newText);
}

void GameGUI::enablePopup()
{
    PopupMenu->setActive();
}

void GameGUI::setInfoText(std::string text)
{
    InfoText->newSetText(text);
}

void GameGUI::toggleYNButs()
{
    if(YNMenu->isActive())
    {
        YNMenu->setInactive();
    }
    else
    {
        YNMenu->setActive();
    }
}

void GameGUI::toggleEndScreen()
{
    if(EndMenu->isActive())
    {
        EndMenu->setInactive();
    }
    else
    {
        EndMenu->setActive();
    }
}


