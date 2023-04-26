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
}

MenuBasic::~MenuBasic()
{
}

// Voids: ------------------------------------------------------------------------------------------------------------

bool MenuBasic::GetMenuActive()
{
    return menuActive;
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