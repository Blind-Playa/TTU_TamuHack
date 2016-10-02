#include <iostream>
#include "BStree.h"

using namespace std;

void BST::insert(int el) {
	Node *tmp = root, *prev = 0;
	while (tmp != 0) {
		prev = tmp;
		if (el < tmp->info)
			tmp = tmp->left;
		else
			tmp = tmp->right;
	}
	if (root == 0) 
		root = new Node(el);
	
	else if (el < prev->info)
		prev->left = new Node(el);

	else
		prev->right = new Node(el);
}

void PreOrder(Node *r) {
	if (r) {
		cout << r->info << " ";
		PreOrder(r->left);
		PreOrder(r->right);
	}
}

void InOrder(Node *r) {
	if (r) {
		InOrder(r->left);
		cout << r->info << " ";
		InOrder(r->right);
	}
}

void PostOrder(Node *r) {
	if (r) {
		PostOrder(r->left);
		PostOrder(r->right);
		cout << r->info << " ";
	}
}

void BST::print(Node *node) {
	if (node == 0)
		return;
	print(node->left);
	print(node->right);
	cout << node->info << " ";
}

int BST::countL(Node *root)
{
	if (root == NULL)
		return 0;
	return 1 + countL(root->left) + countL(root->right);
}

int BST :: countRightL(Node *root, int d)
{
	if (root == NULL)	//This leaf has no children
		return 0;
	return d + countRightL(root->left, 0) +   countRightL(root->right, 1);
}

int PerfectBalance(Node *root, int d)
{
	if (root == NULL) {
		return 0;
	}
	return d + PerfectBalance(root->left, -1) + PerfectBalance(root->right, 1);
}

int BST::TestBST(Node* p) {
	if (p == NULL) {
		return(true);
	}
	else if (p->left != NULL && p->left->info > p->info) {
		return false;
	}
	else if (p->right != NULL && p->right->info < p->info) {
		return false;
	}
	else if (!TestBST(p->left) || !TestBST(p->right)) {
		return false;
	}
	else {
		return true;
	}
}

int main() {
	BST *T = new BST();

	//T->insert(2);
	//T->insert(1);
	//T->insert(3);

	//T->insert(15);
	//T->insert(9);
	//T->insert(8);
	//T->insert(30);
	//T->insert(20);
	//T->insert(1);
	//T->insert(18);
	//T->insert(13);
	//T->print(T->root);
	
	T->insert(30);
	T->insert(10);
	T->insert(20);
	T->insert(40);
	T->insert(50);
	//T->print(T->root);

	cout << endl;
	/*
	cout << "The number of leaves is: " << T->countL(T->root) << endl;

	cout << "The number of right leaves is: " << T->countRightL(T->root, 0) << endl;

	int x = PerfectBalance(T->root, 0);

	if (x == 0)
		cout << "This tree is perfectly balanced" << endl;
	
	else if (x != 0) 
		cout << "This tree is not perfectly balanced" << endl;


	if (T->TestBST(T->root))
		cout << "This is a Binary Search Tree" << endl;

	else
		cout << "This is not a Binary Search Tree" << endl;
	*/

	cout << "Pre-Order: " << endl;

	PreOrder(T->root);

	cout << endl;

	cout << "In-Order: " << endl;

	InOrder(T->root);

	cout << endl;

	cout << "Post-Order: " << endl;

	PostOrder(T->root);

	cout << endl;

	system("pause");

	return 0;
}

