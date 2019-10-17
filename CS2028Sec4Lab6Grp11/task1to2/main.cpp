#include <iostream>
#include "Stack.h"
#include "StackOverflow.h"
#include "StackUnderflow.h"

using namespace std;

const int NUM_TOWERS = 3;

// This function prompts the user for an integer, validates that the input stream has no errors, and then returns the integer
int getInt() {
	int num;

	cin >> num;

	// Validation
	while (cin.fail() || num <= 1) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Enter a valid integer > 1: ";
		cin >> num;
	}

	return num;
}

int getTower() {
	int num;

	cin >> num;

	// Validation
	while (cin.fail() || num <= 0 || num > 3) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Enter an integer from 1 to 3: ";
		cin >> num;
	}

	return num;
}

void displayTower(Stack<int> tower) {
	for (int i = 0; i < tower.length(); i++) {
		cout << *tower.stack[i] << "_";
	}
	cout << endl;
}

void printTowers(Stack<int> towers[]) {
	for (int i = 0; i < NUM_TOWERS; i++) {
		cout << "Tower " << i + 1 << endl;
		displayTower(towers[i]);
	}
}

int main() {
	int choice1;
	int choice2;
	bool comparison;
	int playerTower;

	// prompt user for number of discs to play with
	cout << "Enter number of discs: ";
	int numDiscs = getInt();

	// create five empty towers
	Stack<int> towers[NUM_TOWERS] = { Stack<int>(numDiscs), Stack<int>(numDiscs), Stack<int>(numDiscs) };

	// fill first and last tower with discs
	towers[0].fill();

	cout << "Let the game begin." << endl;
	bool run = true;
	bool choose;
	while (run) {

		cout << "Tower status:" << endl;
		printTowers(towers);

		choose = true;
		while (choose) {
			cout << "Select tower to move from: ";
			choice1 = getTower() - 1;

			cout << "Select tower to move to: ";
			choice2 = getTower() - 1;

			try {
				comparison = *towers[choice1].top() < *towers[choice2].top();
			}
			catch (StackUnderflow e) {
				comparison = true;
			}

			if (comparison) {
				try {
					towers[choice2].push(towers[choice1].pop());
				}
				catch (StackOverflow e) {
					cout << "That tower is full." << endl;
					cout << e.what() << endl;
					choose = true;
				}
				catch (StackUnderflow e) {
					cout << "That tower is empty." << endl;
					cout << e.what() << endl;
					choose = true;
				}
				choose = false;
			}
			else {
				cout << "You can only move a smaller disc onto a bigger disc." << endl;
				choose = true;
			}
		}

		if (towers[2].isFull()) {
			cout << "The tower is complete! Thank you for playing." << endl;
			run = false;
		}
	}


}