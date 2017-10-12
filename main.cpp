#include <iostream>
#include "windows.h"
#include "M_func.h";
#include "S_func.h";
#include "Playlist.h";

using namespace std;



int main()
{
	setlocale(LC_ALL, "ukr");

	TCHAR way[MAX_PATH];
	GetCurrentDirectory(sizeof(way), way);
	string _path_ = way;
	_path_ += +"\\Playlists\\";

	char* comand = new char[100];
	string* comands;

	TCHAR buffer[MAX_PATH];
	string* songs = new string[3000];

	unsigned int count = 0;
	string song;
	string playlist;

	bool IsSave = false;
	bool IsSelectSong = false;
	bool IsOpenPlaylist = false;
	bool IsSelectedPlaylist = false;

	Playlist *Main_playlist;
	Playlist *Support_playlist;

	while (true)
	{


		GetCurrentDirectory(sizeof(buffer), buffer);
		cout << buffer << "\n\n";

		if (!IsOpenPlaylist) cout << "Opened playlist: —\n\n";
		else cout << "Opened playlist: " << Main_playlist->get_name() << "\n\n";

		if (!IsSelectedPlaylist) cout << "Selected playlist: —\n\n";
		else cout <<"Selected playlist: " << playlist << "\n\n";

		if (!IsSelectSong) cout << "Song: —\n\n";
		else cout << "Song: " << song << "\n\n";

		if (!IsSave) cout << "List of Songs: no\n\n";
		else cout << "List of Songs: yes\n\n";

		cout << "_________________________________________________________\n\n";
		cin.getline(comand, 100);
		cout << "_________________________________________________________\n\n";

		int comands_size = 0;
		comands = devide(comand, comands_size);
		if (comands[0] == "--m")
		{
			if (comands[1] == "music_list") 
			{
			  songs = music_list(buffer, count, IsSave);
			  cout << "\n_________________________________________________________\n\n";
			}
			else if (comands[1] == "folder_list") folder_list(buffer);
			else if (comands[1] == "back") back(buffer);
			else if (comands[1] == "select_folder") select_folder(buffer, comands[2]);
			else if (comands[1] == "help") help();
			else if (comands[1] == "playlist_list") playlist_list(buffer);
			else if (comands[1] == "select_song") { song = select_song(buffer, comands[2], IsSelectSong);  }
			else if (comands[1] == "select_playlist") { playlist = select_playlist(buffer, comands[2], IsSelectedPlaylist);  }

			else 
			{
				cout << "Wrong comand!\n";
			    cout << "\n_________________________________________________________\n\n";
			}
		}
		else if (comands[0] == "--c")
		{
			if (comands[1] == "empty") { Main_playlist = new Playlist(comands[2]); IsOpenPlaylist = true;}
			else if (comands[1] == "new")
			{
				if (IsSave) { Main_playlist = new Playlist(songs, count, comands[2]);  IsOpenPlaylist = true; }
				else { Main_playlist = new Playlist(comands[2]); IsOpenPlaylist = true; }
			}
			else if (comands[1] == "open")
			{
				if (IsSelectedPlaylist) { Main_playlist = new Playlist(playlist, comands[2]);  IsOpenPlaylist = true; }
				else
				{
					cout << "\n\nYou haven't a selected playlist!\n\n";
				    cout << "\n_________________________________________________________\n\n";}
			    }
			else if (comands[1] == "info") 
			{
				cout << "\n\n***INFO***\n\n";
				Main_playlist->get_info();
				cout << "\n_________________________________________________________\n\n";
				
			}
			else if (comands[1] == "save")
			{
				Main_playlist->Save(_path_); 
				cout << "\n\n***Saved***\n\n";
				cout << "\n_________________________________________________________\n\n";
			}
			else
			{
				cout << "Wrong comand!\n";
				cout << "\n_________________________________________________________\n\n";
			}

		}

		else if (comands[0] == "--p")
		{
			if (comands[1] == "add_playlist")
			{
				if ((IsSelectedPlaylist)&&(IsOpenPlaylist))
				{ 
				    Support_playlist = new Playlist(playlist, comands[2]); 
					*(Main_playlist)+*(Support_playlist);
				    IsOpenPlaylist = true;
				}
				else
				{
					cout << "\n\nYou haven't a selected or an opened playlist!\n\n";
					cout << "\n_________________________________________________________\n\n";
				}
			}
			else if (comands[1] == "add_song")
			{
				if ((IsSelectSong) && (IsOpenPlaylist))
				{
					*(Main_playlist) + song;
					IsOpenPlaylist = true;
				}
				else
				{
					cout << "\n\nYou haven't a selected song or an opened playlist!\n\n";
					cout << "\n_________________________________________________________\n\n";
				}
			}
			else if (comands[1] == "minus_playlist")
			{
				if ((IsSelectedPlaylist) && (IsOpenPlaylist))
				{
					Support_playlist = new Playlist(playlist, comands[2]);
					*(Main_playlist)-*(Support_playlist);
					IsOpenPlaylist = true;
				}
				else
				{
					cout << "\n\nYou haven't a selected or an opened playlist!\n\n";
					cout << "\n_________________________________________________________\n\n";
				}
			}
			else if (comands[1] == "minus_song")
			{
				if ((IsSelectSong) && (IsOpenPlaylist))
				{
					*(Main_playlist)-song;
					IsOpenPlaylist = true;
				}
				else
				{
					cout << "\n\nYou haven't a selected song or an opened playlist!\n\n";
					cout << "\n_________________________________________________________\n\n";
				}
			}
			else
			{
				cout << "Wrong comand!\n";
				cout << "\n_________________________________________________________\n\n";
			}
		}


		else
		{
			cout << "Wrong comand!\n";
			cout << "\n_________________________________________________________\n\n";
		}
	}
	system("pause");
	return 0;
}