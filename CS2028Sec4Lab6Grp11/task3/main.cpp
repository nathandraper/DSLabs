#include <iostream>
#include <limits>

#include "Stack.h"
#include "StackOverflow.h"
#include "StackUnderflow.h"

using namespace std;

const int NUM_TOWERS = 5;

// function declarations
int getInt();
char getChar();
int getSourceTower(int numDiscs, Stack<int> towers[]);
int getDestTower(int source, int numDiscs, Stack<int> towers[]);
int isMoveable(int num, int numDiscs, Stack<int> towers[]);
bool checkWin(int numDiscs, Stack<int> towers[]);
bool isComplete(int start, int end, Stack<int> tower);
void displayTower(int numDiscs, Stack<int> tower);
void printTowers(int numDiscs, Stack<int> towers[]);
void initGame(Stack<int> towers[], int numDiscs);
void resetTowers(Stack<int> towers[]);


int main() {
	// variables
	unsigned int numDiscs;
	unsigned int player;
	unsigned int source;
	unsigned int dest;
	bool run = true;
	bool runGame = true;

	// create five empty towers
	Stack<int> towers[NUM_TOWERS];

	while (run) {
		// prompt user for number of discs to play with
		cout << "Enter number of discs: ";
		numDiscs = getInt();

		// initialize towers
		for (int i = 0; i < NUM_TOWERS; i++) {
			towers[i] = Stack<int>(numDiscs * 2);
		}
		initGame(towers, numDiscs);

		// game loop;
		cout << "Let the game begin." << endl << endl;
		player = 1;
		while (runGame) {
			// switch turns
			player = !player;

			// display game info
			cout << "Player " << player + 1 << "'s turn." << endl << endl;
			cout << "Tower status:" << endl << endl;
			printTowers(numDiscs, towers);

			// get destination and source towers for move
			source = getSourceTower(numDiscs, towers);
			dest = getDestTower(source, numDiscs, towers);

			// pop a pointer from the source tower and push to dest tower
			towers[dest].push(towers[source].pop());

			// end loop if game is over
			runGame = !checkWin(numDiscs, towers);
		}
		printTowers(numDiscs, towers);
		cout << "The towers are complete! The game has ended." << endl;
		cout << "play again? y/n ";
		run = getChar() == 'y';
		runGame = true;

		resetTowers(towers);
	}

	return 0;
}

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

char getChar() {
	char chr;

	cin >> chr;

	// Validation
	while (cin.fail()) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Enter a valid integer > 1: ";
		cin >> chr;
	}

	return chr;
}

int getSourceTower(int numDiscs, Stack<int> towers[]) {
	int num;

	cout << "Select tower to move from: ";
	cin >> num;

	while (true) {
		if (cin.fail() || num < 1 || num > NUM_TOWERS) {
			cout << "Enter a valid integer from 1 to " << NUM_TOWERS << ": ";
		}
		else if (towers[num - 1].isEmpty()) {
			cout << "That tower is empty. Choose another: ";
		}
		else if (!isMoveable(num - 1, numDiscs, towers)) {
			cout << "There are no valid moves for that tower. Choose another. ";
		}
		else {
			return num - 1;
		}
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin >> num;
	}

}

int getDestTower(int source, int numDiscs, Stack<int> towers[]) {
	int num;

	cout << "Select tower to move to: ";
	cin >> num;

	while (true) {
		if (cin.fail() || num < 1 || num > NUM_TOWERS) {
			cout << "Enter a valid integer from 1 to " << NUM_TOWERS << ": ";
		}
		else if (towers[num - 1].isFull()) {
			cout << "That tower is full. Choose another: ";
		}
		else if (!towers[num - 1].isEmpty() && (*towers[num - 1].top() - 1) % numDiscs < (*towers[source].top() - 1) % numDiscs) {
			cout << "You can only move a disc onto a larger or equally sized disc.";
		}
		else {
			return num - 1;
		}
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin >> num;
	}

}

int isMoveable(int num, int numDiscs, Stack<int> towers[]) {
	for (int i = 0; i < NUM_TOWERS; i++) {
		if (i == num) {
			continue;
		}
		else if (towers[i].isEmpty()) {
			return true;
		}
		else if (*towers[i].top() % numDiscs <= *towers[num].top() % numDiscs) {
			return true;
		}
	}
	return false;
}

bool checkWin(int numDiscs, Stack<int> towers[]) {
	bool p1 = false;
	bool p2 = false;

	for (int i = 0; i < NUM_TOWERS / 2; i++) {
		if (!towers[i].isEmpty() && isComplete(numDiscs * 2, numDiscs + 1, towers[i]) && *towers[i].top() > numDiscs) {
			p1 = true;
			break;
		}
	}

	for (int i = NUM_TOWERS / 2 + 1; i < NUM_TOWERS; i++) {
		if (!towers[i].isEmpty() && isComplete(numDiscs,  1, towers[i]) && *towers[i].top() < numDiscs) {
			p2 = true;
			break;
		}
	}

	return p1 && p2;
}

// friend of Stack
// this function will test if the tower is stacked in high to low order from a given start value to a given end value
// ex. start = 3, end = 1 will return true if and only if the tower's stack is {3, 2, 1}
// ex. start = 6, end = 3 will return true if and only if the tower's stack is {6, 5, 4, 3}
bool isComplete(int start, int end, Stack<int> tower) {
	int num = start - end + 1;
	if (tower.i + 1 != num) {
		return false;
	}
	for (int i = start; i >= end; i--) {
		if (i != *tower.stack[num - ((i - 1) % num) - 1]) {
			return false;
		}
	}
	return true;
}

// friend of Stack
// prints the contents of the tower to the screen
void displayTower(int numDiscs, Stack<int> tower) {
	int player;
	int val;
	for (int i = 0; i < tower.length(); i++) {
		val = *tower.stack[i];
		if (val <= numDiscs) {
			player = 1;
		}
		else {
			player = 2;
		}
		cout << ((val - 1) % numDiscs) + 1 << "(P" << player << ") _ ";
	}
	cout << endl << endl;
}

// prints all towers in an array of towers
void printTowers(int numDiscs, Stack<int> towers[]) {
	for (int i = 0; i < NUM_TOWERS; i++) {
		cout << "Tower " << i + 1 << endl;
		displayTower(numDiscs, towers[i]);
	}
}

// initializes the two starting towers on opposite sides with discs.
// player 1's discs are numbered 1 to numDiscs, player 2's discs are numbered numbered from numDiscs + 1 to numDiscs*2
void initGame(Stack<int> towers[], int numDiscs) {
	for (int i = numDiscs; i > 0; i--) {
		towers[0].push(new int(i));
	}

	for (int i = numDiscs * 2; i > numDiscs; i--) {
		towers[NUM_TOWERS - 1].push(new int(i));
	}
}

void resetTowers(Stack<int> towers[]) {
	for (int i = 0; i < NUM_TOWERS; i++) {
		towers[i].empty();
	}
}