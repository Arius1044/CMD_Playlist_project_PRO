#include <iostream>;
#include <string>;
#include <fstream>
using namespace std;
void readfile() {
	string way;
	cout << "Enter the way to your file - ";
	cin >> way;
	ifstream f(way);

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
int main() {
	readfile();
	system("pause");
	return 0; 
}
