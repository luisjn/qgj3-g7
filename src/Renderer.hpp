#pragma once
#include <windows.h>
// #include <string>
#include "Sound.hpp" // SE: Add sound engine library
#include "Game.hpp"  // LF: Add file loadding library
#include <string>    // LF: To auto-generate names

class Renderer
{
public:
    bool Initialize(bool *mRunn);
    void Update();
    Renderer();
    ~Renderer();

private:
    int consoleQtyCols, consoleQtyRows; // To get console max text
    void GetConsoleMax();               // To get console max text
    bool *mRunning;
    HANDLE mWindow = nullptr;
    COORD mCursorPosition;

    char **ASCII_img; // To print an car array
    int imgLengX, imgLengY;

    void GoToXY(int x, int y);
    // void PrintASCII(string filename);

    Sound *sound_engine; // SE: In memory object to sound engine interact
    Game *game;          // GP: In memory object to interact
    
    void MergeImageASCII(std::string imgASCIItoMerge, int x0, int y0, int dx, int dy);
    void GetBackgroundImage();
    void RenderBackground();
    void ProcessInput();
    void Clear();
    void Render();
    void Shutdown();
};
