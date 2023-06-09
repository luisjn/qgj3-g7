#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <iterator>
// #include <string>

#pragma comment(lib, "User32.lib")

#include "Renderer.hpp"

Renderer::Renderer()
{
    // Initialize(); // Call on parallel
}

Renderer::~Renderer()
{
    Shutdown();
}

bool Renderer::Initialize(bool *mRunn)
{
    mRunning = mRunn;

    mWindow = GetStdHandle(STD_OUTPUT_HANDLE);
    if (mWindow == nullptr)
    {
        return false;
    }

    CONSOLE_CURSOR_INFO cursorInfo;

    GetConsoleCursorInfo(mWindow, &cursorInfo);
    cursorInfo.bVisible = false; // set the cursor visibility
    SetConsoleCursorInfo(mWindow, &cursorInfo);

    SetConsoleTitleW(L"Game");

    // Initiate random character generator (for test propourse):
    srand(time(0));
#ifdef SOUND_ENGINE_AUTOSTART
    sound_engine = new Sound(true); // SE: Initied Sound Engine (default: TRUE)
#endif
#ifndef SOUND_ENGINE_AUTOSTART
    sound_engine = new Sound(false); // SE: Initied Sound Engine (default: FALSE)
#endif
    game = new Game(); // GP: Initiated gameplay
    // game->GetSoundEngine(sound_engine); // GP: Pass the sound engine direction
    // game->LoadLevel(0); // GP: Initiated "Level_0.txt"

    return true;
}

void Renderer::Shutdown()
{
    delete sound_engine; // SE: Delete Sound Engine
    delete game;         // GP: Delete gameplay

    if (mWindow != nullptr)
    {
        mWindow = nullptr;
    }
    // exit(0);
}

void Renderer::Update()
{
    ProcessInput();
    game->Update();
    Render();
    sound_engine->PlaySnd(game->GetSountToActive());
    *mRunning = game->IsRunning();
}

void Renderer::ProcessInput()
{
    // ARROWS:
    if (GetKeyState(VK_RIGHT) & 0x8000)
    {
        game->Input(GAMEPLAY_MOVE_RIGHT);
        // sound_engine->PlaySnd(3);
    }
    if (GetKeyState(VK_LEFT) & 0x8000)
    {
        game->Input(GAMEPLAY_MOVE_LEFT);
        // sound_engine->PlaySnd(3);
    }
    if (GetKeyState(VK_UP) & 0x8000)
    {
        game->Input(GAMEPLAY_MOVE_UP);
        // sound_engine->PlaySnd(3);
    }
    if (GetKeyState(VK_DOWN) & 0x8000)
    {
        game->Input(GAMEPLAY_MOVE_DOWN);
        // sound_engine->PlaySnd(3);
    }

    // SPACE:
    if (GetKeyState(VK_SPACE) & 0x8000)
    {
        //sound_engine->PlaySnd(1); // SE: Sound test: Shot!
        game->Input(GAMEPLAY_SHOOT);
    }

    // WASD:
    if (GetKeyState('A') & 0x8000)
    {
        game->Input(GAMEPLAY_MOVE_A);
        //sound_engine->PlaySnd(3);
    }
    if (GetKeyState('D') & 0x8000)
    {
        game->Input(GAMEPLAY_MOVE_D);
        //sound_engine->PlaySnd(3);
    }
    if (GetKeyState('W') & 0x8000)
    {
        game->Input(GAMEPLAY_MOVE_W);
        //sound_engine->PlaySnd(3);
    }
    if (GetKeyState('S') & 0x8000)
    {
        game->Input(GAMEPLAY_MOVE_S);
        //sound_engine->PlaySnd(3);
    }

    // ENTER;
    if (GetKeyState(VK_RETURN) & 0x8000)
    {
        game->Input(GAMEPLAY_INTRO);
    }

    // ESCAPE:
    if (GetKeyState(VK_ESCAPE) & 0x8000)
    {
        game->Input(GAMEPLAY_EXIT);
        //*mRunning = false; // Close the program (be carefull and change this behavior to adapt menues)
    }

    // Function Keys (F1 to F12):
    if (GetKeyState(VK_F1) & 0x8000)
    {
        //sound_engine->SetActivatedSound(false); // SE: Sound activate sound engine
    }
    if (GetKeyState(VK_F2) & 0x8000)
    {
        //sound_engine->SetActivatedSound(true); // SE: Sound deactivate sound engine
    }
    if (GetKeyState(VK_F3) & 0x8000)
    {
        //sound_engine->ChangeActivatedSound(); // SE: Change avtivate sound state
    }
    if (GetKeyState(VK_F4) & 0x8000)
    {
        //sound_engine->PlayMusic(0); // SE: Change avtivate sound state
    }
    if (GetKeyState(VK_F5) & 0x8000)
    {
    }
    if (GetKeyState(VK_F6) & 0x8000)
    {
    }
    if (GetKeyState(VK_F7) & 0x8000)
    {
    }
    if (GetKeyState(VK_F8) & 0x8000)
    {
    }
    if (GetKeyState(VK_F9) & 0x8000)
    {
        game->Input(GAMEPLAY_JUMPMAINMENU);
    }
    if (GetKeyState(VK_F10) & 0x8000)
    {
        game->Input(GAMEPLAY_JUMPLEVEL_00);
    }
    // if (GetKeyState(VK_F11) & 0x8000) // NOT to use F11 (full screen)!!!
    //{
    // }
    if (GetKeyState(VK_F12) & 0x8000)
    {
        game->Input(GAMEPLAY_JUMPLEVEL_01);
    }
}

void Renderer::GetConsoleMax() // To get console max text
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(mWindow, &csbi);
    consoleQtyCols = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    consoleQtyRows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
}

void Renderer::Clear()
{
    system("cls");
}

void Renderer::GetBackgroundImage()
{
    ASCII_img = game->GetASCIIimg();
    imgLengX = game->GetImgLX();
    imgLengY = game->GetImgLY();
}

void Renderer::RenderBackground()
{
    std::string stringText = "";
    for (int x = 0; x < imgLengX; x++)
    {
        for (int y = 0; y < imgLengY; y++)
        {
            stringText = stringText + ASCII_img[x][y];
        }
        stringText = stringText + "\n";
    }
    std::cout << stringText;
}

void Renderer::Render()
{
    /*
     * CLEAR
     */
    Clear();

    if (game->renderBkg)
    {
        /*
         * MAP / BACKGROUND
         */
        GetBackgroundImage();
        RenderBackground();
    }
    if (game->renderShip)
    {
        /*
         * PLAYER
         */
        GoToXY(game->PlayerPositionX(), game->PlayerPositionY());
        std::cout << game->Player();
    }
    if (game->renderEnemy)
    {
        /*
         * Enemies
         */
        for (game->itEnemies = game->enemies.begin(); game->itEnemies != game->enemies.end(); game->itEnemies++)
        {
            GoToXY((*game->itEnemies)->PositionX(), (*game->itEnemies)->PositionY());
            std::cout << (*game->itEnemies)->Draw();
        }
    }
    if (game->renderShoots)
    {
        /*
         * PROYECTILES
         */
        for (game->itProjectiles = game->projectiles.begin(); game->itProjectiles != game->projectiles.end(); game->itProjectiles++)
        {
            GoToXY((*game->itProjectiles)->PositionX(), (*game->itProjectiles)->PositionY());
            std::cout << (*game->itProjectiles)->Draw();
        }
    }
    if (game->renderMenu)
    {
        /*
         * MENU
         */
        for (game->itMenues = game->menues.begin(); game->itMenues != game->menues.end(); game->itMenues++)
        {
            if (((*game->itMenues)->GetDX() < Width) && ((*game->itMenues)->GetDY() < (Height)))
            {
                MergeImageASCII((*game->itMenues)->Draw(), (*game->itMenues)->GetX0(), (*game->itMenues)->GetY0(), (*game->itMenues)->GetDX(), (*game->itMenues)->GetDY());
            }
            else
            {
                GoToXY((*game->itMenues)->GetX0(), (*game->itMenues)->GetY0());
                std::cout << (*game->itMenues)->Draw();
            }
        }
    }
    if (game->renderCinematic)
    {
        for (game->itCinematics = game->cinematics.begin(); game->itCinematics != game->cinematics.end(); game->itCinematics++)
        {
            if (((*game->itCinematics)->GetDX() < Width) && ((*game->itCinematics)->GetDY() < (Height)))
            {
                MergeImageASCII((*game->itCinematics)->Draw(), (*game->itCinematics)->GetX0(), (*game->itCinematics)->GetY0(), (*game->itCinematics)->GetDX(), (*game->itCinematics)->GetDY());
            }
            else
            {
                GoToXY((*game->itCinematics)->GetX0(), (*game->itCinematics)->GetY0());
                std::cout << (*game->itCinematics)->Draw();
            }
        }
    }
    if (game->renderPlayerBar)
    {
        GoToXY(49, 29);
        std::cout << "HP: " << game->PlayerHP();
        GoToXY(58, 29);
        std::cout << "Enemies Killed: " << game->enemiesKilled;
    }
    if (game->renderHistory)
    {
        int txtDx = game->GetHistoryTextX();
        int txtDy = game->GetHistoryTextY();
        MergeImageASCII(game->GetHistoryText(),(Width-txtDx)/2,(Height-txtDy)/2,txtDx,txtDy);
    }
}

void Renderer::GoToXY(int x, int y)
{
    mCursorPosition.X = x;
    mCursorPosition.Y = y;
    SetConsoleCursorPosition(mWindow, mCursorPosition);
}

void Renderer::MergeImageASCII(std::string imgASCIItoMerge, int x0, int y0, int dx, int dy)
{
    int calc;
    for (int y = 0; y < dy; y++)
    {
        for (int x = 0; x < dx; x++)
        {
            calc = (y * dx) + y + x;
            GoToXY(x + x0, y + y0);
            std::cout << imgASCIItoMerge[calc];
        }
    }
}

/*
void GameplayA::MergeImageASCII(std::string imgASCIItoMerge, int x0, int y0, int dx, int dy)
{
    int calc;
    for(int y=0;y<dy;y++){
        for(int x=0;x<dx;x++){
            calc=(y*dx)+y+x;
            imgASCII[y+y0][x+x0]=(char)imgASCIItoMerge[calc];
        }
    }
}
*/
