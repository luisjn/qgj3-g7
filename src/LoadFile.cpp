// -------------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------------

// Class declare and external libs required: -------------------------------------------------------------------------

//#include <iostream>
//#include <fstream>
//#include <string>
#include "LoadFile.hpp"

// Constructor and destructor: ---------------------------------------------------------------------------------------
char LoadFile::GenerateRandomChar(char startChar)
{
    char randomChar;
    randomChar = char(startChar);// + rand()%260);
    return randomChar;    
}

LoadFile::LoadFile()
{
#ifdef DEBUG_MODE
	std::cout << "LoadFile Start...\n";
#endif

    // Initiate random character generator (for test propourse):
    srand(time(0));

    std::cout << "LoadFile Start...\n";

    // Vars to open a file:
    std::string file_path;
    std::fstream new_file;
    file_path = LEVEL_00_PATH; // To load the frist file
    const int longHorizontal=60;
    const int longVertical=12;

    // Write procedure (DANGER: Overwrite the file!!!):
/*
    new_file.open(file_path, std::ios::out); 
    if (new_file.is_open()) {
        for (int i=0;i<longVertical;i++){
            for (int j=0;j<longHorizontal;j++){
                new_file << char("a"); //GenerateRandomChar(char("1")); // Inserting character.
            }
            new_file << "\n"; // Inserting jump line.
        }
        new_file.close();
    }
*/

    // Open a file to perform read operation using file object.
    new_file.open(file_path, std::ios::in); 
    if(!new_file.fail()){
        std::cout << "File exist and can be open! (" << file_path <<")\n"; 
        if (new_file.is_open()) { 
            char charRead;
            while(new_file.good()) {
                new_file.get(charRead);
                if(charRead!='\n'){
                    std::cout << charRead;
                }
                if(charRead=='\n'){
                    std::cout << "(JUMP)\n";
                }
            }
            if(!new_file.eof()){
                std::cout << "ALERT: Error reading: " << file_path << "\n";
            }
            new_file.close(); 
        }
    }
    if(new_file.fail()){
        std::cout << "Error to open file... (" << file_path <<")\n"; 
    }

/*
ifstream in(filePath);
    char c;

    if(in.is_open()) {
    }
    in.close();
*/    


    // PAUSE (only to debug):
    int a;
    std::cout << " * => Input Int: ";
    std::cin >> a;
}

LoadFile::~LoadFile()
{
#ifdef DEBUG_MODE
	std::cout << "LoadFile Closed.\n";
#endif
}

// Voids: ------------------------------------------------------------------------------------------------------------

void LoadFile::LoadObject(int objID)
{
#ifdef DEBUG_MODE
	std::cout << "LoadFile: " << objID << "\n";
#endif
}

// -------------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------------
