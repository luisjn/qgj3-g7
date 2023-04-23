// -------------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------------

// Class declare and external libs required: -------------------------------------------------------------------------

#include "MapASCII.hpp"

// Constructor and destructor: ---------------------------------------------------------------------------------------

MapASCII::MapASCII(std::string new_map_path)
{
#ifdef DEBUG_MODE
	std::cout << "Map start...\n";
#endif
    InitializeMap(new_map_path);
#ifdef DEBUG_MODE
	std::cout << "Set map: "<< map_file_path <<"\n";
#endif
}

MapASCII::MapASCII()
{
#ifdef DEBUG_MODE
	std::cout << "Map start (no name)...\n";
#endif
}

MapASCII::~MapASCII()
{
#ifdef DEBUG_MODE
	std::cout << "LoadFile Closed.\n";
#endif
    delete map_ascii;
}

// Voids: ------------------------------------------------------------------------------------------------------------

void MapASCII::SetMap(std::string new_map_path)
{
    map_file_path = new_map_path;
}

void MapASCII::InitializeMap(std::string new_map_path)
{
    SetMap(new_map_path);
    LoadMap();
}

void MapASCII::ReadDimentionOfFile()
{
    map_file.open(map_file_path, std::ios::in); 
    if(map_file.fail()){
#ifdef DEBUG_MODE
        std::cout << "Error to open file... (" << map_file_path <<")\n"; 
#endif
    }
    if(!map_file.fail()){
#ifdef DEBUG_MODE
        std::cout << "File exist and can be open! (" << map_file_path <<")\n"; 
#endif
        if (map_file.is_open()) { 
            char charRead;
            longHorizontal=0;
            longVertical=1;

            while(map_file.good()) {
                map_file.get(charRead);
                if(map_file.eof()){
#ifdef DEBUG_MODE
                    std::cout << "(EOF!)\n";
#endif
                }
                if(!map_file.eof()){
                    if(charRead!=CHAR_LINE_BREAK){
#ifdef DEBUG_MODE
                        std::cout << charRead;
#endif
                        longHorizontal++;
                    }
                    if(charRead==CHAR_LINE_BREAK){
                        longHorizontal=0;
                        longVertical++;
#ifdef DEBUG_MODE
                        std::cout << "(JUMP)\n";
#endif
                    }
                }
            }
            if(!map_file.eof()){
#ifdef DEBUG_MODE
                std::cout << "ALERT: Error reading: " << map_file_path << "\n";
#endif
            }
            map_file.close(); 
        }
    }
#ifdef DEBUG_MODE
    std::cout << " Vertical: " << longVertical << "\n";
    std::cout << " Horizontal: " << longHorizontal << "\n";
#endif
}

void MapASCII::LoadMap()
{
#ifdef DEBUG_MODE
	std::cout << "LoadFile: " << map_file_path << "\n";
#endif
    ReadDimentionOfFile();

    map_ascii = new char*[longVertical];
    for(int i=0;i<longVertical;i++){
        char* vector = new char[longHorizontal];
        map_ascii[i]=vector;
    }

    map_file.open(map_file_path, std::ios::in); 
    if(map_file.fail()){
#ifdef DEBUG_MODE
        std::cout << "Error to open file... (" << map_file_path <<")\n"; 
#endif
    }
    if(!map_file.fail()){
#ifdef DEBUG_MODE
        std::cout << "File exist and can be open! (" << map_file_path <<")\n"; 
#endif
        if (map_file.is_open()) { 
#ifdef DEBUG_MODE
            std::cout << "File open...\n"; 
#endif
            char charRead;
            int i=0;
            int j=0;

            while(map_file.good()) {
                map_file.get(charRead);
                if(map_file.eof()){
#ifdef DEBUG_MODE
                    std::cout << "(EOF!)\n";
#endif
                }
                if(!map_file.eof()){
                    if(charRead!=CHAR_LINE_BREAK){
#ifdef DEBUG_MODE
                        std::cout << charRead;
#endif
                        
                        std::strncpy(&map_ascii[i][j], &charRead, 1);
                        j++;
                    }
                    if(charRead==CHAR_LINE_BREAK){
                        j=0;
                        i++;
#ifdef DEBUG_MODE
                        std::cout << "(JUMP)\n";
#endif
                    }
                }
            }
            if(!map_file.eof()){
#ifdef DEBUG_MODE
                std::cout << "ALERT: Error reading: " << map_file_path << "\n";
#endif
            }
            map_file.close(); 
        }
    }
}

void MapASCII::Draw()
{

    for(int i=0;i<longVertical;i++){
        for(int j=0;j<longHorizontal;j++){
            std::cout << map_ascii[i][j];
        }
        std::cout << "\n";
    }
}

void MapASCII::WriteMapToFile()
{
    // Write procedure (DANGER: Overwrite the file!!!):
    map_file.open(map_file_path, std::ios::out); 
    if (map_file.is_open()) {
        for (int i=0;i<longVertical;i++){
            for (int j=0;j<longHorizontal;j++){
                map_file << map_ascii[i][j]; //GenerateRandomChar(char("1")); // Inserting character.
            }
            if(i+1<longVertical){
                map_file << "\n"; // Inserting jump line.
            }
        }
        map_file.close();
    }
}

char** MapASCII::GetMapASCII()
{
    return map_ascii;
}

char MapASCII::GetChar(int x, int y)
{
    char toReturn = NULL;
    if ((x>=0) && (x<longHorizontal)){
        if ((y>=0) && (y<longVertical)){
            toReturn=map_ascii[x][y];
        }
    }
    return toReturn;
}

bool MapASCII::ChangeChar(int x, int y, char newASCII)
{
    bool result=false;
    if ((x>=0) && (x<longHorizontal)){
        if ((y>=0) && (y<longVertical)){
            map_ascii[x][y]=newASCII;
            result=true;
        }
    }
    return result;
}

// -------------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------------
