#pragma once
// External libs required: -------------------------------------------------------------------------------------------

#include <iostream>
#include <fstream>
//#include <sstream>
#include "Settings.h" // General Game DEFINEs


// Class declare: ----------------------------------------------------------------------------------------------------

class LoadFile
{
private:
    bool errorCode;
    char GenerateRandomChar(char startChar);
public:
    void LoadObject(int objID);
    LoadFile();
    ~LoadFile();
};