#pragma once

#include "Renderer.hpp"
#include "Sound.hpp" // SE: Add sound engine library
#include "LoadFile.hpp" // LF: Add file loadding library

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
    LoadFile* load_file; // LF: In memory object to file interact

    Renderer mRenderer;

    void ProcessInput();
    float Update();
    void GenerateOutputs();
};
