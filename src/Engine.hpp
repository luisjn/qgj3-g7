#pragma once

#include "Renderer.hpp"
#include "Settings.h" // General Game DEFINEs

class Engine
{
public:
    bool Initialize();
    void Shutdown();
    void Run();

private:
    bool mRunning = false;
    float mFrameTime = 60; // 40=25fps 33=30fps, 16=60fps
    Renderer* mRenderer; // Renderer (principal function for View-Presentator Model)
    float Update();
};
