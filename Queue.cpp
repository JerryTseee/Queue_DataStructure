#include<iostream>
using namespace std;

/*
empty(q): return true if the queue is empty and false otherwise
full(q): return true if the queue is full and false otherwise
enqueue(q,x): insert x to the tail of queue q
dequeue(q): return and then delete the element at the head of the queue q

First-in First-out
*/

struct queue {
	int head = 0;
	int tail = 0;
	int entry[100];
};
queue q;

//O(1)
bool empty(queue& q) {
	if (q.head == q.tail) {
		return true;
	}
	else {
		return false;
	}
};

//O(1)
bool full(queue& q) {
	if (q.head == (q.tail + 1) % 100) {
		return true;
	}
	else {
		return false;
	}
};

//O(1)
void enqueue(queue& q, int x) {
	if (full(q)) {
		cout << "overflow" << endl;
	}
	else {
		q.entry[q.tail] = x;
		q.tail = (q.tail + 1) % 100;//it is a circular loop entry
	}
};

//O(1)
int dequeue(queue& q) {
	if (empty(q)) {
		cout << "underflow" << endl;
		return 0;
	}
	else {
		int temp = q.entry[q.head];
		q.head = (q.head + 1) % 100;//it is a circular loop entry
		return temp;
	}
};

void printQueue(queue& q) {
	int i = q.head;
	while (i != q.tail) {
		cout << q.entry[i] << " ";
		i = (i + 1) % 100;//move to the next index in a circular loop
	}
	cout << endl;
};