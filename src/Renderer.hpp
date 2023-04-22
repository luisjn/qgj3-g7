#pragma once
#include <windows.h>
// #include <string>

#include "Spaceship.hpp"

class Renderer
{
public:
    bool Initialize();
    void Shutdown();
    void Input();
    void Clear();
    void Render();

private:
    HANDLE mWindow = nullptr;
    COORD mCursorPosition;

    Spaceship mSpaceship;

    void GoToXY(int x, int y);
    // void PrintASCII(string filename);
};
