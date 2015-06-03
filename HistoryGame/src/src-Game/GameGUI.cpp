#include "GameGUI.h"

GameGUI::GameGUI()
{
    Manager = new MenuManager; // creates a new Menu manager
    Menu GUI(ofVec2f(0,0)); // creating the options menu
    Menu popup(ofVec2f(0, 0));


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
                            ofVec2f(ofGetWindowWidth()/2, ofGetWindowHeight()/2),
                            Manager->getFontPointer("PopupFont")
                                );

    MenuEntity *OKButton;
    OKButton = new HoverButton(
                            ofVec2f(200, 200),
                            Manager->getTexturePointer("OpenNormal"),
                            Manager->getTexturePointer("OpenHovered"),
                            Manager->getTexturePointer("OpenClicked"),
                            Manager->getTexturePointer("OpenClicked"),
                            Manager->getTexturePointer("OpenClickedHovered"),
                            Manager->getTexturePointer("OpenClickedHovered")
                                    );
    MenuEntity *ShopButton;
    ShopButton = new HoverButton(
                            ofVec2f(400, 200),
                            Manager->getTexturePointer("NoExitNormal"),
                            Manager->getTexturePointer("NoExitHovered"),
                            Manager->getTexturePointer("NoExitPressed"),
                            Manager->getTexturePointer("NoExitPressed"),
                            Manager->getTexturePointer("NoExitPressed"),
                            Manager->getTexturePointer("NoExitPressed")
                                    );

    MenuEntity *PopupBG;
    PopupBG = new MenuBackground(ofVec2f(ofGetWindowWidth()/2, ofGetWindowHeight()/2),
                                 Manager->getTexturePointer("PopupBG"),
                                 false
                                    );
    MenuEntity *infoBox;
    infoBox = new TextBox("Swag",
                          ofVec2f(10, 10),
                          Manager->getFontPointer("PopupFont"));

    GUI.addEntity(*No, "NoButton");
    GUI.addEntity(*Yes, "YesButton");
    GUI.addEntity(*infoBox, "InfoText");
    //GUI.addEntity(*ShopButton, "ShopButton");

    popup.addEntity(*PopupBG, "BG");
    popup.addEntity(*popupText, "popupText");
    GUI.addEntity(*OKButton, "OKButton");


    Manager->addMenu(GUI, "GUIMenu");
    Manager->addMenu(popup, "popupMenu");


    GUIMenu = Manager->getMenuPointerByName("GUIMenu");
    GUIMenu->setActive();

    PopupMenu = Manager->getMenuPointerByName("popupMenu");
    PopupMenu->setInactive();

    PopupText = PopupMenu->getPointerToChildByName<TextBox>("popupText");
    popupButton = GUIMenu->getPointerToChildByName<HoverButton>("OKButton");
    InfoText = GUIMenu->getPointerToChildByName<TextBox>("InfoText");
    YesButton = GUIMenu->getPointerToChildByName<HoverButton>("YesButton");
    NoButton = GUIMenu->getPointerToChildByName<HoverButton>("NoButton");
    shopButton = GUIMenu->getPointerToChildByName<HoverButton>("ShopButton");


}

void GameGUI::draw()
{
    Manager->draw();
}

int GameGUI::update(ofVec2f& mousePos, bool& clicked, bool& pressed)
{
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
