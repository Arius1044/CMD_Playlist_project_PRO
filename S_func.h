#pragma once
#include "MP3_INFO.h"
#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

string* devide(char* comand, int &count);

MP3_INFO read_mp3(string path);