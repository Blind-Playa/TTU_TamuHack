class Node {
	Node() {
		next = 0;
	}
	Node(int el, Node *ptr = 0){
		info = el; next = ptr;
	}
	int info;
	Node *next;
};

class List {
public:
	List() {
		head = tail = 0;
	}
	int isEmpty() {
		return head = 0;
	}
	void addToHead(int);
	bool isInList(int);
	void printAll();
	Node *head, *tail;

};

class Stack {
	Node *top;
public:
	Stack();
	void push(int);
	int pop();
	boolisEmpty();
	void display();
};

class Graph {
private:
	int n;
	int **A;
public:
	Graph(int size = 2);
	~Graph();
	bool isConnected(int, int);
	void addEdge(int x, int y);
	void DFS(int, int);
};