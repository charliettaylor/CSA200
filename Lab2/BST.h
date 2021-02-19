#ifndef BST_H
#define BST_H

#include <string>		
#include <iostream>
#include <stack>

class Node
{
	friend class BST;
public:
	Node() : data(0), rlink(nullptr), llink(nullptr) {}
	~Node(){}
private:
    int data;
    Node *rlink, *llink;
};

class BST
{
public:

	BST();

   	void recursiveInsert(int);
	void recursiveInorder() const;	

	int totalNodes() const;
	bool isEmpty() const;
	
	void emptyTree();
	~BST();   

	// Declaration function nonRecursiveInsert
	void nonRecursiveInsert(int);

	// Declaration function nonRecursiveInorder
	void nonRecursiveInorder() const;		

private:	
	void recursiveInsert(Node* &, int);
    void recursiveInorder(Node*) const;

	void clearTree(Node* &);	

	Node *root; //pointer to the root
	int count;  //number of nodes
};

#endif