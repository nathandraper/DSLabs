#include <iostream>
#include <limits>
#include "Stack.h"
#include "StackOverflow.h"
#include "StackUnderflow.h"

using namespace std;

const int NUM_TOWERS = 3;

// function declarations
int getInt();
int getTower();
void fill(int numDiscs, Stack<int> &tower);
void displayTower(Stack<int> &tower);
void printTowers(Stack<int> towers[]);

int main() {
	// variables
	int source;
	int dest;
	bool comparison;

	// prompt user for number of discs to play with
	cout << "Enter number of discs: ";
	int numDiscs = getInt();

	// create five empty towers
	Stack<int> towers[NUM_TOWERS] = { Stack<int>(numDiscs), Stack<int>(numDiscs), Stack<int>(numDiscs) };

	// fill first and last tower with discs
	fill(numDiscs, towers[0]);

	// game loop
	cout << "Let the game begin." << endl;
	bool run = true;
	bool choose;
	while (run) {

		cout << "Tower status:" << endl << endl;
		printTowers(towers);

		//  prompt user for towers to move from and to until a valid choice is selected
		choose = true;
		while (choose) {
			cout << "Select tower to move from: ";
			source = getTower() - 1;

			cout << "Select tower to move to: ";
			dest = getTower() - 1;
			cout << endl;

			// ensure that the destination tower has a disc greater than the source tower
			// in the case that the receiving tower is empty, the game should allow it as a valid destination
			// if the source tower is empty the next try/catch will catch it
			try {
				comparison = *towers[source].top() < *towers[dest].top();
			}
			catch (StackUnderflow e) {
				comparison = true;
			}

			if (comparison) {
				try {
					towers[dest].push(towers[source].pop());
				}
				catch (StackOverflow e) {
					cout << "That tower is full." << endl;
					cout << e.what() << endl;
					choose = true;
					continue;
				}
				catch (StackUnderflow e) {
					cout << "That tower is empty." << endl;
					cout << e.what() << endl;
					choose = true;
					continue;
				}
				choose = false;
			}
			else {
				cout << "You can only move a smaller disc onto a bigger disc." << endl;
				choose = true;
			}
		}

		// if the tower is full, the game is complete
		// the game will not allow discs to be stacked out of order, so as long as the target tower is full it's game over
		if (towers[2].isFull()) {
			printTowers(towers);
			cout << "The tower is complete! Thank you for playing." << endl;
			run = false;
		}
	}

	// release memory
	for (int i = 0; i < NUM_TOWERS; i++) {
		towers[i].empty();
	}

}


// this function prompts the user for an integer, validates that the input stream has no errors, and then returns the integer
// the integer must be > 1
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

// prompts the user for an integer between 0 and NUM_TOWERS
int getTower() {
	int num;

	cin >> num;

	// Validation
	while (cin.fail() || num <= 0 || num > NUM_TOWERS) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Enter an integer from 1 to 3: ";
		cin >> num;
	}

	return num;
}

// pushes numDiscs discs onto tower stack
void fill(int numDiscs, Stack<int> &tower) {
	for (int i = 0; i < numDiscs; i++) {
		tower.push(new int(numDiscs - i));
	}
}

// friend of Stack class
// prints the contents of the tower stack onto the screen
void displayTower(Stack<int> &tower) {
	for (int i = 0; i < tower.length(); i++) {
		cout << *tower.stack[i] << "_";
	}
	cout << endl << endl;
}

// calls displayTower on every tower in towers
void printTowers(Stack<int> towers[]) {
	for (int i = 0; i < NUM_TOWERS; i++) {
		cout << "Tower " << i + 1 << endl;
		displayTower(towers[i]);
	}
}