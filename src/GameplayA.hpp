#pragma once
// External libs required: -------------------------------------------------------------------------------------------

#include <iostream>
#include <fstream>
#include <sstream> // LF: Manage string names for maps to include
#include "Settings.h" // General Game DEFINEs
#include "LevelFile.hpp" // LF: Add file loadding library
#include "Sound.hpp" // SE: Add sound engine library
#include "Spaceship.hpp" // Add player charactable to Gameplay
#include "Menu.hpp" // Add menues to Gameplay
#include "ImageASCII.hpp" // New mod for char array use

// Class declare: ----------------------------------------------------------------------------------------------------

class GameplayA
{
private:
    Sound* msound_engine; // SE: In memory object to sound engine interact
    LevelFile* level;
    Spaceship* mSpaceship;
    MenuBasic* mainMenu; // Main menu
    char** imgASCII;
    int actualLevel, imgLengX, imgLengY;
    int gameState; // State for game

    //ImageASCII* image;

    void GameplayInitial();
    void GameplayOnPresentation();
    void GameplayOnMainMenu();
    void GameplayOnRun();
    void GameplayOnPause();
    void GameplayOnEnd();
    void MergeImageASCII(std::string imgASCIItoMerge, int x0, int y0, int dx, int dy);
public:
    void GetSoundEngine(Sound* SoundEngine); // SE: To get the Sound Engine pass by Game Engine
    void LoadLevel(int lID);
    void UnloadLevel();
    void Run();
    void Input(int side_ID);
    int GetImgLX();
    int GetImgLY();
    char** GetASCIIimg();
    GameplayA();
    ~GameplayA();
};