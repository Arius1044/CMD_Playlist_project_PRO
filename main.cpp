#include <iostream>
#include "windows.h"
#include "M_func.h";
#include "S_func.h";

using namespace std;

int main()
{
	setlocale(LC_ALL, "ukr");

	char* comand = new char[100];
	string* comands;
	TCHAR buffer[MAX_PATH];
	





	while (true)
	{

		GetCurrentDirectory(sizeof(buffer), buffer);
		cout << buffer << "\n\n";
		cin.getline(comand, 100);
		comands = devide(comand);

		if (comands[0] == "--m")
		{
			if (comands[1] == "music_list") music_list(buffer);
			else if (comands[1] == "folder_list") folder_list(buffer);
			else if (comands[1] == "cd") cd(buffer);
			else if (comands[1] == "select") select(buffer, comands[2]);
			else if (comands[1] == "help") help();
		}

	}

	system("pause");
	return 0;
}
