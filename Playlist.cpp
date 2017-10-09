#define _CRT_SECURE_NO_WARNINGS
#include "MP3_INFO.h"
#include "Playlist.h"
#include <windows.h>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

Playlist::Playlist(string* paths, unsigned int count, string _name_)
{
	name = _name_;
	count_of_songs = count;

	if (count_of_songs != 0)
	{
		for (int i = 0; i < count_of_songs; i++)
		{

			ifstream mp3_file(paths[i], ios::binary || ios::in);
			mp3_file.seekg(-128, ios::end);

			mp3_file.read((char*)&Songs[i].ID, sizeof(Songs[i].ID));
			mp3_file.read((char*)&Songs[i].song, sizeof(Songs[i].song));
			mp3_file.read((char*)&Songs[i].artist, sizeof(Songs[i].artist));
			mp3_file.read((char*)&Songs[i].album, sizeof(Songs[i].album));
			mp3_file.read((char*)&Songs[i].year, sizeof(Songs[i].year));
			mp3_file.read((char*)&Songs[i].comment, sizeof(Songs[i].comment));
			mp3_file.read((char*)&Songs[i].genre, sizeof(Songs[i].genre));

			strcpy(Songs[i].path, paths[i].c_str());
			mp3_file.close();
		}
	}
	
}

void Playlist::Save()
{
	string _name_ = name;
	_name_ += ".m3u";


	ofstream m3u_file(_name_);
	m3u_file << "#EXTM3U" << "\n";
	for (int i = 0; i < count_of_songs; i++)
	{

		if (count_of_songs != 0)
		{
			m3u_file << "#EXTINF:" << Songs[i].artist << " — " << Songs[i].song << "\n";
			m3u_file << Songs[i].path << "\n";
		}
	}
	m3u_file.close();
	cout << "\n\n***Done***\n\n";
}

Playlist::Playlist( string _name_)
{
	name = _name_;
	count_of_songs = 0;
}

Playlist::Playlist(string path, string _name_)
{
	count_of_songs = 0;

	ifstream m3u_file(path);
	unsigned count = 0;

	while (!m3u_file.eof())
	{
		string path;
		char temp;
		m3u_file >> temp;
		if (temp=='\n') count++;
		if ((count % 2 == 0) && (count != 0))
		{
			char buf;
			m3u_file >> buf;
			for (int i = 0; buf != '\n'; i++) { path[i] = buf; m3u_file >> buf; } 
			ifstream mp3_file(path, ios::binary || ios::in);
			mp3_file.seekg(-128, ios::end);

			mp3_file.read((char*)&Songs[count_of_songs].ID, sizeof(Songs[count_of_songs].ID));
			mp3_file.read((char*)&Songs[count_of_songs].song, sizeof(Songs[count_of_songs].song));
			mp3_file.read((char*)&Songs[count_of_songs].artist, sizeof(Songs[count_of_songs].artist));
			mp3_file.read((char*)&Songs[count_of_songs].album, sizeof(Songs[count_of_songs].album));
			mp3_file.read((char*)&Songs[count_of_songs].year, sizeof(Songs[count_of_songs].year));
			mp3_file.read((char*)&Songs[count_of_songs].comment, sizeof(Songs[count_of_songs].comment));
			mp3_file.read((char*)&Songs[count_of_songs].genre, sizeof(Songs[count_of_songs].genre));

			strcpy(Songs[count_of_songs].path, path.c_str());
			mp3_file.close();
			count_of_songs++;
		}

	}

	m3u_file.close();


}

Playlist::~Playlist()
{
	delete[] Songs;
}