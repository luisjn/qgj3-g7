#pragma once
// External libs required: -------------------------------------------------------------------------------------------

#include <iostream>
#include <fstream>
#include "Settings.h" // General Game DEFINEs


// Class declare: ----------------------------------------------------------------------------------------------------

class MapASCII
{
private:
    bool errorCode;
    int longHorizontal;
    int longVertical;
    std::string map_file_path;
    std::fstream map_file;
    char** map_ascii;
    void ReadDimentionOfFile();
public:
    char** GetMapASCII();
    char GetChar(int x, int y);
    //bool ChangeChar(int x, int y, char newASCII);
    void Draw();
    void LoadMap();
    void WriteMapToFile();
    void SetMap(std::string new_map_path);
    void InitializeMap(std::string new_map_path);
    int GetMapSizeX();
    int GetMapSizeY();
    MapASCII();
    MapASCII(std::string new_map_path);
    ~MapASCII();
};