#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include "S_func.h"
#include <windows.h>
#include <string>

using namespace std;

string* devide(char* comand)
{

	string* lexems = new string[4];
	char *token;
	char *cst = new char[100];

	strcpy(cst, comand);
	char *baryer = " ";
	token = strtok(cst, baryer);

	int i = 0;

	while (token != NULL)
	{
		lexems[i++] = token;
		token = strtok(NULL, baryer);
	}

	delete[] cst, baryer;
	return lexems;
}


