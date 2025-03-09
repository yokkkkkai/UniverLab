#pragma once

class PriorityQueue {
private:
	const int MAX_SIZE = 16;
	int current_size;
	int* ptr;

	int findPosition(int value);
public:
	PriorityQueue();
	~PriorityQueue();
	PriorityQueue(const PriorityQueue& other);
	PriorityQueue& operator=(const PriorityQueue& other);

	void push(int value);
	int front() const;
	int getSize() const;
	void print() const;
	void setSize(int new_size);
	int* getRandom(int x) const;
	void fillRandom(int x, int min, int max);
};