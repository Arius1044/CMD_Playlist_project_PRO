#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "M_func.h"
#include <windows.h>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

string* music_list(char* buffer, unsigned int &count)
{
	cout << endl;
	int i = 0;
	string *paths = new string[3000];

	WIN32_FIND_DATA File_Data;
	HANDLE hand;

	char* c_buffer = new char[100];
	strcpy(c_buffer, buffer);
	strcat(c_buffer, "\\*.mp3");


	hand = FindFirstFile(c_buffer, &File_Data);
	if (hand != INVALID_HANDLE_VALUE)
	{
		do
		{
		    cout << File_Data.cFileName << "\n";
			string temp = File_Data.cFileName;
			paths[i] += buffer;
			paths[i] += "\\";
			paths[i++] += temp;

		} 
		while (FindNextFile(hand, &File_Data) != 0);

		FindClose(hand);
	}

	delete[] c_buffer;
	cout << endl;
	count = i;
	return paths;
}

void folder_list(char* buffer)
{
	cout << endl;

	WIN32_FIND_DATA Folder_Data;
	HANDLE hand;

	char* c_buffer = new char[100];
	strcpy(c_buffer, buffer);
	strcat(c_buffer, "\\*");

	hand = FindFirstFile(c_buffer, &Folder_Data);

	if (hand != INVALID_HANDLE_VALUE)
	{
		do
		{
			if (Folder_Data.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) cout << Folder_Data.cFileName << endl;
			
		} while (FindNextFile(hand, &Folder_Data) != 0);

		FindClose(hand);
	}
	delete[] c_buffer;
	cout << endl;
}

void back(char* buffer)
{
	int count = 0;
	string nbuffer;
	int size = strlen(buffer);
	for (int i = size; i > 0; i--)
	{
		count++;
		if (buffer[i] == '\\') 
		{
			if (buffer[i - 1] == ':') count--;
			for (int j = 0; j <size - count + 1; j++) nbuffer+=buffer[j];
			break;
	    }
	}

	SetCurrentDirectory(nbuffer.c_str());
	cout << endl;
}

void select(char* buffer, string folder)
{
	string c_buffer;
	c_buffer = buffer;

	c_buffer = c_buffer + "\\"+ folder;
	SetCurrentDirectory(c_buffer.c_str());
	cout << endl;
}

void help()
{

	ifstream f("help.txt");

	int n = 0;
	while (!f.eof()) {
		string definition;
		f >> definition;
		cout << definition << " ";
		if (definition == ";")
		{
			cout << "\n";
		}
		n++;
	}

	f.close();
	cout << endl;
}

void playlist_list(char* buffer)
{
	cout << endl;
	int i = 0;
	string *paths = new string[3000];

	WIN32_FIND_DATA File_Data;
	HANDLE hand;

	char* c_buffer = new char[100];
	strcpy(c_buffer, buffer);
	strcat(c_buffer, "\\*.m3u");


	hand = FindFirstFile(c_buffer, &File_Data);
	if (hand != INVALID_HANDLE_VALUE)
	{
		do
		{
			cout << File_Data.cFileName << "\n";

		} while (FindNextFile(hand, &File_Data) != 0);

		FindClose(hand);
	}

	delete[] c_buffer;
	cout << endl;
}

string select_playlist(char* buffer, string playlist)
{
	string c_buffer;
	c_buffer = buffer;

	c_buffer = c_buffer + "\\" + playlist + ".m3u";
	cout << endl;

	return c_buffer;
}