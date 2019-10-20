#include <iostream>
#include "Queue.h"
#include "QueueUnderflow.h"
#include "Move.h"
#include "C:\Users\Nate\source\repos\DSlab6a\DSlab6a\Stack.h"
#include "C:\Users\Nate\source\repos\DSlab6a\DSlab6a\StackOverflow.h"
#include "C:\Users\Nate\source\repos\DSlab6a\DSlab6a\StackUnderflow.h"

using namespace std;

const int NUM_TOWERS = 3;

// function declarations
int getInt();
int getTower();
void fill(int numDiscs, Stack<int>& tower);
void displayTower(Stack<int>& tower);
void printTowers(Stack<int> towers[]);
void printMoves(Queue<Move>& moves);

int main() {
	// variables
	int choice1;
	int choice2;
	bool comparison;

	// prompt user for number of discs to play with
	cout << "Enter number of discs: ";
	int numDiscs = getInt();

	// create five empty towers
	Stack<int> towers[NUM_TOWERS] = { Stack<int>(numDiscs), Stack<int>(numDiscs), Stack<int>(numDiscs) };

	// create move queue
	Queue<Move> moves;

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
			choice1 = getTower() - 1;

			cout << "Select tower to move to: ";
			choice2 = getTower() - 1;
			cout << endl;

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

		// store move for this turn
		moves.enqueue(Move{ choice1, choice2 });

		if (towers[2].isFull()) {
			printTowers(towers);
			cout << "The tower is complete! Thank you for playing." << endl;
			cout << "Moves: " << moves.getLength() << endl; 
			printMoves(moves);
			run = false;
		}
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
void fill(int numDiscs, Stack<int>& tower) {
	for (int i = 0; i < numDiscs; i++) {
		tower.push(new int(numDiscs - i));
	}
}

// friend of Stack class
// prints the contents of the tower stack onto the screen
void displayTower(Stack<int>& tower) {
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

void printMoves(Queue<Move>& moves) {
	int len = moves.getLength();
	for (int i = 0; i < len; i++) {
		Move move = moves.dequeue();
		cout << "Move " << i + 1 << ":  Tower " << move.source + 1 << " to tower " << move.dest + 1 << endl;
	}
}
