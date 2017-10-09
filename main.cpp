#include <iostream>
#include "windows.h"
#include "M_func.h";
#include "S_func.h";
#include "Playlist.h";

using namespace std;

int main()
{
	setlocale(LC_ALL, "ukr");
	char* comand = new char[100];
	string* comands;
	TCHAR buffer[MAX_PATH];
	string* songs = new string[3000];
	unsigned int count = 0;
	bool IsSave = false;

	while (true)
	{


		GetCurrentDirectory(sizeof(buffer), buffer);
		cout << buffer << "\n\n";
		cin.getline(comand, 100);
		comands = devide(comand);

		if (comands[0] == "--m")
		{
			if (comands[1] == "music_list") music_list(buffer, count);
			else if (comands[1] == "folder_list") folder_list(buffer);
			else if (comands[1] == "back") back(buffer);
			else if (comands[1] == "select") select(buffer, comands[2]);
			else if (comands[1] == "help") help();
			else if (comands[1] == "save_song_list") { songs = music_list(buffer, count); IsSave = true; }
		}
		else if (comands[0] == "--p")
		{
			if (comands[1] == "create_playlist")
			{
				if (comands[2] == "empty") { Playlist playlist(comands[3]); playlist.Save(); }
				else
				{
					if (IsSave) { Playlist playlist(songs, count, comands[2]);  playlist.Save(); }
					else { Playlist playlist(comands[2]);  playlist.Save(); }
				}
			}


		}
	}
	system("pause");
	return 0;
}