#pragma once
// External libs required: -------------------------------------------------------------------------------------------

#include "Settings.h" // General Game DEFINEs
#include <windows.h> // Default ound need (Windows) (no parallel sounds)
#pragma comment(lib, "winmm.lib") // Default sound need (Windows) (no parallel sounds)

// Class declare: ----------------------------------------------------------------------------------------------------

class Sound
{
private:
    bool soundActivated;
public:
    void PlaySnd(int id);
    void PlayMusic(int id);
    void StopSnd();
    void SetActivatedSound(bool newSoundState);
    bool ChangeActivatedSound();
    bool GetSoundActivated();
    Sound(bool activeInitial);
    Sound();
    ~Sound();
};