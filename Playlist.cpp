#define _CRT_SECURE_NO_WARNINGS
#include "MP3_INFO.h"
#include "Playlist.h"
#include "S_func.h"
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

void Playlist::Save(string _path_)
{

	string _name_ = _path_; 
	_name_ += name + ".m3u";

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
}

Playlist::Playlist( string _name_)
{
	name = _name_;
	count_of_songs = 0;
}

Playlist::Playlist(string path, string _name_)
{
	count_of_songs = 0;
	name = _name_;

	ifstream m3u_file(path);
	unsigned count = -1;

	while (!m3u_file.eof())
	{
		char* _path = new char[1000];
		char temp;
		m3u_file.get(temp);

		int counter = 0;

		if (temp == '\n') count++;
		if ((count == 1) && (!m3u_file.eof()))
		{
			char buf;
			m3u_file.get(buf);
			for (int i = 0; ((buf != '\n') && (!m3u_file.eof())); i++)
			{ 
				_path[i] = buf;
			     m3u_file.get(buf); 
				 counter++;
				 if (buf == '\n')  count = 0;
			}
			if (!m3u_file.eof()) 
			{
				string c_path(_path, counter);
				counter = 0;
				Songs[count_of_songs] = read_mp3(c_path);
				count_of_songs++;
			}
		}
		delete[] _path;

	}
	

	m3u_file.close();


}

void  Playlist:: operator+ ( const Playlist &Playlist2)
{
	for (int i = count_of_songs; i < count_of_songs + Playlist2.count_of_songs; i++)
		Songs[i] = Playlist2.Songs[i - count_of_songs];
	count_of_songs += Playlist2.count_of_songs;
}

void Playlist:: operator+ (string song)
{
	Songs[count_of_songs] = read_mp3(song);
	count_of_songs++;
}

void  Playlist:: operator- (const Playlist Playlist2)
{
	for (int i = 0; i < Playlist2.count_of_songs; i++)
		for (int j = 0; j < count_of_songs; j++)
		{
			if (!strcmp(Playlist2.Songs[i].artist, Songs[j].artist) && !strcmp(Playlist2.Songs[i].song, Songs[j].song))
			{
				for (int k = j; k < count_of_songs - 1; k++) swap(Songs[k], Songs[k + 1]); count_of_songs--;
				
			}
		}
}

void  Playlist:: operator- (string song)
{
	MP3_INFO Song = read_mp3(song);
	for (int j = 0; j < count_of_songs; j++)
	{
		if (!strcmp(Song.artist,Songs[j].artist) && !strcmp(Song.song,Songs[j].song))
		{
			for (int k = j; k < count_of_songs - 1; k++) swap(Songs[k], Songs[k + 1]); count_of_songs--;
			break;

		}
	}
}

void Playlist::get_info()
{
	for (int i = 0; i < count_of_songs; i++)
	{
		
		cout << Songs[i].artist << "\t\t\t\t\t";
		cout << Songs[i].song << "\t\t\t\t\t" << endl;
	}
}

string Playlist::get_name()
{
	return name;
}

Playlist::~Playlist()
{
	delete[] Songs;
}