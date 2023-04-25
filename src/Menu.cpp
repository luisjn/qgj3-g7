// -------------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------------

// Class declare and external libs required: -------------------------------------------------------------------------

#include "Menu.hpp"

// Constructor and destructor: ---------------------------------------------------------------------------------------

MenuBasic::MenuBasic()
{
    menuActivated=true;
    x0=0;
    y0=0;
    LoadMenu();
}

MenuBasic::MenuBasic(int x_0, int y_0, int dx, int dy)
{
    menuActivated=true;
    x0=x_0;
    y0=y_0;
    LoadMenu(dx,dy);
}

MenuBasic::~MenuBasic()
{
    delete image;
}

// Voids: ------------------------------------------------------------------------------------------------------------

void MenuBasic::LoadMenu(int dx, int dy)
{
    image = new ImageASCII(dx,dy,'K');
}

void MenuBasic::LoadMenu()
{
    image = new ImageASCII(6,10,'K');
}

ImageASCII* MenuBasic::GetImage()
{
    return image;
}

int MenuBasic::GetX0()
{
    return x0;
}

int MenuBasic::GetY0()
{
    return y0;
}

bool MenuBasic::OnActive()
{
    return menuActivated;
}

void MenuBasic::Run()
{
//    std::cout << "\nMenu\n";
}

void MenuBasic::Input(int side_ID)
{
    switch(side_ID){
        // Move spacecraft:
        case GAMEPLAY_MOVE_RIGHT:
            break;
        case GAMEPLAY_MOVE_LEFT:
            break;
        case GAMEPLAY_MOVE_UP:
            break;
        case GAMEPLAY_MOVE_DOWN:
            break;
        case GAMEPLAY_MOVE_A:
            break;
        case GAMEPLAY_MOVE_D:
            break;
        case GAMEPLAY_MOVE_W:
            break;
        case GAMEPLAY_MOVE_S:
            break;
        case GAMEPLAY_SHOT:
            menuActivated=false;
            break;
        case GAMEPLAY_JUMPLEVEL_00:
            break;
        case GAMEPLAY_JUMPLEVEL_01:
            break;
    }
}


// -------------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------------
