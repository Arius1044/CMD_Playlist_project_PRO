#pragma once
#include <windows.h>
#include <string>

using namespace std;

string* music_list(char* buffer, unsigned int &count, bool &flag);
void folder_list(char* buffer);
void back(char* buffer);
void select_folder(char* buffer, string folder);
string select_playlist(char* buffer, string playlist, bool &flag);
string select_song(char* buffer, string song, bool &flag);
void playlist_list(char* buffer);
void help();