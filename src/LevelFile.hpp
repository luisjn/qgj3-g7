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
    std::string level_file_path;
    std::string level_text;
    int level_text_dx;
    int level_text_dy;
    std::fstream level_file;
    void LoadMap(int x, int y);
    void UnloadMap(int x, int y);
    void LoadAllMaps();
    void LoadLevelFileInfo();
    void InitializeMapMatrix();
public:
    char** GetMapASCII();

    std::string GetHistoryText();
    int GetHistoryTextX();
    int GetHistoryTextY();
    int GetActiveMapX();
    int GetActiveMapY();

    void MoveMapUp();
    void MoveMapDown();
    void MoveMapLeft();
    void MoveMapRight();
    int GetMapSizeX();
    int GetMapSizeY();
    LevelFile(int lID);
    ~LevelFile();
};