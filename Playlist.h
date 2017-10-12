#pragma once
#include <string>
#include "MP3_INFO.h"
using namespace std;

class Playlist
{
private:
	string name;
	MP3_INFO *Songs = new MP3_INFO[3000];
	unsigned int count_of_songs;

public:
	Playlist(string* songs, unsigned int count, string _name_);
	Playlist(string _name_);
	Playlist(string path ,string _name_);
	void Save(string _path_);
	void operator+ (const Playlist &Playlist2);
	void operator+ (string song);
	void operator- (const Playlist Playlist2);
	void operator- (string song);
	void get_info();

	string get_name();

	~Playlist();

};