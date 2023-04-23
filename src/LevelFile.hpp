#pragma once
// External libs required: -------------------------------------------------------------------------------------------

#include <iostream>
#include <fstream>
#include <sstream> // LF: Manage string names for maps to include
#include "Settings.h" // General Game DEFINEs
#include "MapASCII.hpp" // LF: Add file loadding library


// Class declare: ----------------------------------------------------------------------------------------------------

class LevelFile
{
private:
    char GenerateRandomChar(char startChar);
    int levelID,maxMaps_x,maxMaps_y,activeMap_x,activeMap_y;
    MapASCII** maps_ASCII; // LF: In memory object to file interact - Maps
    void LoadMaps();
public:
    char** GetMapASCII();
    void MovePlayer();
    void LoadLevel();
    LevelFile(int lID);
    ~LevelFile();
};