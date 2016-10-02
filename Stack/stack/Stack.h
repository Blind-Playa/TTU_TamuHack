class charSLLNode {
public:
	charSLLNode() {
		next = 0;
	}
	charSLLNode(char d, charSLLNode *ptr = 0) {
		info = d; 
		next = ptr;
	}
	char info;
	charSLLNode *next;
};

class charSLLStack {
public:
	charSLLStack() {
		head = 0;
	}
	//~charSLLStack();
	void print();
	void Push(char d);
	char pop();
	bool isEmpty();
	void TransferStack(charSLLStack *);
	bool delimiterMatching(char *);

private:
	charSLLNode *head;
};
