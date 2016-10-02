#include <iostream>
#include "Queues.h"

using namespace std;
int main() {
	Queue q;
	int x;

	q.Enqueue(5);		q.Print();
	q.Enqueue(1);		q.Print();
	q.Enqueue(10);		q.Print();

	x = q.Dequeue();
	cout << x << "	";	q.Print();

	PQueue p;
	p.Enqueue(10, 2);	p.Print();
	p.Enqueue(9, 3);	p.Print();
	p.Enqueue(1, 5);	p.Print();
	p.Enqueue(4, 6);	p.Print();

	x = p.Dequeue();
	cout << x << "	";	p.Print();

	system("pause");
}

void Queue::Print(){
	int count = (rear + MAX_SIZE - front) % MAX_SIZE + 1;
	cout << "Queue		: ";
	for (int i = 0; i < count; i++)
	{
		int index = (front + i) % MAX_SIZE;
		cout << A[index] << " ";
	}
	cout << "\n\n";
}

void Queue::Enqueue(int d) {
	cout << "Enqueuing " << d << " \n";
	if (IsEmpty()) {
		front = rear = 0;
	}
	else {
		rear = (rear + 1) % MAX_SIZE;
	}
	A[rear] = d;
}

int Queue::Dequeue() {
	cout << "Dequeuing \n";

	int x;
	if (IsEmpty()) {
		cout << "Error: Queue is Empty\n";
		return 0;
	}
	else if (front == rear) {
		x = A[front];
		rear = front = -1;
		
	}
	else {
		x = A[front];
		front = (front + 1) % MAX_SIZE;
	}
	return x;
}

void PQueue::Enqueue(int d, int p)
{
	cout << "Enqueuing " << d << " with the priority of " << p << " \n"; 
	if (IsEmpty())
		front = rear = 0;
	else {
		rear = (rear + 2) % MAX_SIZE;
	}
	priority = rear + 1;
	A[rear] = d;
	A[priority] = p;
}

int PQueue::Dequeue()
{
	int x = NULL;
	if (IsEmpty()) {
		cout << "Error: Queue is Empty\n";
		return 0;
	}
	int p = 0;
	int i = 1;
	int j = 0;
	for (; i < MAX_SIZE; i= i+2) {
		if (A[i] >= p) {
			p = A[i];
			j = i-1;
		}
	}
	i = A[j];
	A[j] = 0;
	A[j + 1] = 0;

	return i,p;
}

void PQueue::Print()
{

	for (int i = 0; i <= MAX_SIZE; i++)
	{
		if (A[i] > 0)
			cout << A[i] << " ";
	}
	cout << "\n\n";
}
