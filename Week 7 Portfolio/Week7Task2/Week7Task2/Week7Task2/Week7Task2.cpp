// Week7Task1.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <fstream>

//I know using namespace std is a bad practice, but for a project with the size of lab task is just more convinient
using namespace std;


//Creating class Node, which contains the value, structure (vector) of edges and visited flag
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

	void printNodAndEd(ofstream& myfile) {
		myfile.open("Graph traverses.txt", ios::app);
		myfile << "The Node " << value << " is connected to :" << endl;
		for (std::vector<Node*>::iterator it = edges.begin(); it != edges.end(); it++) {
			myfile << (*it)->value << ", ";
		}
		myfile << endl;
		myfile.close();
	}

	~Node() {}
};

//Creating Graph - a vector of all the nodes inside it
class Graph {

public:
	Graph() {

	}

	vector<Node*> headNode;

	//Adding Node to the graph
	void insertNode(Node *node) {
		headNode.push_back(node);
	}

	//Connecting to nodes
	void connectNodes(Node *source, Node *dest) {
		source->addEdgeToNode(dest);
		dest->addEdgeToNode(source);
	}

	//Printing the graph in txt file
	void printGraph(ofstream& myfile) {
		myfile.open("Graph traverses.txt");
		myfile << "GRAPH DISPLAYED STARTING FROM NODE 3: " << endl;
		myfile << "        3 " << endl;
		myfile << "       / " << (char)92 << endl;
		myfile << "      7   0" << endl;
		myfile << "     /     " << (char)92 << endl;
		myfile << "    5       NULL" << endl;
		myfile << "   /   " << endl;
		myfile << "  2   " << endl;
		myfile << " / | " << (char)92 << endl;
		myfile << "4  6  1" << endl;
		cout << endl;

		for (std::vector<Node*>::iterator it = headNode.begin(); it != headNode.end(); it++) {
			 (*it)->printNodAndEd(myfile);
		}
		myfile.close();
	}

	//Breadth first search, outputing nodes values into txt file
	void BFS(Node *head, ofstream& myfile)
	{
		myfile.open("Graph traverses.txt",ios::app);
		myfile << endl;
		myfile << "BREADTH FIRST TRAVERSAL: " << endl;

		queue<Node*> traverse;
		traverse.push(head);
		
		while (!traverse.empty()) {
			Node* n = traverse.front();
			traverse.pop();
			if (!n->visited)
			{
				myfile << "Node value is: " << n->value << endl;
				cout << "n value is " << n->value << ", " << endl;
				n->visited = true;
				for (auto e : n->edges)
					traverse.push(e);
			}
		}
		cout << endl;
		myfile.close();
	}


	//Depth first search, outputing nodes values into txt file
	void DFS(Node* head, ofstream& myfile) {
		myfile.open("Graph traverses.txt", ios::app);
		myfile << endl;
		myfile << "DEPTH FIRST TRAVERSAL: " << endl;
		stack<Node*> traverse;
		traverse.push(head);

		while (!traverse.empty()) {
			Node* n = traverse.top();
			traverse.pop();
			if (!n->visited) {
				myfile << "Node value is: " << n->value << endl;
				cout << "n value is " << n->value << ", " << endl;
				n->visited = true;
				for (auto e : n->edges) {
					if (!e->visited) {
						traverse.push(e);

					}
				}
			}
		}

		myfile.close();
	}

	//Reseting the visited flag of all the nodes, so we can run both of the searches in the same execution
	void Reset(Node *head)
	{
		queue<Node*> traverse;
		traverse.push(head);

		while (!traverse.empty()) {
			Node* n = traverse.front();
			traverse.pop();
			if (n->visited)
			{
				//				cout << "n value is " << n->value << ", " << endl;
				n->visited = false;
				for (auto e : n->edges)
					traverse.push(e);
			}
		}

	}


};


int main() {
	
	//Creating file
	ofstream myfile;

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
	g->printGraph(myfile);

	cout << "BFS is: " << endl;
	g->BFS(a, myfile);

	g->Reset(a);

	cout << "DFS is: " << endl;
	g->DFS(a, myfile);

	//Freeing memory from the graph to prevent memory leaks
	delete g;
	system("pause");
	return 0;
}

