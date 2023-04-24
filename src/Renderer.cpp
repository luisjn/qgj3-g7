#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <iterator>
// #include <string>

#pragma comment(lib, "User32.lib")

#include "Renderer.hpp"

Renderer::Renderer()
{
    //Initialize(); // Call on parallel
}

Renderer::~Renderer()
{
    Shutdown();
}

bool Renderer::Initialize(bool* mRunn)
{
    mRunning=mRunn;

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
    gameplay_tloz = new GameplayA(); // GP: Initiated gameplay
    gameplay_tloz->GetSoundEngine(sound_engine); // GP: Pass the sound engine direction
    //gameplay_tloz->LoadLevel(0); // GP: Initiated "Level_0.txt"

    return true;
}

void Renderer::Shutdown()
{
    delete sound_engine; // SE: Delete Sound Engine
    delete gameplay_tloz; // GP: Delete gameplay

    if (mWindow != nullptr)
    {
        mWindow = nullptr;
    }
    exit(0);
}

void Renderer::Update()
{
        ProcessInput();
        gameplay_tloz->Run();
        GetGameplayImage();
        Render();
}

void Renderer::GetGameplayImage()
{
    ASCII_img=gameplay_tloz->GetASCIIimg();
    imgLengX = gameplay_tloz->GetImgLX();
    imgLengY = gameplay_tloz->GetImgLY();
}

void Renderer::ProcessInput()
{
    // ARROWS:
    if (GetKeyState(VK_RIGHT) & 0x8000)
    {
        gameplay_tloz->InputMove(GAMEPLAY_MOVE_RIGHT);
    }
    if (GetKeyState(VK_LEFT) & 0x8000)
    {
        gameplay_tloz->InputMove(GAMEPLAY_MOVE_LEFT);
    }
    if (GetKeyState(VK_UP) & 0x8000)
    {
        gameplay_tloz->InputMove(GAMEPLAY_MOVE_UP);
    }
    if (GetKeyState(VK_DOWN) & 0x8000)
    {
        gameplay_tloz->InputMove(GAMEPLAY_MOVE_DOWN);
    }

    // WASD:
    if (GetKeyState('A') & 0x8000)
    {
        gameplay_tloz->InputMove(GAMEPLAY_MOVE_A);
    }
    if (GetKeyState('D') & 0x8000)
    {
        gameplay_tloz->InputMove(GAMEPLAY_MOVE_D);
    }
    if (GetKeyState('W') & 0x8000)
    {
        gameplay_tloz->InputMove(GAMEPLAY_MOVE_W);
    }
    if (GetKeyState('S') & 0x8000)
    {
        gameplay_tloz->InputMove(GAMEPLAY_MOVE_S);
    }

    // SPACE:
    if (GetKeyState(VK_SPACE) & 0x8000)
    {
        sound_engine->PlaySnd(0); // SE: Sound test: Shot!
    }

    // ESCAPE:
    if (GetKeyState(VK_ESCAPE) & 0x8000)
    {
        *mRunning = false; // Close the program (be carefull and change this behavior to adapt menues)
    }

    // Function Keys (F1 to F12):
    if (GetKeyState(VK_F1) & 0x8000)
    {
        sound_engine->SetActivatedSound(false); // SE: Sound activate sound engine
    }
    if (GetKeyState(VK_F2) & 0x8000)
    {
        sound_engine->SetActivatedSound(true); // SE: Sound deactivate sound engine
    }
    if (GetKeyState(VK_F3) & 0x8000)
    {
        sound_engine->ChangeActivatedSound(); // SE: Change avtivate sound state
    }
    if (GetKeyState(VK_F4) & 0x8000)
    {
        sound_engine->PlayMusic(0); // SE: Change avtivate sound state
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
        std::cout << consoleQtyCols << " x " << consoleQtyRows << "\n";
    }
    if (GetKeyState(VK_F10) & 0x8000)
    {
        gameplay_tloz->InputMove(50);
    }
    //if (GetKeyState(VK_F11) & 0x8000) // NOT to use F11 (full screen)!!!
    //{
    //}
    if (GetKeyState(VK_F12) & 0x8000)
    {
        gameplay_tloz->InputMove(51);
    }
    
}

void Renderer::GetConsoleMax() // To get console max text
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    consoleQtyCols = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    consoleQtyRows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
}

void Renderer::Clear()
{
    system("cls");
}

void Renderer::Render()
{
    Clear();
    GetConsoleMax(); // To get console max text

    std::string stringText = ""; 
	for (int x = 0; x < imgLengX; x++) { 
	    for (int y = 0; y < imgLengY; y++) { 
		    stringText = stringText + ASCII_img[x][y]; 
	    }
        stringText = stringText + "\n";
    }
    std::cout << stringText;

/*
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
*/
    //GoToXY(mSpaceship.Position.x, mSpaceship.Position.y);
    //std::cout << mSpaceship.Draw();
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
