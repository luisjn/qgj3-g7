#include "Game.hpp"

Game::Game()
{
#ifdef DEBUG_MODE
    std::cout << "Gameplay Start...\n";
#endif
    gameState = GAMEPLAY_STATE_INTIAL;
    isRunning=true;

    

    LoadLevel(0);
    mSpaceship = new Spaceship();
}

Game::~Game()
{
#ifdef DEBUG_MODE
    std::cout << "Gameplay Finish!\n";
#endif
    delete level;
    delete mSpaceship;
    isRunning=false;
    // delete msound_engine;
}

// void Game::GetSoundEngine(Sound *SoundEngine)
// {
//     msound_engine = SoundEngine;
// }

bool Game::IsRunning()
{
    return isRunning;
}

void Game::SetRenderAvailable()
{
    switch(gameState){
        case GAMEPLAY_STATE_INTIAL:
            renderBkg = false;
            renderShip = false;
            renderEnemy = false;
            renderShoots = false;
            renderMenu = false;
            renderCinematic = false;
            break;
        case GAMEPLAY_STATE_PRESENTATION:
            renderBkg = false;
            renderShip = false;
            renderEnemy = false;
            renderShoots = false;
            renderMenu = false;
            renderCinematic = true;
            break;
        case GAMEPLAY_STATE_MAIN_MENU:
            renderBkg = false;
            renderShip = false;
            renderEnemy = false;
            renderShoots = false;
            renderMenu = true;
            renderCinematic = false;
            break;
        case GAMEPLAY_STATE_ON_GAME:
            renderBkg = true;
            renderShip = true;
            renderEnemy = true;
            renderShoots = true;
            renderMenu = false;
            renderCinematic = false;
            break;
        case GAMEPLAY_STATE_PAUSE:
            renderBkg = true;
            renderShip = true;
            renderEnemy = true;
            renderShoots = true;
            renderMenu = true;
            renderCinematic = false;
            break;
        case GAMEPLAY_STATE_END_GAME:
            renderBkg = true;
            renderShip = false;
            renderEnemy = false;
            renderShoots = false;
            renderMenu = true;
            renderCinematic = true;
            break;
        }
}

void Game::Update()
{
    switch(gameState){
        case GAMEPLAY_STATE_INTIAL:
            GameplayInitial();
            break;
        case GAMEPLAY_STATE_PRESENTATION:
            GameplayOnPresentation();
            break;
        case GAMEPLAY_STATE_MAIN_MENU:
            GameplayOnMainMenu();
            break;
        case GAMEPLAY_STATE_ON_GAME:
            GameplayOnRun();
            break;
        case GAMEPLAY_STATE_PAUSE:
            GameplayOnPause();
            break;
        case GAMEPLAY_STATE_END_GAME:
            GameplayOnEnd();
            break;
        }
}


void Game::GameplayInitial()
{
//    std::cout << "gameState: "<< gameState << "\n";
    gameState = GAMEPLAY_STATE_PRESENTATION; // HARDCODE JUMP TO NEXT STATE...
    SetRenderAvailable();
}


void Game::GameplayOnPresentation()
{
    //std::cout << "gameState: "<< gameState << "\n";
    gameState = GAMEPLAY_STATE_MAIN_MENU; // HARDCODE JUMP TO NEXT STATE...
    SetRenderAvailable();
}

void Game::GameplayOnMainMenu()
{
    bool MM_NotExist=true;
    for (itMenues = menues.begin(); itMenues != menues.end(); itMenues++)
    {
        if((*itMenues)->GetMenuID()==MENU_MAINMENU_CODE){
            MM_NotExist=false;
            int result = (*itMenues)->Update();
            switch(result){
                case MENU_ACTION_NULL:
                    break;
                case MENU_ACTION_CONTINUE_GAME:
                    gameState = GAMEPLAY_STATE_ON_GAME;
                    SetRenderAvailable();
                    break;
                case MENU_ACTION_SWITCH_SOUND:
                    // change sound mode...
                    break;
                case MENU_ACTION_EXIT_GAME:
                    isRunning=false;
                    break;
                case MENU_ACTION_GET_HELP:
                    break;
                case MENU_ACTION_LOAD_SAVE:
                    break;
                case MENU_ACTION_GO_PRESENTATION:
                    break;
            }
            if(!(*itMenues)->GetMenuActive()){
                delete (*itMenues);
                itMenues = menues.erase(itMenues);
            }
        }
    }
    if(MM_NotExist){
        menues.push_back(new MenuBasic(MENU_MAINMENU_CODE,0,0,MENU_MAINMENU_FILE));
    }
}

void Game::GameplayOnPause()
{
    bool PM_NotExist=true;
    for (itMenues = menues.begin(); itMenues != menues.end(); itMenues++)
    {
        if((*itMenues)->GetMenuID()==MENU_PAUSEMENU_CODE){
            PM_NotExist=false;
            int result = (*itMenues)->Update();
            switch(result){
                case MENU_ACTION_NULL:
                    break;
                case MENU_ACTION_CONTINUE_GAME:
                    gameState = GAMEPLAY_STATE_ON_GAME;
                    SetRenderAvailable();
                    break;
                case MENU_ACTION_SWITCH_SOUND:
                    // change sound mode...
                    break;
                case MENU_ACTION_EXIT_GAME:
                    isRunning=false;
                    break;
                case MENU_ACTION_BACK_MAINMENU:
                    gameState = GAMEPLAY_STATE_MAIN_MENU; // HARDCODE JUMP TO NEXT STATE...
                    SetRenderAvailable();
                    break;
            }
            if(!(*itMenues)->GetMenuActive()){
                delete (*itMenues);
                itMenues = menues.erase(itMenues);
            }
        }
    }
    if(PM_NotExist){
        menues.push_back(new MenuBasic(MENU_PAUSEMENU_CODE,5,5,MENU_PAUSEMENU_FILE));
    }
}

void Game::GameplayOnEnd()
{
//    std::cout << "gameState: "<< gameState << "\n";
    gameState = GAMEPLAY_STATE_ON_GAME; // HARDCODE JUMP BACK TO GAME...
    SetRenderAvailable();
}

void Game::GameplayOnRun()
{
    if (mSpaceship->Position.x > Width - Limit)
    {
        mSpaceship->Position.x = Limit;
    }
    else if (mSpaceship->Position.x < Limit)
    {
        mSpaceship->Position.x = Width - Limit;
    }
    else if (mSpaceship->Position.y > Height - Limit)
    {
        mSpaceship->Position.y = Limit;
    }
    else if (mSpaceship->Position.y < Limit)
    {
        mSpaceship->Position.y = Height - Limit;
    }
    for (itProjectiles = projectiles.begin(); itProjectiles != projectiles.end(); itProjectiles++)
    {
        (*itProjectiles)->Update();
        if ((*itProjectiles)->IsOut())
        {
            delete (*itProjectiles);
            itProjectiles = projectiles.erase(itProjectiles);
        }
    }
}

void Game::LoadLevel(int lID)
{
    level = new LevelFile(lID);
    actualLevel = lID;

    // for (int x = 0; x < imgLengX; x++)
    // {
    //     for (int y = 0; y < imgLengY; y++)
    //     {
    //         mCurrentMap = mCurrentMap + imgASCII[x][y];
    //     }
    //     mCurrentMap = mCurrentMap + "\n";
    // }
}

void Game::UnloadLevel()
{
    delete level;
}

void Game::Input(int side_ID)
{
    switch(gameState){
        case GAMEPLAY_STATE_INTIAL:
            break;
        case GAMEPLAY_STATE_PRESENTATION:
            break;
        case GAMEPLAY_STATE_MAIN_MENU:
            for (itMenues = menues.begin(); itMenues != menues.end(); itMenues++)
            {
                if((*itMenues)->GetMenuID()==MENU_MAINMENU_CODE){
                    (*itMenues)->Input(side_ID);
                }
            }
            break;
        case GAMEPLAY_STATE_PAUSE:
            for (itMenues = menues.begin(); itMenues != menues.end(); itMenues++)
            {
                if((*itMenues)->GetMenuID()==MENU_PAUSEMENU_CODE){
                    (*itMenues)->Input(side_ID);
                }
            }
            break;
        case GAMEPLAY_STATE_END_GAME:
            break;
        case GAMEPLAY_STATE_ON_GAME:
            InputMove(side_ID);
            break;
        }
}

void Game::InputMove(int side_ID)
{
    switch (side_ID)
    {
    // Move spacecraft:
    case GAMEPLAY_MOVE_RIGHT:
        mSpaceship->Right();
        break;
    case GAMEPLAY_MOVE_LEFT:
        mSpaceship->Left();
        break;
    case GAMEPLAY_MOVE_UP:
        mSpaceship->Up();
        break;
    case GAMEPLAY_MOVE_DOWN:
        mSpaceship->Down();
        break;
    case GAMEPLAY_SHOOT:
        projectiles.push_back(new Projectile(mSpaceship->Position.x, mSpaceship->Position.y, mSpaceship->Direction()));
        break;
    // Move maps on level:
    case GAMEPLAY_MOVE_A:
        level->MoveMapLeft();
        break;
    case GAMEPLAY_MOVE_D:
        level->MoveMapRight();
        break;
    case GAMEPLAY_MOVE_W:
        level->MoveMapUp();
        break;
    case GAMEPLAY_MOVE_S:
        level->MoveMapDown();
        break;
    case GAMEPLAY_EXIT:
        gameState = GAMEPLAY_STATE_PAUSE;
        SetRenderAvailable();
        break;
    case GAMEPLAY_JUMPMAINMENU:
        gameState = GAMEPLAY_STATE_MAIN_MENU;
        SetRenderAvailable();
        break;
    case GAMEPLAY_JUMPLEVEL_00:
        LoadLevel(0); // GP: Initiated "Level_0.txt"
        break;
    case GAMEPLAY_JUMPLEVEL_01:
        LoadLevel(1); // GP: Initiated "Level_0.txt"
        break;
    }
}

char **Game::GetASCIIimg()
{
    imgASCII = level->GetMapASCII();
    return imgASCII;
}

int Game::GetImgLX()
{
    imgLengX = level->GetMapSizeX();
    return imgLengX;
}

int Game::GetImgLY()
{
    imgLengY = level->GetMapSizeY();
    return imgLengY;
}

std::string Game::CurrentMap()
{
    for (int x = 0; x < imgLengX; x++)
    {
        for (int y = 0; y < imgLengY; y++)
        {
            mCurrentMap = mCurrentMap + imgASCII[x][y];
        }
        mCurrentMap = mCurrentMap + "\n";
    }
    return mCurrentMap;
}

float Game::PlayerPositionX()
{
    return mSpaceship->Position.x;
}

float Game::PlayerPositionY()
{
    return mSpaceship->Position.y;
}

char Game::Player()
{
    return mSpaceship->Draw();
}
