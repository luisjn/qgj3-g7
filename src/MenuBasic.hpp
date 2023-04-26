#pragma once
// External libs required: -------------------------------------------------------------------------------------------

#include <iostream>
#include <fstream>
#include <sstream>
#include "Settings.h" // General Game DEFINEs

// Class declare: ----------------------------------------------------------------------------------------------------

class MenuBasic
{
private:
    int menuID;
    int optionState, maxOptions;
    bool menuActive;
    bool selectedOption;
    bool escapeKey;
    int x0, y0;
    int cursor_x0, cursor_y0, cursor_jump;

    int longHorizontal;
    int longVertical;
    std::string img_file_path;
    std::fstream img_file;
    char** img_ascii;
    void ReadDimentionOfFile();
    void SendMoveUp();
    void SendMoveDown();
    void SendOK();
    void SendEscape();
    void InitStates(int newMenuID, int x_0, int y_0);

public:
    MenuBasic(int newMenuID, int x_0, int y_0,std::string new_map_path);

    ~MenuBasic();

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
