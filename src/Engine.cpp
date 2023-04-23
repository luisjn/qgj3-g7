#include "Engine.hpp"

bool Engine::Initialize()
{
    // Initiate random character generator (for test propourse):
    srand(time(0));

    mRenderer.Initialize();
    sound_engine = new Sound(); // SE: Initied Sound Engine
    level_00 = new LevelFile(0); // LF: Initiated Level 00

    mRenderer.GetSoundEngine(sound_engine);
    return true;
}

void Engine::Shutdown()
{
    delete sound_engine; // SE: Delete Sound Engine
    delete level_00; // LF: Delete Load File

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
    if (GetKeyState(VK_F9) & 0x8000)
    {
    }
    if (GetKeyState(VK_F10) & 0x8000)
    {
    }
    if (GetKeyState(VK_F11) & 0x8000)
    {
    }
    if (GetKeyState(VK_F12) & 0x8000)
    {
    }
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
