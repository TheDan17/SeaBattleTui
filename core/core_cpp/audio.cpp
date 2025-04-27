#include "../core_h/audio.h"

#include "windows.h"
#include <filesystem>

std::string sound_select_path_str = "..\\resources\\Select.wav";
const char* sound_select_path = sound_select_path_str.c_str();

// todo play_game_sound(sounds.select);
void play_select_sound(){
    PlaySound(sound_select_path, NULL, SND_FILENAME | SND_ASYNC);
}