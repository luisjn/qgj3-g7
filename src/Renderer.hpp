#pragma once
#include <windows.h>
// #include <string>

#include "Spaceship.hpp"
#include "Sound.hpp" // SE: Add sound engine library

class Renderer
{
public:
    bool Initialize();
    void Shutdown();
    void Input();
    void Clear();
    void Render();
    void GetSoundEngine(Sound* SoundEngine); // SE: To get the Sound Engine pass by Game Engine

private:
    HANDLE mWindow = nullptr;
    COORD mCursorPosition;

    Spaceship mSpaceship;
    Sound* msound_engine; // SE: In memory object to sound engine interact

    void GoToXY(int x, int y);
    // void PrintASCII(string filename);
};
