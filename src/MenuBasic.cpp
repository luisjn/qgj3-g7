// -------------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------------

// Class declare and external libs required: -------------------------------------------------------------------------

#include "MenuBasic.hpp"

// Constructor and destructor: ---------------------------------------------------------------------------------------

MenuBasic::MenuBasic(int newMenuID, int x_0, int y_0,std::string new_map_path)
{
    InitStates(newMenuID,x_0,y_0);
    InitializeImg(new_map_path);
}

MenuBasic::~MenuBasic()
{
    if(img_ascii!=NULL){
        delete img_ascii;
        img_ascii = NULL;
    }
}

// Voids: ------------------------------------------------------------------------------------------------------------

void MenuBasic::InitStates(int newMenuID, int x_0, int y_0)
{
    menuID = newMenuID;
    menuActive = true;
    x0=x_0;
    y0=y_0;
    optionState = 0;
    selectedOption=false;
    escapeKey = false;
    img_ascii = NULL;

    switch(menuID){
    case MENU_MAINMENU_CODE:
        maxOptions=5;
        cursor_x0=12;
        cursor_y0=16;
        cursor_jump=2;
        break;
    case MENU_PAUSEMENU_CODE:
        maxOptions=3;
        cursor_x0=3;
        cursor_y0=1;
        cursor_jump=1;
        break;
    default:
        maxOptions=2;
        break;
    } 
}

void MenuBasic::SetImg(std::string new_map_path)
{
    img_file_path = new_map_path;
}

void MenuBasic::InitializeImg(std::string new_map_path)
{
    SetImg(new_map_path);
    LoadImg();
}

void MenuBasic::ReadDimentionOfFile()
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

void MenuBasic::LoadImg()
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
    return longHorizontal;
}

int MenuBasic::GetDY()
{
    return longVertical;
}

void MenuBasic::SendMoveUp()
{
    int new_selected = optionState-1;
    if(new_selected>=0){
        optionState = new_selected;
    }
    if(new_selected<0){
        optionState = maxOptions;
    }
}

void MenuBasic::SendMoveDown()
{
    int new_selected = optionState+1;
    if(new_selected<=maxOptions){
        optionState = new_selected;
    }
    if(new_selected>maxOptions){
        optionState = 0;
    }
}

void MenuBasic::SendOK()
{
        selectedOption = true;
}

void MenuBasic::SendEscape()
{
        escapeKey=true;
}

void MenuBasic::Input(int side_ID)
{
    switch (side_ID)
    {
    // Move spacecraft:
    case GAMEPLAY_MOVE_RIGHT:
        SendMoveDown();
        break;
    case GAMEPLAY_MOVE_LEFT:
        SendMoveUp();
        break;
    case GAMEPLAY_MOVE_UP:
        SendMoveUp();
        break;
    case GAMEPLAY_MOVE_DOWN:
        SendMoveDown();
        break;
    // Move maps on level:
    case GAMEPLAY_MOVE_A:
        SendMoveUp();
        break;
    case GAMEPLAY_MOVE_D:
        SendMoveDown();
        break;
    case GAMEPLAY_MOVE_W:
        SendMoveUp();
        break;
    case GAMEPLAY_MOVE_S:
        SendMoveDown();
        break;
    case GAMEPLAY_SHOOT:
        SendOK();
        break;
    case GAMEPLAY_INTRO:
        SendOK();
        break;
    case GAMEPLAY_EXIT:
        SendEscape();
        break;
    case GAMEPLAY_JUMPMAINMENU:
        break;
    case GAMEPLAY_JUMPLEVEL_00:
        break;
    case GAMEPLAY_JUMPLEVEL_01:
        break;
    }
}

int MenuBasic::Update()
{
    int result=MENU_ACTION_NULL;
    switch(menuID){
    case MENU_MAINMENU_CODE:
/*
MainMenu:
    {0} jugar
    {1} introduccion
    {2} sonido
    {3} ayuda
    {4} cargar
    {5} salir 
*/
        if(menuActive){
            if(selectedOption){
                selectedOption = false;
                switch(optionState){
                    case 0:
                        result=MENU_ACTION_CONTINUE_GAME;
                        menuActive = false;
                        break;
                    case 1:
                        result=MENU_ACTION_GO_PRESENTATION;
                        break;
                    case 2:
                        result=MENU_ACTION_SWITCH_SOUND;
                        break;
                    case 3:
                        result=MENU_ACTION_GET_HELP;
                        break;
                    case 4:
                        result=MENU_ACTION_LOAD_SAVE;
                        break;
                    case 5:
                        result=MENU_ACTION_EXIT_GAME;
                        menuActive = false;
                        break;
                    default:
                        break;
                }
            }
            if(escapeKey){
                result=MENU_ACTION_EXIT_GAME;
                escapeKey = false;
                menuActive = false;
            }
        }
        break;
    case MENU_PAUSEMENU_CODE:
/*
PAUSA:
    {0} jugar
    {1} sonido
    {2} menu principal
    {3} salir
*/
        if(menuActive){
            if(selectedOption){
                selectedOption = false;
                switch(optionState){
                    case 0:
                        result=MENU_ACTION_CONTINUE_GAME;
                        menuActive = false;
                        break;
                    case 1:
                        result=MENU_ACTION_SWITCH_SOUND;
                        break;
                    case 2:
                        result=MENU_ACTION_BACK_MAINMENU;
                        menuActive = false;
                        break;
                    case 3:
                        result=MENU_ACTION_EXIT_GAME;
                        menuActive = false;
                        break;
                    default:
                        break;
                }
            }
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

std::string MenuBasic::ImgToString()
{
    std::string response = "";
    for(int y=0;y<longVertical;y++)
    {
        for(int x=0;x<longHorizontal;x++)
        {
            if((x==cursor_x0)&&(y==(cursor_y0+(cursor_jump*optionState)))){
                response=response+ MENU_CHARACTER_TO_SELECT; 
            }else{
                response=response+ img_ascii[y][x]; 
            }
	    }
        response=response+ "\n";
    }
    return response;
}

std::string MenuBasic::Draw()
{
    std::string response;
    if(img_ascii!=NULL){
        response=ImgToString();
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