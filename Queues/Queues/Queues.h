#define MAX_SIZE 10 

class Queue
{
private:
	int A[MAX_SIZE];
	int front, rear;
public:
	Queue() {
		front = -1;
		rear = -1;
	}
	bool IsEmpty()
	{
		return (front == -1 && rear == -1);
	}
	void Enqueue(int d);
	int Dequeue();
	void Print();

};

class PQueue
{
private:
	int A[MAX_SIZE];
	int front, rear, priority;
public:
	PQueue() {
		front = -1;
		priority = -1;
		rear = -1;
	}
	bool IsEmpty()
	{
		return (front == -1 && rear == -1);
	}
	void Enqueue(int d, int p);
	int Dequeue();
	void Print();

};