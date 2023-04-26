#pragma once

#include <iostream>
#include <fstream>
#include <sstream> // LF: Manage string names for maps to include
#include <list>

#include "Settings.h"    // General Game DEFINEs
#include "LevelFile.hpp" // LF: Add file loadding library
#include "Sound.hpp"     // SE: Add sound engine library
#include "Spaceship.hpp" // Add player charactable to Gameplay
#include "Vector2.hpp"
#include "Projectile.hpp"
#include "MenuBasic.hpp" // Add Menu

class Game
{
private:
    // Sound *msound_engine; // SE: In memory object to sound engine interact
    LevelFile *level;
    int actualLevel, imgLengX, imgLengY;
    char **imgASCII;
    Spaceship *mSpaceship;
    std::string mCurrentMap = "";

    // Game State
    int gameState;
    void GameplayInitial();
    void GameplayOnPresentation();
    void GameplayOnMainMenu();
    void GameplayOnRun();
    void GameplayOnPause();
    void GameplayOnEnd();
    void SetRenderAvailable();

public:
    std::list<Projectile *> projectiles;
    std::list<Projectile *>::iterator itProjectiles;

    std::list<MenuBasic *> menues;
    std::list<MenuBasic *>::iterator itMenues;

    //MenuBasic* mainMenu; // Main menu
    bool renderBkg;
    bool renderShip;
    bool renderEnemy;
    bool renderShoots;
    bool renderMenu;
    bool renderCinematic;

    // void GetSoundEngine(Sound *SoundEngine); // SE: To get the Sound Engine pass by Game Engine
    void LoadLevel(int lID);
    void UnloadLevel();
    void Update();
    void Input(int side_ID);
    void InputMove(int side_ID);
    int GetImgLX();
    int GetImgLY();
    char **GetASCIIimg();
    std::string CurrentMap();
    float PlayerPositionX();
    float PlayerPositionY();
    char Player();
    Game();
    ~Game();
};
