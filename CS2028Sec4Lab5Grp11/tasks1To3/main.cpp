#include <iostream>
#include "GameShelf.h"

using namespace std;

int getInt() {
	int a;
	cin >> a;
	return a;
}

int main() {
	int choice;
	int run = 1;
	GameShelf shelf;

	while (run == 1) {
		cout << "Press 1 to add a board game to the shelf." << endl;
		cout << "Press 2 to remove a board game from the shelf." << endl;
		cout << "Press 3 to see how many board games are on the shelf." << endl;
		cout << "Press 4 to quit." << endl;

		choice = getInt();

		switch (choice) {
		case 1:
			try {
				BoardGame* gPtr = new BoardGame;
				shelf.addGame(gPtr);
			}
			catch (exception& e) {
				cout << "Exception: " << e.what() << endl;
			}
			break;
		case 2:
			try {
				BoardGame* gPtr = shelf.removeGame();
				delete gPtr;
			}
			catch (exception& e) {
				cout << "Exception: " << e.what() << endl;
			}
			break;
		case 3:
			cout << "There are " << shelf.getSize() << " board games on the shelf." << endl;
			break;

		case 4:
			return 0;
		}

		cout << "Continue? 0 for no, 1 for yes." << endl;
		run = getInt();
	}

	return 0;
}