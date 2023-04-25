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

class Game
{
private:
    // Sound *msound_engine; // SE: In memory object to sound engine interact
    LevelFile *level;
    int actualLevel, imgLengX, imgLengY;
    char **imgASCII;
    Spaceship *mSpaceship;
    std::string mCurrentMap = "";

public:
    std::list<Projectile *> projectiles;
    std::list<Projectile *>::iterator itProjectiles;

    // void GetSoundEngine(Sound *SoundEngine); // SE: To get the Sound Engine pass by Game Engine
    void LoadLevel(int lID);
    void UnloadLevel();
    void Update();
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
