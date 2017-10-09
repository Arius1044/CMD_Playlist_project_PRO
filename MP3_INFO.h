#pragma once
#include <string>

struct MP3_INFO
{
	char* path = new char[1000];
	char ID[3];
	char song[30];
	char artist[30];
	char album[30];
	char year[4];
	char comment[30];
	int genre;

};

