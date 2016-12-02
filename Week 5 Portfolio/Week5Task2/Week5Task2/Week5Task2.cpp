// Week5Taks2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

//Nodes and lists use public data members for convenience
//This may make some software engineers froth at the mouth

using namespace std;

class Node
{
public:
	int value; //This could really be any type
	Node* next;
	Node* prev;
	Node(int val) {
		std::cout << "Node constructr!" << std::endl;
		this->value = val;
		this->next = (Node*)0;
		this->prev = (Node*)0;
	}
	~Node() {
		std::cout << "Node destructor" << std::endl;

	}
};
class List
{

public:
	Node* head;
	Node* tail;

	List() {
		std::cout << "List Constructor!" << std::endl;
		this->head = 0;
		this->tail = 0;
	}
	~List() {
		std::cout << "List destructor!" << std::endl;
		std::cout << "Todo: properly delete nodes..." << std::endl;
	}
	void insert(Node* n, Node* x) {
		//Not actually perfect: how do we prepend to an existing list?
		if (n != 0) {
			x->next = n->next;
			n->next = x;
			x->prev = n;
			if (x->next != 0)
				x->next->prev = x;
		}
		if (this->head == 0) {
			this->head = x;
			this->tail = x;
			x->prev = 0;
			x->next = 0;
		}
		else if (this->tail = n) {
			this->tail = x;
		}
	}

	void deleteNode(Node* n) {
		if (n->prev != NULL) {
			n->prev->next = n->next;
		}
		else {
			this->head = n->next;
			this->head->prev = 0;
			
		}
		if (n->next != 0) {
			n->next->prev = n->prev;
		}
		else {
			this->tail = n->prev;
			this->tail->next = 0;
		}

	}

	void display() {
		Node* i = this->head;
		std::cout << "List: ";
		while (i != 0) {
			std::cout << i->value << ",";
			i = i->next;
		}
		std::cout << std::endl;
	}
};

int main(int argc, char *argv[])
{
	List* l = new List();
	Node n1 = Node(7);
	Node n2 = Node(3);
	Node n3 = Node(5);
	Node n4 = Node(12);
	Node n5 = Node(1);
	l->insert(0, &n1);
	l->insert(l->head, &n2);
	l->insert(l->head, &n3);
	l->insert(l->head, &n4);
	l->insert(l->head, &n5);
	l->display();
	l->deleteNode(&n1);
	l->deleteNode(&n3);
	cout << "after delete" << endl;
	l->display();
	delete l;

	system("pause");
	return 0;
}

