#ifndef QUEUE_H
#define QUEUE_H

#include <vector>

template <typename T>
class Queue
{
private:
	vector<T> queue;
	int length;

public:
	int getLength() {
		return this->length
	}

	void enqueue(T data) {
		this->queue.insert(this->queue.begin(), data);
		this->length++;
	}

	T dequeue() {
		T data = this->queue.back();
		this->queue.pop_back();
		
		return data;
	}

	void clear() {
		this->dequeue.clear();
	}

	friend displayTower(Queue<int> tower);
	friend isComplete(int numDiscs, Queue<int> tower);
};

#endif

