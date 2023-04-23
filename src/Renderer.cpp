#include <iostream>
#include <stdlib.h>
#include <fstream>
// #include <string>

#pragma comment(lib, "User32.lib")

#include "Renderer.hpp"

bool Renderer::Initialize()
{
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

    return true;
}

void Renderer::Shutdown()
{
    if (mWindow != nullptr)
    {
        mWindow = nullptr;
    }
    exit(0);
}

void Renderer::GetSoundEngine(Sound* SoundEngine)
{
    msound_engine = SoundEngine;
}

void Renderer::GetConsoleMax() // To get console max text
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    consoleQtyCols = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    consoleQtyRows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
}

void Renderer::Input()
{
    if (GetKeyState(VK_RIGHT) & 0x8000)
    {
        mSpaceship.Right();
    }
    if (GetKeyState(VK_LEFT) & 0x8000)
    {
        mSpaceship.Left();
    }
    if (GetKeyState(VK_UP) & 0x8000)
    {
        mSpaceship.Up();
    }
    if (GetKeyState(VK_DOWN) & 0x8000)
    {
        mSpaceship.Down();
    }

    // SE: Sound test keys:
    if (GetKeyState(VK_SPACE) & 0x8000)
    {
        msound_engine->PlaySnd(0); // SE: Sound test: Shot!
    }
    if (GetKeyState(VK_F1) & 0x8000)
    {
        msound_engine->SetActivatedSound(false); // SE: Sound activate sound engine
    }
    if (GetKeyState(VK_F2) & 0x8000)
    {
        msound_engine->SetActivatedSound(true); // SE: Sound deactivate sound engine
    }
    if (GetKeyState(VK_F3) & 0x8000)
    {
        msound_engine->ChangeActivatedSound(); // SE: Change avtivate sound state
    }
    if (GetKeyState(VK_F4) & 0x8000)
    {
        msound_engine->PlayMusic(0); // SE: Change avtivate sound state
    }
    // SE: End sound test keys.
}

void Renderer::Clear()
{
    system("cls");
}

void Renderer::Render()
{
    GetConsoleMax(); // To get console max text
    char space[] = R"(.         _  .          .          .    +     .          .          .      .
        .(_)          .            .            .            .       :
        .   .      .    .     .     .    .      .   .      . .  .  -+-        .
          .           .   .        .           .          /         :  .
    . .        .  .      /.   .      .    .     .     .  / .      . ' .
        .  +       .    /     .          .          .   /      .
       .            .  /         .            .        *   .         .     .
      .   .      .    *     .     .    .      .   .       .  .
          .           .           .           .           .         +  .
  . .        .  .       .   .      .    .     .     .    .      .   .
      .   .      .    *     .     .    .      .   .       .  .
          .           .           .           .           .         +  .
  . .        .  .       .   .      .    .     .     .    .      .   .)";
    std::cout << space;
    GoToXY(mSpaceship.Position.x, mSpaceship.Position.y);
    std::cout << mSpaceship.Draw();
}

void Renderer::GoToXY(int x, int y)
{
    mCursorPosition.X = x;
    mCursorPosition.Y = y;
    SetConsoleCursorPosition(mWindow, mCursorPosition);
}

// void Renderer::PrintASCII()
// {
//     string line = "";
//     ifstream inFile;
//     inFile.open("bomb_art. txt");
//     if (inFile.is_open())
//     {
//         while (getline(inFile, line))
//         {
//             cout <‹ line <‹ end;
//         }
//     }
//     else
//     {
//         cout <‹ "File failed to load. " <‹ end1;
//         cout <‹ "No nuke displayed." < endl;
//     }
//     infile.close();
// }
