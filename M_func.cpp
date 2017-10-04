#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "M_func.h"
#include <windows.h>
#include <string>
#include <iostream>
using namespace std;

void music_list(char* buffer)
{
	cout << endl;

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
		} 
		while (FindNextFile(hand, &File_Data) != 0);

		FindClose(hand);
	}
	delete[] c_buffer;
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
}
