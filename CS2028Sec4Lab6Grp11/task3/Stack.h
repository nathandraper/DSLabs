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
	Stack() {
		this->stack = nullptr;
		this->size = 0;
		this->i = -1;
	}

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
		for (int i = 0; i <= this->i; i++) {
			delete stack[i];
			stack[i] = nullptr;
		}
		this->i = -1;
	}

	bool isFull() {
		return this->i == this->size - 1;
	}

	bool isEmpty() {
		return this->i == -1;
	}

	friend bool isComplete(int start, int end, Stack<int>tower);
	friend void displayTower(int numDiscs, Stack<int> tower);
	friend void displayTower(Stack<int> &tower);
};

#endif

