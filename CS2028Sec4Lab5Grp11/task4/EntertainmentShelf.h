#pragma once
#include "FullShelf.h"
#include "EmptyShelf.h"
#define shelfsize 10

template <class T>
class EntertainmentShelf
{
private:
	int size;
	T* shelf[shelfsize];
public:
	int getSize() {
		return size;
	}
	void addGame(T* g) {
		if (size >= shelfsize) {
			throw FullShelf();
		}

		shelf[size] = g;
		size++;
	}
	T* removeGame() {
		if (size <= 0) {
			throw EmptyShelf();
		}

		T* temp = shelf[size - 1];
		shelf[size - 1] = nullptr;
		size--;
		return temp;
	}

	EntertainmentShelf() {
		size = 0;
	}
	~EntertainmentShelf() {}
};


