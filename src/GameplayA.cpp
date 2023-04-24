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

    //std::cout << "S_x: " << S_x << "\n";
    //std::cout << "S_y: " << S_y << "\n";
    
    if((S_x>=0)||(S_x<=imgLengX)){
        if((S_y>=0)||(S_y<=imgLengY)){
            //std::cout << "OkToPrint: "<< mSpaceship->Draw() <<"\n";
            //str::strcpy(&imgASCII[S_x][S_y],&mSpaceship->Draw(),1);
        }
    }
    
}

void GameplayA::LoadLevel(int lID)
{
    level = new LevelFile(lID);
    mSpaceship = new Spaceship();
    actualLevel=lID;
}

void GameplayA::UnloadLevel()
{
    delete level;
    delete mSpaceship;
}

void GameplayA::InputMove(int side_ID){
    switch(side_ID){
        // Move spacecraft:
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
        // Move maps on level:
        case GAMEPLAY_MOVE_A:
            msound_engine->PlaySnd(2);
            level->MoveMapLeft();
            break;
        case GAMEPLAY_MOVE_D:
            msound_engine->PlaySnd(2);
            level->MoveMapRight();
            break;
        case GAMEPLAY_MOVE_W:
            msound_engine->PlaySnd(2);
            level->MoveMapUp();
            break;
        case GAMEPLAY_MOVE_S:
            msound_engine->PlaySnd(2);
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

char** GameplayA::GetASCIIimg()
{
    imgASCII=level->GetMapASCII();
    return imgASCII;
}

int GameplayA::GetImgLX()
{
    imgLengX=level->GetMapSizeX();
    return imgLengX;
}

int GameplayA::GetImgLY()
{
    imgLengY=level->GetMapSizeY();
    return imgLengY;
}

// -------------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------------