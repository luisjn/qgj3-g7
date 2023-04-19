#include <iostream>
// #include <stdlib.h>

#include "Engine.hpp"

bool Engine::Initialize()
{
    mWindow = GetStdHandle(STD_OUTPUT_HANDLE);
    if (mWindow == nullptr)
    {
        return false;
    }

    return true;
}

void Engine::Shutdown()
{
    if (mWindow != nullptr)
    {
        mWindow = nullptr;
    }
    exit(0);
}

void Engine::Run()
{
    mRunning = true;

    while (mRunning)
    {
        ProcessInput();
        Update();
        GenerateOutputs();
    }
}

void Engine::ProcessInput()
{
    std::cout << "input\n";
    // if (GetKeyState(VK_UP) & 0x8000)
    //     std::cout << "up";
    // if (GetKeyState(VK_ESCAPE) & 0x8000)
    //     mRunning = false;
}

// This code implements a “busy wait” (empty while loop) until at least 16ms have passed, ensuring that the maximum FPS will be 60
void Engine::Update()
{
    // Tracks next "clock" value that's acceptable to perform an update.
    static int nextTicks = 0;

    // Tracks the last ticks value each time we run this loop.
    static uint32_t lastTicks = 0;

    // Limit to ~60FPS. "nextTicks" is always +16 at start of frame.
    // If we get here again and 16ms have not passed, we wait.
    while (clock() < nextTicks)
    {
    }

    // Get current ticks value. Save next ticks for +16ms.
    uint32_t currentTicks = clock();
    nextTicks = currentTicks + 16;

    // Calculate change from current to last, and convert to seconds.
    uint32_t deltaTicks = currentTicks - lastTicks;
    float deltaTime = deltaTicks * 0.001f;

    // Save ticks value for next frame.
    lastTicks = currentTicks;

    // For debugging
    // Ensure delta time is never negative.
    if (deltaTime < 0.0f)
    {
        deltaTime = 0.0f;
    }

    // Limit the time delta to 0.05 seconds (about 20FPS).
    if (deltaTime > 0.05f)
    {
        deltaTime = 0.05f;
    }
}

void Engine::GenerateOutputs()
{
    // TODO
    std::cout << "outputs \n";
}
