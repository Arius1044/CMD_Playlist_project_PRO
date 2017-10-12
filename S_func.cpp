#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include "S_func.h"
#include <windows.h>
#include <string>
#include "MP3_INFO.h"
#include <iostream>
#include <fstream>

using namespace std;

string* devide(char* comand, int &count)
{

	setlocale(LC_ALL, "ukr");

	string* lexems = new string[20];
	char *token;
	char *cst = new char[1000];

	strcpy(cst, comand);
	char *baryer = " ";
	token = strtok(cst, baryer);

	int i = 0;

	while (token != NULL)
	{
		lexems[i++] = token;
		token = strtok(NULL, baryer);
		if (i == 2) break;
	}

	int len = lexems[0].length() + lexems[1].length();

	for (int j = len+2; j < strlen(comand); j++) lexems[2] += comand[j];

	count = i;
	count++;

	delete[] cst, baryer;
	return lexems;
}

MP3_INFO read_mp3(string path)
{
	MP3_INFO Song;

	ifstream mp3_file(path, ios::binary || ios::in);
	mp3_file.seekg(-128, ios::end);

	mp3_file.read((char*)&Song.ID, sizeof(Song.ID));
	mp3_file.read((char*)&Song.song, sizeof(Song.song));
	mp3_file.read((char*)&Song.artist, sizeof(Song.artist));
	mp3_file.read((char*)&Song.album, sizeof(Song.album));
	mp3_file.read((char*)&Song.year, sizeof(Song.year));
	mp3_file.read((char*)&Song.comment, sizeof(Song.comment));
	mp3_file.read((char*)&Song.genre, sizeof(Song.genre));

	strcpy(Song.path, path.c_str());
	mp3_file.close();

	return Song;
}
