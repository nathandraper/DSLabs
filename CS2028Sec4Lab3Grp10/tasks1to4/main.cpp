#include "Complex.h"
#include <iostream>
#include <cmath>

using namespace std;

int main() {
	double realA;
	double imaginaryA;
	double realB = 0;
	double imaginaryB = 0;
	int opChoice;
	double scalar = 0;
	char run = 'y';

	cout << "Enter the real part of your number: ";
	cin >> realA;
	cout << "Enter the imaginary part of your number: ";
	cin >> imaginaryA;

	Complex A(realA, imaginaryA);

	while (run == 'y') {
		
		cout << "Which operation would you like to perform?" << endl;
		cout << "1: add" << endl;
		cout << "2: subtract" << endl;
		cout << "3: multiply" << endl;
		cout << "4: divide" << endl;
		cout << "5: equals" << endl;
		cin >> opChoice;

		if (opChoice == 3 || opChoice == 4) {
			cout << "Enter a scalar number: ";
			cin >> scalar;
		}
		else {
			cout << "Enter the real part of the second number: ";
			cin >> realB;
			cout << "Enter the imaginary part of the second number: ";
			cin >> imaginaryB;
		}

		Complex B(realB, imaginaryB);

		switch (opChoice) {
		case 1:
			A + B;
			break;
		case 2:
			A - B;
			break;
		case 3:
			A * scalar;
			break;
		case 4:
			A / scalar;
			break;
		case 5:
			if (A == B) {
				cout << "The numbers are equal." << endl;
			}
			else {
				cout << "The numbers are not equal." << endl;
			}
			break;
		}

		A.printNumber();

		cout << "would you like to continue? y/n";
		cin >> run;
	}
	return 0;
}