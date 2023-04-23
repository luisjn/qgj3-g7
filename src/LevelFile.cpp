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
    LoadLevelFileInfo(); // This must be run PREVIOUS to load Maps (have Maps info from file)

    int jhk;
    std::cout << "pausa de Int: ";
    std::cin >> jhk;

    LoadMaps(); // Load all maps info fo the level (run "LoadLevelFileInfo()" previous!!!).
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

void LevelFile::LoadLevelFileInfo()
{
    level_file_path=GAME_LEVEL_NAME_INITIAL_PATH+
        std::to_string(levelID)+
        GAME_LEVEL_EXTENTION;
#ifdef DEBUG_MODE
    std::cout << "LevelFile: "<< level_file_path <<"\n";
#endif
    level_file.open(level_file_path, std::ios::in); 
    if (level_file.is_open()) {
#ifdef DEBUG_MODE
        std::cout << "LevelFile Open: "<< level_file_path <<"\n";
#endif
        int string_line=0;
        while(level_file.good()) {
            std::string textLine;
            std::getline(level_file,textLine);
            std::string restostring = textLine;
            std::string TextToInt;
            int string_val=0;
            int string_pos=0;
            int intValue;
            while(restostring.length()>0){
                TextToInt = restostring.substr(0,restostring.find(';'));
                if(string_line==0){
                    if(string_val==0){ // (0;0) = maxMaps_x
                        intValue = stoi(TextToInt);
                        maxMaps_x=intValue;
#ifdef DEBUG_MODE
                        std::cout << "maxMaps_x: "<< maxMaps_x << "\n";
#endif
                    }
                    if(string_val==1){ // (0;1) = maxMaps_y
                        intValue = stoi(TextToInt);
                        maxMaps_y=intValue;
#ifdef DEBUG_MODE
                        std::cout << "maxMaps_y: "<< maxMaps_y << "\n";
#endif
                    }
                }
                if(string_line==1){
                    if(string_val==0){ // (1;0) = activeMap_x
                        intValue = stoi(TextToInt);
                        activeMap_x=intValue;
#ifdef DEBUG_MODE
                        std::cout << "activeMap_x: "<< activeMap_x << "\n";
#endif
                    }
                    if(string_val==1){ // (1;1) = activeMap_y
                        intValue = stoi(TextToInt);
                        activeMap_y=intValue;
#ifdef DEBUG_MODE
                        std::cout << "activeMap_y: "<< activeMap_y << "\n";
#endif
                    }
                }
                string_val++;
                string_pos = restostring.find(';')+1;
                restostring = restostring.substr(string_pos,restostring.length());
            }
#ifdef DEBUG_MODE
            std::cout << "Jump line...\n";
#endif
            string_line++;
        }
        level_file.close();
    }
}

// -------------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------------
