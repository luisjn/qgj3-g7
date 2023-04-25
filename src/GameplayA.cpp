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
    //image = new ImageASCII();
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
    //delete image;
    //delete level;
    //delete msound_engine;
}

// Voids: ------------------------------------------------------------------------------------------------------------

void GameplayA::MergeImageASCII(std::string imgASCIItoMerge, int x0, int y0, int dx, int dy)
{
    int calc;
    for(int y=0;y<dy;y++){
        for(int x=0;x<dx;x++){
            calc=(y*dx)+y+x;
            imgASCII[y+y0][x+x0]=(char)imgASCIItoMerge[calc];
        }
    }
}

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
//    std::cout << "gameState: "<< gameState << "\n";
    gameState = GAMEPLAY_STATE_PRESENTATION; // HARDCODE JUMP TO NEXT STATE...
}


void GameplayA::GameplayOnPresentation()
{
//    std::cout << "gameState: "<< gameState << "\n";
    gameState = GAMEPLAY_STATE_MAIN_MENU; // HARDCODE JUMP TO NEXT STATE...
}

void GameplayA::GameplayOnMainMenu()
{
    if(mainMenu==NULL){
        mainMenu = new MenuBasic(5,5,25,15);
    }else{
        mainMenu->Run();
        if(!mainMenu->OnActive()){
            delete mainMenu;
            gameState = GAMEPLAY_STATE_ON_GAME;
            mainMenu=NULL;
            LoadLevel(actualLevel);
        }
    }
}

void GameplayA::GameplayOnRun()
{
    int S_x = mSpaceship->Position.x;
    int S_y = mSpaceship->Position.y;
    if((S_x>=0)||(S_x<=imgLengX)){
        if((S_y>=0)||(S_y<=imgLengY)){
            //std::cout << "OkToPrint: "<< mSpaceship->Draw() <<"\n";
            //str::strcpy(&imgASCII[S_x][S_y],&mSpaceship->Draw(),1);
        }
    }
}

void GameplayA::GameplayOnPause()
{
//    std::cout << "gameState: "<< gameState << "\n";
    gameState = GAMEPLAY_STATE_ON_GAME; // HARDCODE JUMP BACK TO GAME...
}

void GameplayA::GameplayOnEnd()
{
//    std::cout << "gameState: "<< gameState << "\n";
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

void GameplayA::Input(int side_ID){
     switch(gameState){
        case GAMEPLAY_STATE_INTIAL:
            break;
        case GAMEPLAY_STATE_PRESENTATION:
            break;
        case GAMEPLAY_STATE_MAIN_MENU:
            mainMenu->Input(side_ID);
            break;
        case GAMEPLAY_STATE_PAUSE:
            break;
        case GAMEPLAY_STATE_END_GAME:
            break;
        case GAMEPLAY_STATE_ON_GAME:
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
                case GAMEPLAY_JUMPLEVEL_00:
                    gameState = GAMEPLAY_STATE_MAIN_MENU; // HARDCODE JUMP TO NEXT STATE...
                    break;
                case GAMEPLAY_JUMPLEVEL_01:
                    if (actualLevel==0){
                        LoadLevel(1); // GP: Initiated "Level_0.txt"
                    }else{
                        LoadLevel(0); // GP: Initiated "Level_0.txt"
                    }
                    break;
            }
            break;
        }
}

char** GameplayA::GetASCIIimg()
{
    imgASCII=level->GetMapASCII();
    if(gameState==GAMEPLAY_STATE_MAIN_MENU){
        if(mainMenu!=NULL){
            MergeImageASCII(
                mainMenu->GetImage()->ToString(),
                mainMenu->GetX0(),
                mainMenu->GetY0(),
                mainMenu->GetImage()->imgLengX,
                mainMenu->GetImage()->imgLengY);
        }
    }   
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