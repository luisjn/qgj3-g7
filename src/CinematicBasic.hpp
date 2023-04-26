#pragma once
// External libs required: -------------------------------------------------------------------------------------------

#include <iostream>
#include <fstream>
#include <sstream>
#include "Settings.h" // General Game DEFINEs

// Class declare: ----------------------------------------------------------------------------------------------------

class CinematicBasic
{
private:
    int menuID;
    bool menuActive;
    bool escapeKey;
    int x0, y0;

    int longHorizontal;
    int longVertical;
    std::string img_file_path;
    std::fstream img_file;
    char** img_ascii;
    void ReadDimentionOfFile();
    void SendMoveUp();
    void SendMoveDown();
    void SendEscape();
    void InitStates(int newMenuID, int x_0, int y_0);

public:
    CinematicBasic(int newMenuID, int x_0, int y_0,std::string new_map_path);

    ~CinematicBasic();

    void SetImg(std::string new_map_path);
    void InitializeImg(std::string new_map_path);
    void LoadImg();
    std::string ImgToString();

    int GetX0();
    int GetY0();
    int GetDX();
    int GetDY();
    int GetMenuID();
    bool GetMenuActive();
    int Update();
    void Input(int side_ID);
    std::string Draw();
};
