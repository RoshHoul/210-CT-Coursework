// Week7Task1.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <queue>

/*PSEUDOCODE: 
	new NODE{ value, visited, list of edges }
	new GRAPH {list of nodes}

	CONNECT_NODES(Node a, Node b) 
		add a to b.edges
		add b to a.edges

	ADD_EDGE(Node a)
		add a to graph
*/

//I know using namespace std is a bad practice, but for a project with the size of lab task is just more convinient
using namespace std;

class Node {
public:
	Node(int value) {
		this->value = value;
		this->visited = false;
	}

	int value;
	vector<Node*> edges;
	bool visited;

	void addEdgeToNode(Node *v) {
		edges.push_back(v);
	}

	void printNodAndEd() {
		cout << "The Node " << value << " is connected to :" << endl;
		for (std::vector<Node*>::iterator it = edges.begin(); it != edges.end(); it++) {
			cout << (*it)->value << ", ";
		}
		cout << endl;
	}



	~Node() {}
};

class Graph {

public:
	Graph() {

	}

	vector<Node*> headNode;

	void insertNode(Node *node) {
		headNode.push_back(node);

	}

	void connectNodes(Node *source, Node *dest) {
		source->addEdgeToNode(dest);
		dest->addEdgeToNode(source);
	}

	void printGraph() {
		for (std::vector<Node*>::iterator it = headNode.begin(); it != headNode.end(); it++) {
			(*it)->printNodAndEd();
		}
	}

};


int main() {

	//Creating pointers to the nodes
	Node *s = new Node(0);
	Node *a = new Node(3);
	Node *b = new Node(7);
	Node *c = new Node(5);
	Node *d = new Node(2);
	Node *e = new Node(6);
	Node *f = new Node(1);
	Node *h = new Node(4);

	//Creating pointer to the graph
	Graph *g = new Graph();

	//Adding nodes
	g->insertNode(s);
	g->insertNode(a);
	g->insertNode(b);
	g->insertNode(c);
	g->insertNode(d);
	g->insertNode(e);
	g->insertNode(f);
	g->insertNode(h);

	//Connecting nodes
	g->connectNodes(s, a);
	g->connectNodes(a, b);
	g->connectNodes(b, c);
	g->connectNodes(c, d);

	g->connectNodes(d, e);
	g->connectNodes(e, f);
	g->connectNodes(d, h);


	//OUTPUTS:
	g->printGraph();


	//Freeing memory from the graph to prevent memory leaks
	delete g;
	system("pause");
	return 0;
}