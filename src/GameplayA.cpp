// -------------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------------

// Class declare and external libs required: -------------------------------------------------------------------------

#include "GameplayA.hpp"

// Constructor and destructor: ---------------------------------------------------------------------------------------

GameplayA::GameplayA()
{
#ifdef DEBUG_MODE
    std::cout << "Gameplay Start...\n";
#endif
}

GameplayA::~GameplayA()
{
#ifdef DEBUG_MODE
    std::cout << "Gameplay Finish!\n";
#endif
    //delete level;
    //delete msound_engine;
}

// Voids: ------------------------------------------------------------------------------------------------------------

void GameplayA::GetSoundEngine(Sound* SoundEngine)
{
    msound_engine = SoundEngine;
}

void GameplayA::Run()
{
    int S_x = mSpaceship->Position.x;
    int S_y = mSpaceship->Position.y;

    std::cout << "S_x: " << S_x << "\n";
    std::cout << "S_y: " << S_y << "\n";
    
    if((S_x>=0)||(S_x<=imgLengX)){
        if((S_y>=0)||(S_y<=imgLengY)){
            std::cout << "OkToPrint: "<< mSpaceship->Draw() <<"\n";
            //str::strcpy(&imgASCII[S_x][S_y],&mSpaceship->Draw(),1);
        }
    }
    
}

void GameplayA::LoadLevel(int lID)
{
    level = new LevelFile(lID);
    mSpaceship = new Spaceship();
    actualLevel=lID;
    imgLengX=level->GetMapSizeX();
    imgLengY=level->GetMapSizeY();
    imgASCII=level->GetMapASCII();
}

void GameplayA::UnloadLevel()
{
    delete level;
    delete mSpaceship;
}

void GameplayA::InputMove(int side_ID){
    switch(side_ID){
        case GAMEPLAY_MOVE_RIGHT:
            mSpaceship->Right();
            msound_engine->PlaySnd(3);
            break;
        case GAMEPLAY_MOVE_LEFT:
            mSpaceship->Left();
            msound_engine->PlaySnd(3);
            break;
        case GAMEPLAY_MOVE_UP:
            mSpaceship->Up();
            msound_engine->PlaySnd(3);
            break;
        case GAMEPLAY_MOVE_DOWN:
            mSpaceship->Down();
            msound_engine->PlaySnd(3);
            break;
    }
}

char** GameplayA::GetASCIIimg()
{
    return imgASCII;
}

int GameplayA::GetImgLX()
{
    return imgLengX;
}

int GameplayA::GetImgLY()
{
    return imgLengY;
}

// -------------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------------