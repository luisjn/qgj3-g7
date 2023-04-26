// -------------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------------

// Class declare and external libs required: -------------------------------------------------------------------------

#include "CinematicBasic.hpp"

// Constructor and destructor: ---------------------------------------------------------------------------------------

CinematicBasic::CinematicBasic(int newMenuID, int x_0, int y_0,std::string new_map_path)
{
    InitStates(newMenuID,x_0,y_0);
    InitializeImg(new_map_path);
}

CinematicBasic::~CinematicBasic()
{
    if(img_ascii!=NULL){
        delete img_ascii;
        img_ascii = NULL;
    }
}

// Voids: ------------------------------------------------------------------------------------------------------------

void CinematicBasic::InitStates(int newMenuID, int x_0, int y_0)
{
    menuID = newMenuID;
    menuActive = true;
    x0=x_0;
    y0=y_0;
    escapeKey = false;
    img_ascii = NULL;
}

void CinematicBasic::SetImg(std::string new_map_path)
{
    img_file_path = new_map_path;
}

void CinematicBasic::InitializeImg(std::string new_map_path)
{
    SetImg(new_map_path);
    LoadImg();
}

void CinematicBasic::ReadDimentionOfFile()
{
    img_file.open(img_file_path, std::ios::in); 
    if(img_file.fail()){
    }
    if(!img_file.fail()){
        if (img_file.is_open()) { 
            char charRead;
            longHorizontal=0;
            longVertical=1;
            while(img_file.good()) {
                img_file.get(charRead);
                if(img_file.eof()){
                }
                if(!img_file.eof()){
                    if(charRead!=CHAR_LINE_BREAK){
                        longHorizontal++;
                    }
                    if(charRead==CHAR_LINE_BREAK){
                        longHorizontal=0;
                        longVertical++;
                    }
                }
            }
            if(!img_file.eof()){
            }
            img_file.close(); 
        }
    }
}

void CinematicBasic::LoadImg()
{
    ReadDimentionOfFile();
    img_ascii = new char*[longVertical];
    for(int i=0;i<longVertical;i++){
        char* vector = new char[longHorizontal];
        img_ascii[i]=vector;
    }
    img_file.open(img_file_path, std::ios::in); 
    if(img_file.fail()){
    }
    if(!img_file.fail()){
        if (img_file.is_open()) { 
            char charRead;
            int i=0;
            int j=0;
            while(img_file.good()) {
                img_file.get(charRead);
                if(img_file.eof()){
                }
                if(!img_file.eof()){
                    if(charRead!=CHAR_LINE_BREAK){
                        std::strncpy(&img_ascii[i][j], &charRead, 1);
                        j++;
                    }
                    if(charRead==CHAR_LINE_BREAK){
                        j=0;
                        i++;
                    }
                }
            }
            if(!img_file.eof()){
            }
            img_file.close();
        }
    }
}

bool CinematicBasic::GetMenuActive()
{
    return menuActive;
}

int CinematicBasic::GetX0()
{
    return x0;
}

int CinematicBasic::GetY0()
{
    return y0;
}

int CinematicBasic::GetDX()
{
    return longHorizontal;
}

int CinematicBasic::GetDY()
{
    return longVertical;
}

void CinematicBasic::SendMoveUp()
{
}

void CinematicBasic::SendMoveDown()
{
}

void CinematicBasic::SendEscape()
{
        escapeKey=true;
}

void CinematicBasic::Input(int side_ID)
{
    switch (side_ID)
    {
    // Move spacecraft:
    case GAMEPLAY_MOVE_RIGHT:
        //SendMoveDown();
        SendEscape();
        break;
    case GAMEPLAY_MOVE_LEFT:
        //SendMoveUp();
        SendEscape();
        break;
    case GAMEPLAY_MOVE_UP:
        //SendMoveUp();
        SendEscape();
        break;
    case GAMEPLAY_MOVE_DOWN:
        //SendMoveDown();
        SendEscape();
        break;
    // Move maps on level:
    case GAMEPLAY_MOVE_A:
        //SendMoveUp();
        SendEscape();
        break;
    case GAMEPLAY_MOVE_D:
        //SendMoveDown();
        SendEscape();
        break;
    case GAMEPLAY_MOVE_W:
        //SendMoveUp();
        SendEscape();
        break;
    case GAMEPLAY_MOVE_S:
        //SendMoveDown();
        SendEscape();
        break;
    case GAMEPLAY_SHOOT:
        //SendOK();
        break;
    case GAMEPLAY_INTRO:
        SendEscape();
        break;
    case GAMEPLAY_EXIT:
        SendEscape();
        break;
    case GAMEPLAY_JUMPMAINMENU:
        SendEscape();
        break;
    case GAMEPLAY_JUMPLEVEL_00:
        break;
    case GAMEPLAY_JUMPLEVEL_01:
        break;
    }
}

int CinematicBasic::Update()
{
    int result=MENU_ACTION_NULL;
    switch(menuID){
    case CINEMATIC_INITIAL:
        if(menuActive){
            if(escapeKey){
                result=MENU_ACTION_BACK_MAINMENU;
                escapeKey = false;
                menuActive = false;
            }
        }
        break;
    case CINEMATIC_END:
        if(menuActive){
            if(escapeKey){
                result=MENU_ACTION_CONTINUE_GAME;
                escapeKey = false;
                menuActive = false;
            }
        }
        break;
    case CINEMATIC_ENDGOOD:
        if(menuActive){
            if(escapeKey){
                result=MENU_ACTION_CONTINUE_GAME;
                escapeKey = false;
                menuActive = false;
            }
        }
        break;
    case CINEMATIC_ENDFAIL:
        if(menuActive){
            if(escapeKey){
                result=MENU_ACTION_CONTINUE_GAME;
                escapeKey = false;
                menuActive = false;
            }
        }
        break;
    case CINEMATIC_CREDITS:
        if(menuActive){
            if(escapeKey){
                result=MENU_ACTION_CONTINUE_GAME;
                escapeKey = false;
                menuActive = false;
            }
        }
        break;
    default:
        break;
    }
    return result;
}

std::string CinematicBasic::ImgToString()
{
    std::string response = "";
    for(int y=0;y<longVertical;y++)
    {
        for(int x=0;x<longHorizontal;x++)
        {
            response=response+ img_ascii[y][x]; 
	    }
        response=response+ "\n";
    }
    return response;
}

std::string CinematicBasic::Draw()
{
    std::string response;
    if(img_ascii!=NULL){
        response=ImgToString();
    }
    return response;
}

int CinematicBasic::GetMenuID()
{
    return menuID;
}

// -------------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------------