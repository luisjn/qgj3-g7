#pragma once
// This section may be used to apply all the "#defines" to use the program

// Define for general propourse:
// -----------------------------
// A) Debug Mode activated if this line are activated and no commented ("//"):
//#define DEBUG_MODE


// Define for Credits:
// -------------------
#define CREDITS_INCLUDE
// A) People include:
#define CREDITS_INCLUDE
#define CREDITS_INCLUDE
#define CREDITS_INCLUDE

// Define for Engine:
// ------------------
// A) Use some restriction to FPSs input:
#define ENGINE_RESTRICT_FPS

// Define for Sounds:
// ------------------
#define SOUND_ENGINE_INCLUDE
// A) Define ONLY one type of Sound type (add "//" to the other):
#define SOUND_ENGINE_WINDOWS
//#define SOUND_ENGINE_SDL2
// B) Files "WAV" locations:
#define SOUND_HIT_00_PATH "Sounds/Hit_00.wav"
#define SOUND_HIT_01_PATH "Sounds/Hit_01.wav"
#define SOUND_HIT_02_PATH "Sounds/Hit_02.wav"
#define SOUND_HIT_03_PATH "Sounds/Hit_03.wav"
#define MUSIC_00_PATH "Music/Juhani Junkala [Retro Game Music Pack] Ending.wav"

// Define for Levels:
// ------------------
// B) Files "LVL" locations (TXT files):
#define LEVEL_00_PATH "Levels/Level_00.txt"
