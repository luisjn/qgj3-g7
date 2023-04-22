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
}

void Renderer::Clear()
{
    system("cls");
}

void Renderer::Render()
{
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
