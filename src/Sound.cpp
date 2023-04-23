// -------------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------------

// Class declare and external libs required: -------------------------------------------------------------------------

#include <iostream>
// #include <stdlib.h>
#include "Sound.hpp"

// Constructor and destructor: ---------------------------------------------------------------------------------------

Sound::Sound()
{
#ifdef DEBUG_MODE
	std::cout << "Sound Start...\n";
#endif
}

Sound::Sound(bool activeInitial)
{
#ifdef DEBUG_MODE
	std::cout << "Sound Start...\n";
#endif
	SetActivatedSound(activeInitial);
}

Sound::~Sound()
{
#ifdef DEBUG_MODE
	std::cout << "Sound Closed.\n";
#endif
}

// Voids: ------------------------------------------------------------------------------------------------------------

void Sound::SetActivatedSound(bool newSoundState)
{
#ifdef DEBUG_MODE
	std::cout << "Change Sound State to:: " << newSoundState << "\n";
#endif

#ifdef SOUND_ENGINE_WINDOWS
	if(!newSoundState){
		StopSnd();
	}
#endif

	soundActivated = newSoundState;
}

bool Sound::ChangeActivatedSound()
{
	SetActivatedSound(!soundActivated);
	return soundActivated;
}

bool Sound::GetSoundActivated()
{
	return soundActivated;
}

void Sound::PlaySnd(int id)
{
	if(soundActivated){
#ifdef DEBUG_MODE
		std::cout << "PlaySound, ID: " << id << "\n";
#endif

#ifdef SOUND_ENGINE_WINDOWS
		// Leard about "SND_*" #defines: https://learn.microsoft.com/en-us/previous-versions/dd743680(v=vs.85)
		if (id == 0) {
			PlaySound(TEXT(SOUND_HIT_00_PATH), NULL, SND_FILENAME | SND_ASYNC);
		}
		if (id == 1) {
			PlaySound(TEXT(SOUND_HIT_01_PATH), NULL, SND_FILENAME | SND_ASYNC);
		}
		if (id == 2) {
			PlaySound(TEXT(SOUND_HIT_02_PATH), NULL, SND_FILENAME | SND_ASYNC);
		}
		if (id == 3) {
			PlaySound(TEXT(SOUND_HIT_03_PATH), NULL, SND_FILENAME | SND_ASYNC);
		}
#endif

	}
}

void Sound::PlayMusic(int id)
{
	if(soundActivated){
#ifdef DEBUG_MODE
		std::cout << "PlayMusic, ID: " << id << "\n";
#endif

#ifdef SOUND_ENGINE_WINDOWS
		// Leard about "SND_*" #defines: https://learn.microsoft.com/en-us/previous-versions/dd743680(v=vs.85)
		if (id == 0) {
			PlaySound(TEXT(MUSIC_00_PATH), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
		}
#endif

	}
}

void Sound::StopSnd()
{
#ifdef DEBUG_MODE
	std::cout << "StopSound.\n";
#endif

#ifdef SOUND_ENGINE_WINDOWS
	PlaySound(NULL, 0, 0);
#endif

}

// -------------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------------