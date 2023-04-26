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
#include "Enemy.hpp"

class Game
{
private:
    // Sound *msound_engine; // SE: In memory object to sound engine interact
    LevelFile *level;
    int actualLevel, imgLengX, imgLengY;
    char **imgASCII;
    Spaceship *mSpaceship;
    std::string mCurrentMap = "";
    int mEnemies[5] = {132, 137, 139, 148, 129};

    // Game State
    int gameState;
    void GameplayInitial();
    void GameplayOnPresentation();
    void GameplayOnMainMenu();
    void GameplayOnRun();
    void GameplayOnPause();
    void GameplayOnEnd();
    void SetRenderAvailable();
    int RandomPosX();
    int RandomPosY();
    int RandomEnemy();
    int RandomNumEnemies();
    void SpawnEnemies();

public:
    std::list<Projectile *> projectiles;
    std::list<Projectile *>::iterator itProjectiles;

    std::list<MenuBasic *> menues;
    std::list<MenuBasic *>::iterator itMenues;

    std::list<Enemy *> enemies;
    std::list<Enemy *>::iterator itEnemies;

    // MenuBasic* mainMenu; // Main menu
    bool renderBkg;
    bool renderShip;
    bool renderEnemy;
    bool renderShoots;
    bool renderMenu;
    bool renderCinematic;
    int lbx = 20, ubx = 100;
    int lby = 10, uby = 20;
    int lbe = 1, ube = 5;
    int re = 6;

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
    int PlayerHP();
    void Start();
    Game();
    ~Game();
};
