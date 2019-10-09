#pragma once
#include "BoardGame.h"
#include "FullShelf.h"
#include "EmptyShelf.h"
#define shelfsize 10

class GameShelf
{
private:
	int size;
	BoardGame* shelf[shelfsize];
public:
	int getSize() {
		return size;
	}
	void addGame(BoardGame* g) {
		if (size >= shelfsize) {
			throw FullShelf();
		}

		shelf[size] = g;
		size++;
	}
	BoardGame* removeGame() {
		if (size <= 0) {
			throw EmptyShelf();
		}

		BoardGame* temp = shelf[size - 1];
		shelf[size - 1] = nullptr;
		size--;
		return temp;
	}
	GameShelf() {
		size = 0;
	}
	~GameShelf() {}
};


