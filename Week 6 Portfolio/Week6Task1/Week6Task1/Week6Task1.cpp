#include "stdafx.h"
#include <iostream>
#include <stack>

using namespace std;

//The class below is the definition of the tree nodes
class BinTreeNode {
public:
	BinTreeNode(int value) {
		this->value = value;
		this->left = NULL;
		this->right = NULL;
		this->parent = NULL;
		this->visited = false;
	}
	int value;
	BinTreeNode* left;
	BinTreeNode* right;
	BinTreeNode* parent;
	bool visited;

};

class StackNodes
{

public:
	BinTreeNode* node;
	StackNodes* next;

	StackNodes() {
		std::cout << "List Constructor!" << std::endl;
		this->node = 0;
		this->next = 0;
	}
	~StackNodes() {
		std::cout << "List destructor!" << std::endl;
		std::cout << "Todo: properly delete nodes..." << std::endl;
	}

	void push(StackNodes **top_ref, BinTreeNode *node) {
		StackNodes* new_Node = new StackNodes;
		if (new_Node == NULL) {
			cout << "stack empty" << endl;
		}

		new_Node->node = node;
		new_Node->next = *top_ref;
		*top_ref = new_Node;
	}

	bool isEmpty(StackNodes *top) {
		return (top == NULL) ? 1 : 0;
	}

	BinTreeNode *pop(StackNodes **top_ref) {
		BinTreeNode *res;
		StackNodes *top;

		if (isEmpty(*top_ref))
			cout << "Stack Empty" << endl;
		else {
			top = *top_ref;
			res = top->node;
			*top_ref = top->next;
			return res;
		}
	}

	void in_orderGFG(BinTreeNode *root) {
		BinTreeNode *current = root;
		StackNodes *s = NULL;
		bool done = false;

		while (!done) {
			//Reach left-most node
			if (current != NULL) {
				//pointer to a tree node in the stack, before traversing
				push(&s, current);
				current = current->left;
			}
			//backtrack to the top. If stack is empty, it's done
			else {
				if (!isEmpty(s)) {
					current = pop(&s);
					cout << "%d" << current->value << endl;
					current = current->right;
				}
				else
					done = 1;
			}
		}
	}
};

BinTreeNode* tree_insert(BinTreeNode* tree, int item) {
	if (tree == NULL)
		tree = new BinTreeNode(item);
	else
		if (item < tree->value)
			if (tree->left == NULL) {
				tree->left = new BinTreeNode(item);
				tree->left->parent = tree;
			}
			else {
				tree_insert(tree->left, item);
			}
		else
			if (tree->right == NULL) {
				tree->right = new BinTreeNode(item);
				tree->right->parent = tree;
			}
			else
				tree_insert(tree->right, item);
	return tree;
}

void postorder(BinTreeNode* tree) {
	if (tree->left != NULL)
		postorder(tree->left);
	if (tree->right != NULL)
		postorder(tree->right);
	std::cout << tree->value << std::endl;

}

void in_order(BinTreeNode* tree) {
	if (tree->left != NULL)
		in_order(tree->left);
	std::cout << tree->value << std::endl;
	if (tree->right != NULL)
		in_order(tree->right);
}

//in_order function iteratively 
void in_orderITER(BinTreeNode *node) {
	//use of stack so i can iterate
	stack<BinTreeNode*> iteratorSt;
	iteratorSt.push(node);
	while (!iteratorSt.empty()) {
		BinTreeNode *top = iteratorSt.top();
		if (top != NULL) {
			if (!top->visited)
				iteratorSt.push(top->left);
			else {
				cout << top->value << " ";
				iteratorSt.pop();
				iteratorSt.push(top->right);
			}
		}
		else {
			iteratorSt.pop();
			if (!iteratorSt.empty())
				iteratorSt.top()->visited = true;
		}
	}
}



//SEARCH FUNCTION - Talking about this one specifically, i haven't touched anything else in the code
int BST(BinTreeNode* tree, int target) {
	BinTreeNode* r = tree;
	while (r != NULL) {
		if (r->value == target) {
			return r->value;
		}
		else if (r->value > target) {
			return BST(tree->left, target);
		}
		else {
			return BST(tree->right, target);
		}

		return 0;
	}

}

int main(int argc, char *argv[])
{
	BinTreeNode* t = tree_insert(0, 6);
	tree_insert(t, 10);
	tree_insert(t, 5);
	tree_insert(t, 2);
	tree_insert(t, 3);
	tree_insert(t, 4);
	tree_insert(t, 11);
	cout << "Post order, elements are: ";
	postorder(t);
	cout << "In order, elements are: ";
	in_order(t);
	cout << "In order iterative, elements are: ";
	in_orderITER(t);
	system("pause");

	return 0;
}