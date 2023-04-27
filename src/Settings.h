#pragma once
// This section may be used to apply all the "#defines" to use the program

// Define for general propourse:
// -----------------------------
// A) Debug Mode activated if this line are activated and no commented ("//"):
// #define DEBUG_MODE

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
// #define SOUND_ENGINE_SDL2
//  B) Define if Sound start ENABLE by default:
#define SOUND_ENGINE_AUTOSTART
// C) Files "WAV" locations:
#define SOUND_HIT_00_PATH "Sounds/Hit_00.wav"
#define SOUND_HIT_01_PATH "Sounds/Hit_01.wav"
#define SOUND_HIT_02_PATH "Sounds/Hit_02.wav"
#define SOUND_HIT_03_PATH "Sounds/Hit_03.wav"
#define MUSIC_00_PATH "Music/Juhani Junkala [Retro Game Music Pack] Ending.wav"

// Define for Load Files:
// ----------------------
// A) Character to "jump" line (Enter):
#define CHAR_LINE_BREAK '\n'

// Define for Levels:
// ------------------
// A) Files "LVL" locations (TXT files) (non-automatic):
#define GAME_LEVEL_00_PATH "Levels/Level_00.txt"
// B) Generates "LVL" files (TXT files) (automatic name):
#define GAME_LEVEL_NAME_INITIAL_PATH "Levels/Level_"
#define GAME_LEVEL_EXTENTION ".txt"

// Define for Maps:
// ----------------
// A) Files "MAP" locations (TXT files) (non-automatic):
// #define GAME_MAP_00_PATH "Levels/Map_00.txt"
// B) Generates "MAP" files (TXT files) (automatic name):
#define GAME_MAP_NAME_INITIAL_PATH "Levels/Map_"
#define GAME_MAP_NAME_SEPARATION "_"
#define GAME_MAP_EXTENTION ".txt"

// Define for Gameplay:
// --------------------
// A) Move input type:
//    Move Arrows:
#define GAMEPLAY_MOVE_LEFT 0
#define GAMEPLAY_MOVE_RIGHT 1
#define GAMEPLAY_MOVE_UP 2
#define GAMEPLAY_MOVE_DOWN 3
//    Move Keys:
#define GAMEPLAY_MOVE_A 10
#define GAMEPLAY_MOVE_D 11
#define GAMEPLAY_MOVE_W 12
#define GAMEPLAY_MOVE_S 13
//    Move Shotd:
#define GAMEPLAY_SHOOT 20
//    Move Manu:
#define GAMEPLAY_INTRO 30
#define GAMEPLAY_EXIT 31
//    Move SPECIALs:
#define GAMEPLAY_JUMPMAINMENU 40
#define GAMEPLAY_JUMPLEVEL_00 50
#define GAMEPLAY_JUMPLEVEL_01 51
// B) Interrupt input type:
#define GAMEPLAY_INTERRUMP_F1 10
// C) Gameplay states:
#define GAMEPLAY_STATE_INTIAL 0
#define GAMEPLAY_STATE_PRESENTATION 1
#define GAMEPLAY_STATE_MAIN_MENU 2
#define GAMEPLAY_STATE_ON_GAME 3
#define GAMEPLAY_STATE_PAUSE 4
#define GAMEPLAY_STATE_END_GAME 5

// Console
#define Width 120
#define Height 29
#define Limit 1

// Define for Menues:
// --------------------
// A) Menues available:
#define MENU_MAINMENU_CODE 0
#define MENU_PAUSEMENU_CODE 1

// Define for Enemies:
#define ENEMY_RADIOUS_IMPACT 0.25f

// B) Files of menues:
#define MENU_MAINMENU_FILE "UI/MainMenu_00.txt"
#define MENU_PAUSEMENU_FILE "UI/PauseMenu_00.txt"
// C) Option for menues:
#define MENU_CHARACTER_TO_SELECT "X"
//    Commond to various menues:
#define MENU_ACTION_NULL 0
#define MENU_ACTION_CONTINUE_GAME 1
#define MENU_ACTION_SWITCH_SOUND 2
#define MENU_ACTION_EXIT_GAME -1
//    Only for Main Menu:
#define MENU_ACTION_GET_HELP 3
#define MENU_ACTION_LOAD_SAVE 4
#define MENU_ACTION_GO_PRESENTATION 6
//    Only for Pause Menu:
#define MENU_ACTION_BACK_MAINMENU 5

// Define for Cinematics:
// --------------------
// A) Files of cinematics:
#define CINEMATIC_INITIAL_FILE "Cinematic/Initial_00.txt"
#define CINEMATIC_END_FILE "Cinematic/End_00.txt"
#define CINEMATIC_ENDGOOD_FILE "Cinematic/EndGood_00.txt"
#define CINEMATIC_ENDFAIL_FILE "Cinematic/EndFail_00.txt"
#define CINEMATIC_CREDITS_FILE "Cinematic/Credits_00.txt"
#define CINEMATIC_HELP_FILE "Cinematic/Help_00.txt"
// B) Index of cinematics:
#define CINEMATIC_INITIAL 0
#define CINEMATIC_END 1
#define CINEMATIC_ENDGOOD 2
#define CINEMATIC_ENDFAIL 3
#define CINEMATIC_CREDITS 4
#define CINEMATIC_HELP 5
