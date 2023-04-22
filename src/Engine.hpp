#pragma once

#include "Renderer.hpp"

class Engine
{
public:
    bool Initialize();
    void Shutdown();
    void Run();

private:
    bool mRunning = false;
    float mFrameTime = 33; // 40=25fps 33=30fps, 16=60fps

    Renderer mRenderer;

    void ProcessInput();
    float Update();
    void GenerateOutputs();
};
