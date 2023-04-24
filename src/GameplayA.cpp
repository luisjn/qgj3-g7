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
    gameState = GAMEPLAY_STATE_INTIAL;
    LoadLevel(0);
/*
    imgASCII = new char*[1];
    imgASCII[0] = new char[1];
    imgASCII[0][0] = '0';
    imgLengX =1;
    imgLengY =1;
*/
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
    switch(gameState){
        case GAMEPLAY_STATE_INTIAL:
            GameplayInitial();
            break;
        case GAMEPLAY_STATE_PRESENTATION:
            GameplayOnPresentation();
            break;
        case GAMEPLAY_STATE_MAIN_MENU:
            GameplayOnMainMenu();
            break;
        case GAMEPLAY_STATE_ON_GAME:
            GameplayOnRun();
            break;
        case GAMEPLAY_STATE_PAUSE:
            GameplayOnPause();
            break;
        case GAMEPLAY_STATE_END_GAME:
            GameplayOnEnd();
            break;
        }
}

void GameplayA::GameplayInitial()
{
    std::cout << "gameState: "<< gameState << "\n";
    gameState = GAMEPLAY_STATE_PRESENTATION; // HARDCODE JUMP TO NEXT STATE...
}


void GameplayA::GameplayOnPresentation()
{
    std::cout << "gameState: "<< gameState << "\n";
    gameState = GAMEPLAY_STATE_MAIN_MENU; // HARDCODE JUMP TO NEXT STATE...
}

void GameplayA::GameplayOnMainMenu()
{
    int sdfs;
    std::cout << "gameState: "<< gameState << "\n";
    std::cout << "\nInt pause...\n";
    std::cin >> sdfs;
    //LoadLevel(0);
    gameState = GAMEPLAY_STATE_ON_GAME; // HARDCODE JUMP BACK TO GAME...
    
}

void GameplayA::GameplayOnRun()
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

void GameplayA::GameplayOnPause()
{
    std::cout << "gameState: "<< gameState << "\n";
    gameState = GAMEPLAY_STATE_ON_GAME; // HARDCODE JUMP BACK TO GAME...
}

void GameplayA::GameplayOnEnd()
{
    std::cout << "gameState: "<< gameState << "\n";
    gameState = GAMEPLAY_STATE_ON_GAME; // HARDCODE JUMP BACK TO GAME...
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