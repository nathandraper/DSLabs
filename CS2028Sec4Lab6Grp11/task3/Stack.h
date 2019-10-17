#ifndef STACK_H
#define STACK_H

#include "StackOverflow.h"
#include "StackUnderflow.h"

template <typename T>
class Stack
{
private:
	int size;
	int i;
	T** stack;

public:
	Stack(int size) {
		this->stack = new T * [size];
		this->size = size;
		this->i = -1;
	}
	
	void push(T* disc) {
		if (i >= this->size - 1){
			throw StackOverflow();
		}
		else {
			this->i++;
			this->stack[i] = disc;
		}
	}

	T* pop() {
		if (i < 0) {
			throw StackUnderflow();
		}
		else {
			this->i--;
			return this->stack[i + 1];
		}
	}

	T* top() {
		if (i < 0) {
			throw StackUnderflow();
		}
		else {
			return this->stack[i];

		}
	}

	int length() {
		return this->i + 1;
	}

	void empty() {
		for (int i = 0; i < this->size; i++) {
			delete stack[i];
		}
		this->i = -1;
	}

	void fill() {
		for (int i = 0; i < this->size; i++) {
			stack[i] = new int(this->size - i);
		}
		this->i = this->size - 1;
	}

	bool isFull() {
		return this->i == this->size - 1;
	}

	friend void displayTower(Stack<int> tower);
};

#endif

