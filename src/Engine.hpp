#pragma once
#include <windows.h>

class Engine
{
public:
    bool Initialize();
    void Shutdown();
    void Run();

private:
    bool mRunning = false;
    HANDLE mWindow = nullptr;

    void ProcessInput();
    void Update();
    void GenerateOutputs();
};
