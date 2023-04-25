#pragma once
// External libs required: -------------------------------------------------------------------------------------------

#include <iostream>
#include "Settings.h" // General Game DEFINEs
#include "ImageASCII.hpp" // New mod for char array use

// Class declare: ----------------------------------------------------------------------------------------------------

class MenuBasic
{
private:
    bool menuActivated;
    ImageASCII* image;
    int x0, y0;
public:
    ImageASCII* GetImage();
    int GetX0();
    int GetY0();
    void LoadMenu();
    void LoadMenu(int dx, int dy);
    bool OnActive();
    void Run();
    void Input(int side_ID);
    MenuBasic();
    MenuBasic(int x_0, int y_0, int dx, int dy);
    ~MenuBasic();
};