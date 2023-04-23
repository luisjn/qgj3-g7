#pragma once

#include "Renderer.hpp"
#include "Settings.h" // General Game DEFINEs
#include "Sound.hpp" // SE: Add sound engine library
#include "LevelFile.hpp" // LF: Add file loadding library
#include <string> // LF: To auto-generate names

class Engine
{
public:
    bool Initialize();
    void Shutdown();
    void Run();

private:
    bool mRunning = false;
    float mFrameTime = 33; // 40=25fps 33=30fps, 16=60fps

    Sound* sound_engine;  // SE: In memory object to sound engine interact
    LevelFile* level_00; // LF: In memory object to file interact - Level

    Renderer mRenderer;

    void ProcessInput();
    float Update();
    void GenerateOutputs();
};
