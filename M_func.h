#pragma once
#include <windows.h>
#include <string>

using namespace std;

string* music_list(char* buffer, unsigned int &count);
void folder_list(char* buffer);
void back(char* buffer);
void select(char* buffer, string folder);
void help();