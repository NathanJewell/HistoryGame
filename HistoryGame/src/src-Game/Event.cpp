#include "Event.h"

Event::Event()
{

}

Event::Event (int tn, int yn, int nn, std::string na, std::string des, std::string room, int da)
{
    //assigning all variables
    thisEventNum = tn;
    yesEventNum = yn;
    noEventNum = nn;
    name = na;
    description = des;
    roomType = room;
    date = da;
}

Event::Event (int tn)
{

}

Event Event::doNextEvent(bool which)  //if which == true the player clicked yes
{
    if(which)
    {
        return loadEvent(yesEventNum);
    }
    else
    {
        return loadEvent(noEventNum);
    }
}

std::string Event::getName()
{
    return name;
}

std::string Event::getDescription()
{
    return description;
}

std::string Event::getRoomType()
{
    return roomType;
}

int Event::getDate()
{
    return date;
}

int Event::getNextEventNum(bool which)
{
    if(which)
    {
        return yesEventNum;
    }
    return noEventNum;oi
}

std::vector<std::string> getRoomTextureData()
{
    return roomTextureData;
}


