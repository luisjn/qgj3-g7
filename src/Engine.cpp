#include "Engine.hpp"

bool Engine::Initialize()
{
    mRenderer.Initialize();

    return true;
}

void Engine::Shutdown()
{
    mRenderer.Shutdown();
}

void Engine::Run()
{
    float dt = 0;
    mRunning = true;

    while (mRunning)
    {
        ProcessInput();
        dt = Update();
        GenerateOutputs();
    }
}

void Engine::ProcessInput()
{
    mRenderer.Input();
}

// This code implements a “busy wait” (empty while loop) until at least 16ms have passed, ensuring that the maximum FPS will be 60
float Engine::Update()
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
    nextTicks = currentTicks + mFrameTime;
    // nextTicks = currentTicks + 16;

    // Calculate change from current to last, and convert to seconds.
    uint32_t deltaTicks = currentTicks - lastTicks;
    float deltaTime = deltaTicks * 0.001f;

    // Save ticks value for next frame.
    lastTicks = currentTicks;

    /*
     * For debugging
     */

    // Ensure delta time is never negative.
    // if (deltaTime < 0.0f)
    // {
    //     deltaTime = 0.0f;
    // }

    // Limit the time delta to 0.05 seconds (about 20FPS).
    // if (deltaTime > 0.05f)
    // {
    //     deltaTime = 0.05f;
    // }

    /*
     * For debugging
     */

    return deltaTime;
}

void Engine::GenerateOutputs()
{
    mRenderer.Clear();
    mRenderer.Render();
    // mRenderer.Present();
}
