#pragma once
// External libs required: -------------------------------------------------------------------------------------------

#include <iostream>
#include "Settings.h" // General Game DEFINEs

// Class declare: ----------------------------------------------------------------------------------------------------

class MenuBasic
{
private:
    int menuID;
    int optionSelected;
    bool menuActive;
    int x0, y0, dx, dy;
    char** imgASCII;
public:
    MenuBasic(int newMenuID);
    MenuBasic(int newMenuID, int x_0, int y_0);
    MenuBasic(int newMenuID, int x_0, int y_0, int d_x, int d_y);
    ~MenuBasic();
    int GetX0();
    int GetY0();
    int GetDX();
    int GetDY();
    int GetMenuID();
    bool GetMenuActive();
    void Update();
    void Input(int side_ID);
    std::string Draw();
};
