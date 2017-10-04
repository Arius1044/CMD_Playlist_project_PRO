#include <iostream>;
#include <string>;
#include <fstream>
void readfile() {
	
	ifstream f("help.txt");

	int n = 0;
	while (!f.eof()) {
		string definition;
		f >>definition;
		cout << definition <<" ";
		if (definition == ";") {
			cout << "\n";
		}
		n++;
	}

	f.close();

}
