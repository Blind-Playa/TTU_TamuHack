class Node {
public:
	Node() {
		left = right = 0;
	}
	Node(int el, Node *l = 0, Node *r = 0) {
		info = el;
		left = l;
		right = r;
	}
	int info;
	Node *left, *right;
};

class BST {
public:
	BST() {
		root = 0;
	}
	void insert(int);
	void print(Node *);
	int countL(Node *);
	int countRightL(Node *, int d);
	int TestBST(Node *);
	Node *root;
};

