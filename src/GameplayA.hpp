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
    void GameplayInitial();
    void GameplayOnPresentation();
    void GameplayOnMainMenu();
    void GameplayOnRun();
    void GameplayOnPause();
    void GameplayOnEnd();
public:
    void GetSoundEngine(Sound* SoundEngine); // SE: To get the Sound Engine pass by Game Engine
    void LoadLevel(int lID);
    void UnloadLevel();
    void Run();
    void InputMove(int side_ID);
    int GetImgLX();
    int GetImgLY();
    char** GetASCIIimg();
    GameplayA();
    ~GameplayA();
};