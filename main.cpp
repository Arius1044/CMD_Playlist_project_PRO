
#include <iostream>
#include "S_func.h";

using namespace std;

int main()
{
	char* comand = new char[100];
	string* comands;
	cin.getline(comand, 100);

	comands = devide(comand);

	for (int i = 0; i < 4; i++) cout << comands[i]<<"\n";

	//while (true)
	//{
	//	
	//}

	system("pause");
	return 0;
}