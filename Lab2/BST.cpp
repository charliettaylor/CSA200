#include "BST.h"

using namespace std;

	//default constructor
BST::BST() : root(nullptr), count(0) {}

	//recursiveInsert
void BST::recursiveInsert(int elemToInsert)
{
	recursiveInsert(root, elemToInsert);
}

	//recursiveInsert (private)
void BST::recursiveInsert(Node * &ptr, int elemToInsert)
{
	if (ptr == nullptr)
	{	
		Node* newNode = new Node;
		newNode->data = elemToInsert;
		ptr = newNode;
		++count;
	}
	else if (ptr->data == elemToInsert)
		cerr << "Element " << elemToInsert 
			<< " is already in the list. "
			<< "Duplicates are not allowed." << endl;
	else if (ptr->data > elemToInsert)
		recursiveInsert(ptr->llink, elemToInsert);
	else
		recursiveInsert(ptr->rlink, elemToInsert);
}

	//recursiveInorder
void BST::recursiveInorder() const
{
	recursiveInorder(root);
}

	//recursiveInorder (private)
void BST::recursiveInorder(Node* ptr) const
{
	if (ptr != nullptr)
	{
		recursiveInorder(ptr->llink);
		cout << ptr->data << " ";
		recursiveInorder(ptr->rlink);
	}
}

	//totalNodes
int BST::totalNodes() const
{
	return count;
}

	//isEmpty
bool BST::isEmpty() const
{
	return (root == nullptr);
}

	//emptyTree
void BST::emptyTree()
{
	clearTree(root);
	count = 0;
}

	//clearTree
void  BST::clearTree(Node* &ptr)
{
	if (ptr != nullptr)
	{
		clearTree(ptr->llink);
		clearTree(ptr->rlink);
		delete ptr;
		ptr = nullptr;
	}
}

	//destructor
BST::~BST()
{
	clearTree(root);
}


