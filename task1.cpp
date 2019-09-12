// Data Structures Lab 2
// task 1
// 9/11/2019
// Nathan Draper
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
	ifstream file;
	string filename;
	string input;

	const int LINES = 10;

	cout << "enter file name: ";
	cin >> filename;
	file.open(filename);

	if (!file.is_open()) {
		cout << "file does not exist." << endl;
		return 0;
	}

	int count = LINES;
	while (!file.eof() && count > 0){
		getline(file, input);
		cout << input << endl;
		count--;
	}
	file.close();
}