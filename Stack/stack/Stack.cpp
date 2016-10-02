#include <iostream>
#include <stack>
#include "Stack.h"

using namespace std;

void charSLLStack::Push(char d) {
	charSLLNode *tmp = new charSLLNode(d);
	tmp->next = head;
	head = tmp;
}

void charSLLStack::print() {
	cout << "Stack : ";
	if (isEmpty()) {
		cout << "EMPTY" << endl;
	}
	else {
		charSLLNode *tmp = head;
		while (tmp != NULL) {
			cout << tmp->info << " ";
			tmp = tmp->next;
		}
		cout << "Head is " << head->info;
		cout << endl;
	}
}

char charSLLStack::pop() {
	if (head == NULL) {
		return NULL;
	}
	else {
		char el = head->info;
		head = head->next;
		return el;
	}
}

bool charSLLStack::isEmpty() {
	return(head != NULL) ? false : true;
}

void charSLLStack::TransferStack(charSLLStack *n2) {

	charSLLNode *tmp = head;
	charSLLStack tmp_stack;
	char s;

	while (tmp != NULL)
	{
		s = tmp->info;
		tmp_stack.Push(s);
		tmp = tmp->next;
	
	}
	cout << "Temp";
	tmp_stack.print();
	tmp = tmp_stack.head;

	while (tmp != NULL) {
		s = tmp->info;
		n2->Push(s);
		tmp = tmp->next;
	}
	return;
}

bool charSLLStack::delimiterMatching(char* file) {
	cout << "working" << endl;
	int counter = 0;
	char ch, popd;
	do {
		ch = file[counter];
		if (ch == ';')
			break;
		if (ch == '(' || ch == '[' || ch == '{')
			Push(ch);
		if (ch == ')' || ch == ']' || ch == '}') {
			 popd = pop();
			 if ((ch == ')' && popd != '(') || (ch == ']' && popd!= '[') || (ch == '}' && popd != '{'))
				 return false;
		}
		counter++;
	} while (ch != '\n');

	if (isEmpty())
		return true;
	else return false;
}

int main() {
	charSLLStack n;

	charSLLStack n2;

	char filename[50];

	cout << "Enter a statement (Ex. s=t[5]+u/(v*w+y));	   : ";
	cin >> filename;
	cout << endl;

	if (n.delimiterMatching(filename))
		cout << endl << "Your statement was constructed successfully." << endl;
	else cout << endl << "Your statement is incorrectly constructed." << endl;

	n.Push('c');
	n.Push('a');
	n.Push('m');
	n.Push('e');
	n.Push('r');
	n.Push('o');
	n.Push('n');

	n.print();

	n.TransferStack(&n2);

	n2.print();

	system("pause");

	return 0;
}
