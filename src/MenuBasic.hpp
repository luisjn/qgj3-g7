#pragma once
// External libs required: -------------------------------------------------------------------------------------------

#include <iostream>
#include "Settings.h" // General Game DEFINEs

// Class declare: ----------------------------------------------------------------------------------------------------

class MenuBasic
{
private:
    int menuID;
    bool menuActive;
public:
    MenuBasic(int newMenuID);
    ~MenuBasic();
    int GetMenuID();
    bool GetMenuActive();
    void Update();
    void Input(int side_ID);
    std::string Draw();
};
