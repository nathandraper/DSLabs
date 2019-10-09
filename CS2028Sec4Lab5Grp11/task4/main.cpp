#include <iostream>
#include "EntertainmentShelf.h"
#include "VideoGame.h"

using namespace std;

int getInt() {
	int a;
	cin >> a;
	return a;
}

int main() {
	int choice;
	int run = 1;
	EntertainmentShelf<VideoGame> shelf;

	while (run == 1) {
		cout << "Press 1 to add a video game to the shelf." << endl;
		cout << "Press 2 to remove a video game from the shelf." << endl;
		cout << "Press 3 to see how many vidoe games are on the shelf." << endl;
		cout << "Press 4 to quit." << endl;

		choice = getInt();

		switch (choice) {
		case 1:
			try {
				VideoGame* gPtr = new VideoGame;
				shelf.addGame(gPtr);
			}
			catch (exception& e) {
				cout << "Exception: " << e.what() << endl;
			}
			break;
		case 2:
			try {
				VideoGame* gPtr = shelf.removeGame();
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