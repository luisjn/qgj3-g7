#include "Game.hpp"

Game::Game()
{
#ifdef DEBUG_MODE
    std::cout << "Gameplay Start...\n";
#endif
    LoadLevel(0);
    mSpaceship = new Spaceship();
}

Game::~Game()
{
#ifdef DEBUG_MODE
    std::cout << "Gameplay Finish!\n";
#endif
    delete level;
    delete mSpaceship;
    // delete msound_engine;
}

// void Game::GetSoundEngine(Sound *SoundEngine)
// {
//     msound_engine = SoundEngine;
// }

void Game::Update()
{
    if (mSpaceship->Position.x > Width - Limit)
    {
        mSpaceship->Position.x = Limit;
    }
    else if (mSpaceship->Position.x < Limit)
    {
        mSpaceship->Position.x = Width - Limit;
    }
    else if (mSpaceship->Position.y > Height - Limit)
    {
        mSpaceship->Position.y = Limit;
    }
    else if (mSpaceship->Position.y < Limit)
    {
        mSpaceship->Position.y = Height - Limit;
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
}

void Game::LoadLevel(int lID)
{
    level = new LevelFile(lID);
    actualLevel = lID;

    // for (int x = 0; x < imgLengX; x++)
    // {
    //     for (int y = 0; y < imgLengY; y++)
    //     {
    //         mCurrentMap = mCurrentMap + imgASCII[x][y];
    //     }
    //     mCurrentMap = mCurrentMap + "\n";
    // }
}

void Game::UnloadLevel()
{
    delete level;
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
    // Move maps on level:
    case GAMEPLAY_MOVE_A:
        level->MoveMapLeft();
        break;
    case GAMEPLAY_MOVE_D:
        level->MoveMapRight();
        break;
    case GAMEPLAY_MOVE_W:
        level->MoveMapUp();
        break;
    case GAMEPLAY_MOVE_S:
        level->MoveMapDown();
        break;
    case 50:
        LoadLevel(0); // GP: Initiated "Level_0.txt"
        break;
    case 51:
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
