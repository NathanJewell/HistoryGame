
#pragma once
#include <string.h>
#include <vector>

template<class T>
std::string typeToString(T toChange) //usage example... typeToString<double>(mydouble) changes given double to string
{
    std::stringstream ss;
    ss << toChange;
    std::string var;
    ss >> var;
    return var;
}

template<class T>   //usage.... stringToType<double>("12.34")
T stringToType(std::string toChange)
{
    std::stringstream ss;
    ss << toChange;
    T var;
    ss >> var;
    return var;
}

template<class T>
void parseLineToData(T& putin, std::string line, std::string toFind, bool ignoreSpaces)
{
    int charPerLine = 40;
    bool isSpace = false;
    int lastChar = 0;
    int loc = line.find(toFind);    //find the escape sequence
    loc+=toFind.size();             //move location to end of sequence

    if(ignoreSpaces)
    {
        while(line[loc] == ' ')         //move location past all spaces
        {
            loc++;
        }
    }

    std::string output = line.substr(loc);      //get the string from the end of the sequence+
    for(int i = 0; i<output.size();i++)
    {
//        if(output[i] == '/' && output[i+1] == 'n')
//        {
//             std::string tmp = output.substr(0, i-1);
//             tmp+= "\n";
//             tmp+=output.substr(i+2);
//             output = tmp;
//             i++;
//        }
        if(output[i] == ' ' && i-lastChar > 40)
        {
            lastChar = i;
            std::string tmp = output.substr(0, i);
            tmp+= "\n";
            tmp+=output.substr(i+1);
            output = tmp;
            i++;
        }
    }
    try
    {
        putin=output;
        return;
        throw 20;
    }
    catch(int e)
    {

    }
    putin = stringToType<T>(output);
    return;

}
