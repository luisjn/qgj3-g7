// -------------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------------

// Class declare and external libs required: -------------------------------------------------------------------------

#include "MenuBasic.hpp"

// Constructor and destructor: ---------------------------------------------------------------------------------------

MenuBasic::MenuBasic(int newMenuID)
{
    menuID = newMenuID;
    menuActive = true;
    optionSelected = 0;
    switch(menuID){
    case MENU_MAINMENU_CODE:
        x0=10;
        y0=10;
        break;
    case MENU_PAUSEMENU_CODE:
        x0=20;
        y0=20;
        break;
    default:
        x0=0;
        y0=0;
        break;
    }
}

MenuBasic::MenuBasic(int newMenuID, int x_0, int y_0)
{
    menuID = newMenuID;
    menuActive = true;
    x0=x_0;
    y0=y_0;
    optionSelected = 0;
}

MenuBasic::MenuBasic(int newMenuID, int x_0, int y_0, int d_x, int d_y)
{
    menuID = newMenuID;
    menuActive = true;
    x0=x_0;
    y0=y_0;
    dx=d_x;
    dy=d_y;
    optionSelected = 0;
}

MenuBasic::~MenuBasic()
{
    delete imgASCII;
}

// Voids: ------------------------------------------------------------------------------------------------------------

bool MenuBasic::GetMenuActive()
{
    return menuActive;
}

int MenuBasic::GetX0()
{
    return x0;
}

int MenuBasic::GetY0()
{
    return y0;
}

int MenuBasic::GetDX()
{
    return dx;
}

int MenuBasic::GetDY()
{
    return dy;
}

void MenuBasic::Input(int side_ID)
{
    switch (side_ID)
    {
    // Move spacecraft:
    case GAMEPLAY_MOVE_RIGHT:
        break;
    case GAMEPLAY_MOVE_LEFT:
        break;
    case GAMEPLAY_MOVE_UP:
        break;
    case GAMEPLAY_MOVE_DOWN:
        break;
    case GAMEPLAY_SHOOT:
        menuActive = false;
        break;
    // Move maps on level:
    case GAMEPLAY_MOVE_A:
        break;
    case GAMEPLAY_MOVE_D:
        break;
    case GAMEPLAY_MOVE_W:
        break;
    case GAMEPLAY_MOVE_S:
        break;
    case GAMEPLAY_JUMPMAINMENU:
        break;
    case GAMEPLAY_JUMPLEVEL_00:
        break;
    case GAMEPLAY_JUMPLEVEL_01:
        break;
    }
}

void MenuBasic::Update()
{
    //menuActive = false;
}

std::string MenuBasic::Draw()
{
    std::string response;
    switch(menuID){
    case MENU_MAINMENU_CODE:
        response="MainMenu";
        break;
    case MENU_PAUSEMENU_CODE:
        response="PAUSEMenu";
        break;
    default:
        response="Menu";
        break;
    }

    return response;
}

int MenuBasic::GetMenuID()
{
    return menuID;
}

// -------------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------------