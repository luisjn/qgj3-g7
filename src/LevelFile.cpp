// -------------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------------

// Class declare and external libs required: -------------------------------------------------------------------------

#include "LevelFile.hpp"

// Constructor and destructor: ---------------------------------------------------------------------------------------

LevelFile::LevelFile(int lID)
{
#ifdef DEBUG_MODE
    std::cout << "LevelFile Start...\n";
#endif
    levelID = lID;
    maxMaps_x=3;
    maxMaps_y=3;
    activeMap_x=0;
    activeMap_y=0;
    LoadMaps();
}

LevelFile::~LevelFile()
{
    delete maps_ASCII;
}

// Voids: ------------------------------------------------------------------------------------------------------------

char LevelFile::GenerateRandomChar(char startChar)
{
    char randomChar;
    randomChar = char(startChar + rand()%26);
    return randomChar;    
}

void LevelFile::LoadMaps()
{
    maps_ASCII = new MapASCII*[maxMaps_y];
    for(int i=0;i<maxMaps_y;i++){
        MapASCII* vector = new MapASCII[maxMaps_x];
        maps_ASCII[i]=vector;
    }
    std::string pathMap;
    for (int i=0;i<maxMaps_y;i++){
        for (int j=0;j<maxMaps_x;j++){
            pathMap=
                GAME_MAP_NAME_INITIAL_PATH+
                std::to_string(levelID)+
                GAME_MAP_NAME_SEPARATION+
                std::to_string(i)+
                GAME_MAP_NAME_SEPARATION+
                std::to_string(j)+
                GAME_MAP_EXTENTION;
#ifdef DEBUG_MODE
            std::cout << pathMap << "(" << i << ";" << j <<")\n";
#endif
            maps_ASCII[i][j].InitializeMap(pathMap);
#ifdef DEBUG_MODE
            maps_ASCII[i][j].Draw();
#endif
        }
#ifdef DEBUG_MODE
        std::cout << "\n";
#endif
    }
}

char** LevelFile::GetMapASCII()
{
    return maps_ASCII[activeMap_x][activeMap_y].GetMapASCII();
}

// -------------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------------
