#pragma once

#include "ofMain.h"
#include "Util.h"
class Event
{
public:
    Event();
    Event(int tn, int yn, int nn, std::string name, std::string des, std::string room, int date);
    Event(int tn);

    Event doNextEvent(bool which);  //return the next event to display

    std::string getName();
    std::string getDescription();
    std::string getRoomType();
    int getDate();
    int getNextEventNum(bool which);
    std::vector<std::string> getRoomTextureData();
    std::vector<std::string> roomTextureData;
private:
    int thisEventNum, yesEventNum, noEventNum;  //ID numbers for this event and its following events
    std::string name, description, roomType;
    int date;

};

inline std::vector<std::string> loadEventFile(int eventNum)
{
    //add stuff to create full file path
    std::string filePath ="C:/OpenFrameworks/apps/HistoryGame/HistoryGame/bin/data/Events/" + typeToString<int>(eventNum) + ".txt";
    std::cout << filePath << std::endl;
    std::ifstream eventFile(filePath.c_str());
    std::string line;
    std::vector<std::string> lines;     //vector of all lines from file
    if(eventFile.is_open())
    {
        while(getline(eventFile,line))     //while there is another line in the file continue to load
        {
            lines.push_back(line);
        }
        eventFile.close();
    }

    return lines;
}

inline Event loadEvent(int eventNum)
{
    std::vector<std::string> fileLines = loadEventFile(eventNum);
    for(int ii = 0; ii < fileLines.size(); ii++)
    {
        parseLineToData<std::string>(fileLines[ii], fileLines[ii], "=", true);
    }
    std::cout << " swag" << fileLines[7] << std::endl;
    Event tempEvent(stringToType<int>(fileLines[0]),
                    stringToType<int>(fileLines[1]),
                    stringToType<int>(fileLines[2]),
                    fileLines[3],
                    fileLines[4],
                    fileLines[5],
                    stringToType<int>(fileLines[6]));

    if(fileLines[7]=="ROOM")
    {
        for(int ii =8; ii<fileLines.size();ii++)
        {
            tempEvent.roomTextureData.push_back(fileLines[ii]);
        }
    }
    return tempEvent;

}




