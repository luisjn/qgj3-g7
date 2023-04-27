#include <cstdlib>
#include <time.h>
#include "Game.hpp"

Game::Game()
{
#ifdef DEBUG_MODE
    std::cout << "Gameplay Start...\n";
#endif
    gameState = GAMEPLAY_STATE_INTIAL;
    isRunning = true;
    srand(time(0));
    LoadLevel(0);
    mSpaceship = new Spaceship();
    SpawnEnemies();
}

Game::~Game()
{
#ifdef DEBUG_MODE
    std::cout << "Gameplay Finish!\n";
#endif
    delete level;
    delete mSpaceship;
    isRunning = false;
}

void Game::Restart()
{
    delete mSpaceship;
    enemies.clear();
    mSpaceship = new Spaceship();
    SpawnEnemies();
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
    switch (gameState)
    {
    case GAMEPLAY_STATE_INTIAL:
        renderBkg = false;
        renderShip = false;
        renderEnemy = false;
        renderShoots = false;
        renderMenu = false;
        renderCinematic = false;
        renderPlayerBar = false;
        break;
    case GAMEPLAY_STATE_PRESENTATION:
        renderBkg = false;
        renderShip = false;
        renderEnemy = false;
        renderShoots = false;
        renderMenu = false;
        renderCinematic = true;
        renderPlayerBar = false;
        break;
    case GAMEPLAY_STATE_MAIN_MENU:
        renderBkg = false;
        renderShip = false;
        renderEnemy = false;
        renderShoots = false;
        renderMenu = true;
        renderCinematic = false;
        renderPlayerBar = false;
        break;
    case GAMEPLAY_STATE_ON_GAME:
        renderBkg = true;
        renderShip = true;
        renderEnemy = true;
        renderShoots = true;
        renderMenu = false;
        renderCinematic = false;
        renderPlayerBar = true;
        break;
    case GAMEPLAY_STATE_PAUSE:
        renderBkg = true;
        renderShip = true;
        renderEnemy = true;
        renderShoots = true;
        renderMenu = true;
        renderCinematic = false;
        renderPlayerBar = false;
        break;
    case GAMEPLAY_STATE_END_GAME:
        renderBkg = false;
        renderShip = false;
        renderEnemy = false;
        renderShoots = false;
        renderMenu = false;
        renderCinematic = true;
        renderPlayerBar = false;
        break;
    }
}

void Game::Update()
{
    switch (gameState)
    {
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
    bool CN_NotExist = true;
    for (itCinematics = cinematics.begin(); itCinematics != cinematics.end(); itCinematics++)
    {
        if ((*itCinematics)->GetMenuID() == CINEMATIC_INITIAL)
        {
            CN_NotExist = false;
            int result = (*itCinematics)->Update();
            switch (result)
            {
            case MENU_ACTION_BACK_MAINMENU:
                gameState = GAMEPLAY_STATE_MAIN_MENU; // HARDCODE JUMP TO NEXT STATE...
                SetRenderAvailable();
                break;
            }
            if (!(*itCinematics)->GetMenuActive())
            {
                delete (*itCinematics);
                itCinematics = cinematics.erase(itCinematics);
            }
        }
    }
    if (CN_NotExist)
    {
        cinematics.push_back(new CinematicBasic(CINEMATIC_INITIAL, 0, 0, CINEMATIC_INITIAL_FILE));
    }
}

void Game::GameplayOnMainMenu()
{
    bool MM_NotExist = true;
    for (itMenues = menues.begin(); itMenues != menues.end(); itMenues++)
    {
        if ((*itMenues)->GetMenuID() == MENU_MAINMENU_CODE)
        {
            MM_NotExist = false;
            int result = (*itMenues)->Update();
            switch (result)
            {
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
                isRunning = false;
                break;
            case MENU_ACTION_GET_HELP:
                break;
            case MENU_ACTION_LOAD_SAVE:
                break;
            case MENU_ACTION_GO_PRESENTATION:
                gameState = GAMEPLAY_STATE_PRESENTATION;
                SetRenderAvailable();
                break;
            }
            if (!(*itMenues)->GetMenuActive())
            {
                delete (*itMenues);
                itMenues = menues.erase(itMenues);
            }
        }
    }
    if (MM_NotExist)
    {
        menues.push_back(new MenuBasic(MENU_MAINMENU_CODE, 0, 0, MENU_MAINMENU_FILE));
    }
}

void Game::GameplayOnPause()
{
    bool PM_NotExist = true;
    for (itMenues = menues.begin(); itMenues != menues.end(); itMenues++)
    {
        if ((*itMenues)->GetMenuID() == MENU_PAUSEMENU_CODE)
        {
            PM_NotExist = false;
            int result = (*itMenues)->Update();
            switch (result)
            {
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
                isRunning = false;
                break;
            case MENU_ACTION_BACK_MAINMENU:
                gameState = GAMEPLAY_STATE_MAIN_MENU; // HARDCODE JUMP TO NEXT STATE...
                SetRenderAvailable();
                break;
            }
            if (!(*itMenues)->GetMenuActive())
            {
                delete (*itMenues);
                itMenues = menues.erase(itMenues);
            }
        }
    }
    if (PM_NotExist)
    {
        menues.push_back(new MenuBasic(MENU_PAUSEMENU_CODE, 5, 5, MENU_PAUSEMENU_FILE));
    }
}

void Game::GameplayOnEnd()
{
    bool CN_NotExist = true;
    for (itCinematics = cinematics.begin(); itCinematics != cinematics.end(); itCinematics++)
    {
        if ((*itCinematics)->GetMenuID() == CINEMATIC_END)
        {
            CN_NotExist = false;
            int result = (*itCinematics)->Update();
            switch (result)
            {
            case MENU_ACTION_CONTINUE_GAME:
                gameState = GAMEPLAY_STATE_ON_GAME;
                SetRenderAvailable();
                break;
            }
            if (!(*itCinematics)->GetMenuActive())
            {
                delete (*itCinematics);
                itCinematics = cinematics.erase(itCinematics);
            }
        }
    }
    if (CN_NotExist)
    {
        std::string pathFile = CINEMATIC_END_FILE;
        // FAIL CONDITION:
        if (mSpaceship->mHp <= 0)
        {
            pathFile = CINEMATIC_ENDFAIL_FILE;
            Restart();
        }
        // VICTORY CONDITION:
        /*
        if (???????????)
        {
            pathFile=CINEMATIC_ENDGOOD_FILE;
            Restart();
        }
        */
        cinematics.push_back(new CinematicBasic(CINEMATIC_END, 0, 0, pathFile));
    }
}

void Game::GameplayOnRun()
{
    // FAIL CONDITION:
    if (mSpaceship->mHp <= 0)
    {
        gameState = GAMEPLAY_STATE_END_GAME;
        enemiesKilled = 0;
        SetRenderAvailable();
    }

    // VICTORY CONDITION:
    if ((level->GetActiveMapX() == 1 && level->GetActiveMapY() == 2) && enemies.empty())
    {
        gameState = GAMEPLAY_STATE_END_GAME;
        SetRenderAvailable();
    }

    if (mSpaceship->Position.x > Width - Limit)
    {
        enemies.clear();
        level->MoveMapRight();
        mSpaceship->Position.x = Limit;
        SpawnEnemies();
    }
    else if (mSpaceship->Position.x < Limit)
    {
        enemies.clear();
        level->MoveMapLeft();
        mSpaceship->Position.x = Width - Limit;
        SpawnEnemies();
    }
    else if (mSpaceship->Position.y > Height - Limit)
    {
        enemies.clear();
        level->MoveMapDown();
        mSpaceship->Position.y = Limit;
        SpawnEnemies();
    }
    else if (mSpaceship->Position.y < Limit)
    {
        enemies.clear();
        level->MoveMapUp();
        mSpaceship->Position.y = Height - Limit;
        SpawnEnemies();
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

    for (itEnemies = enemies.begin(); itEnemies != enemies.end(); itEnemies++)
    {
        (*itEnemies)->FollowPlayer(mSpaceship->Position);

        if ((*itEnemies)->IsColliding(mSpaceship->Position))
        {
            mSpaceship->mHp -= 5;
        }

        for (itProjectiles = projectiles.begin(); itProjectiles != projectiles.end(); itProjectiles++)
        {
            if ((*itEnemies)->IsColliding((*itProjectiles)->Position(), (*itProjectiles)->GetDirection(), (*itProjectiles)->GetSpeedX(), (*itProjectiles)->GetSpeedY()))
            {
                delete (*itProjectiles);
                itProjectiles = projectiles.erase(itProjectiles);
                delete (*itEnemies);
                itEnemies = enemies.erase(itEnemies);
                enemiesKilled++;
            }
        }
    }
}

void Game::LoadLevel(int lID)
{
    level = new LevelFile(lID);
    actualLevel = lID;
}

void Game::UnloadLevel()
{
    delete level;
}

void Game::Input(int side_ID)
{
    switch (gameState)
    {
    case GAMEPLAY_STATE_INTIAL:
        break;
    case GAMEPLAY_STATE_PRESENTATION:
        for (itCinematics = cinematics.begin(); itCinematics != cinematics.end(); itCinematics++)
        {
            (*itCinematics)->Input(side_ID);
        }
        break;
    case GAMEPLAY_STATE_MAIN_MENU:
        for (itMenues = menues.begin(); itMenues != menues.end(); itMenues++)
        {
            if ((*itMenues)->GetMenuID() == MENU_MAINMENU_CODE)
            {
                (*itMenues)->Input(side_ID);
            }
        }
        break;
    case GAMEPLAY_STATE_PAUSE:
        for (itMenues = menues.begin(); itMenues != menues.end(); itMenues++)
        {
            if ((*itMenues)->GetMenuID() == MENU_PAUSEMENU_CODE)
            {
                (*itMenues)->Input(side_ID);
            }
        }
        break;
    case GAMEPLAY_STATE_END_GAME:
        for (itCinematics = cinematics.begin(); itCinematics != cinematics.end(); itCinematics++)
        {
            (*itCinematics)->Input(side_ID);
        }
        break;
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

int Game::PlayerHP()
{
    return mSpaceship->mHp;
}

int Game::RandomPosX()
{
    return (rand() % (ubx - lbx + 1)) + lbx;
}

int Game::RandomPosY()
{
    return (rand() % (uby - lby + 1)) + lby;
}

int Game::RandomEnemy()
{
    return rand() % re;
}

int Game::RandomNumEnemies()
{
    return (rand() % (ube - lbe + 1)) + lbe;
}

void Game::SpawnEnemies()
{
    int rne = RandomNumEnemies();
    for (int i = 0; i < rne; i++)
    {
        char e = mEnemies[RandomEnemy()];
        enemies.push_back(new Enemy(RandomPosX(), RandomPosY(), e));
    }
}
