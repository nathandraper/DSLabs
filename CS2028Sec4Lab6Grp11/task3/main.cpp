#include <iostream>
#include "C:\Users\Nate\source\repos\DSlab6a\DSlab6a\Stack.h"
#include "C:\Users\Nate\source\repos\DSlab6a\DSlab6a\StackOverflow.h"
#include "C:\Users\Nate\source\repos\DSlab6a\DSlab6a\StackUnderflow.h"

using namespace std;

const int NUM_TOWERS = 5;

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

int getSourceTower(int numDiscs, Stack<int> towers[]) {
	int num;

	cout << "Select tower to move from: ";
	cin >> num;

	while (true) {
		if (cin.fail() || num < 1 || num > NUM_TOWERS) {
			cout << "Enter a valid integer from 1 to " << NUM_TOWERS << ": ";
		}
		else if (towers[num].isEmpty()) {
			cout << "That tower is empty. Choose another: ";
		}
		else if (isMoveable(num, numDiscs, towers)) {
			cout << "There are no valid moves for that tower. Choose another. ";
		}
		else {
			return num;
		}
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
		else if (towers[num].isFull()) {
			cout << "That tower is full. Choose another: ";
		}
		else if (!towers[num].isEmpty() && *towers[num].top() % numDiscs <= *towers[source].top() % numDiscs) {
			cout << "You can only move a disc onto a larger or equally sized disc.";
		}
		else {
			return num;
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
		if (!towers[i].isEmpty() && towers[i].isComplete(1, numDiscs, numDiscs) && *towers[i].top() < numDiscs) {
			p1 = true;
		}
	}

	for (int i = NUM_TOWERS / 2 + 1; i < NUM_TOWERS; i++) {
		if (!towers[i].isEmpty() && towers[i].isComplete(numDiscs + 1, numDiscs * 2, numDiscs) && *towers[i].top() > numDiscs) {
			p2 = true;
		}
	}

	return p1 && p2;
}

// friend of Stack
// prints the contents of the tower to the screen
void displayTower(Stack<int> tower) {
	for (int i = 0; i < tower.length(); i++) {
		cout << *tower.stack[i] << "_";
	}
	cout << endl;
}


// prints all towers in an array of towers
void printTowers(Stack<int> towers[]) {
	for (int i = 0; i < NUM_TOWERS; i++) {
		cout << "Tower " << i + 1 << endl;
		displayTower(towers[i]);
	}
}

// initializes the two starting towers on opposite sides with discs.
// player 1's discs are numbered 1 to numDiscs, player 2's discs are numbered numbered from numDiscs + 1 to numDiscs*2
void initGame(Stack<int> towers[], int numDiscs) {
	for (int i = numDiscs; i > 0; i--) {
		towers[0].push(new int(i));
	}

	for (int i = numDiscs*2; i > numDiscs; i--) {
		towers[numDiscs - 1].push(new int(i));
	}
}

void resetTowers(Stack<int> towers[]) {
	for (int i = 0; i < NUM_TOWERS; i++) {
		towers[i].empty();
	}
}

int main() {
	unsigned int numDiscs;
	unsigned int player;
	unsigned int choice1;
	unsigned int choice2;
	bool comparison;
	bool run = true;
	bool choose;

	// prompt user for number of discs to play with
	cout << "Enter number of discs: ";
	numDiscs = getInt();

	// create five empty towers
	Stack<int> towers[NUM_TOWERS];
	for (int i = 0; i < NUM_TOWERS; i++) {
		towers[i] = Stack<int>(numDiscs * 2);
	}

	cout << "Let the game begin." << endl;
	player = 1;
	while (run) {
		// initialize towers
		initGame(towers, numDiscs);

		// switch turns
		player = !player;

		// display game info
		cout << "Player " << player + 1 << "'s turn." << endl;
		cout << "Tower status:" << endl;
		printTowers(towers);

		cout << "Select tower to move from";
		choice1 = getSourceTower(numDiscs, towers) - 1;

		cout << "Select tower to move to: ";
		choice2 = getDestTower(choice1, numDiscs, towers) - 1;
			
		// pop a pointer from the source tower and push to dest tower
		towers[choice2].push(towers[choice1].pop());

		run = checkWin(numDiscs, towers);
	}


}