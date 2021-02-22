/*
	Taylor, Charlie
	Ziller, Joseph

	February 28, 2021

	CS A200
	Lab 2
*/

#include "BST.h"
#include <stack>
#include <set>

using namespace std;

//Definition function nonRecursiveInsert
void BST::nonRecursiveInsert(int elemToInsert)
{
	Node *ptr = root;
	bool done = false;

	while(!done)
	{
		if (ptr == nullptr)
		{	
			Node* newNode = new Node;
			newNode->data = elemToInsert;
			ptr = newNode;
			++count;
			done = true;
		}
		else if (ptr->data == elemToInsert)
		{
			cerr << "Element " << elemToInsert 
				<< " is already in the list. "
				<< "Duplicates are not allowed." << endl;
			done = true;
		}
		else if (ptr->data > elemToInsert)
		{
			ptr = ptr->llink;
		}
		else
		{
			ptr = ptr->rlink;
		}
	}
}

//Definition function nonRecursiveInorder
void BST::nonRecursiveInorder() const
{
	Node* ptr = root;
	stack<Node*> traversed;
	traversed.push(ptr);
	set<int> values = {ptr->data};
	int traversalCount = 0;
	
	while(count != traversalCount)
	{
		if(ptr->llink != nullptr && values.find(ptr->llink->data) != values.end())
		{
			ptr = ptr->llink;
			traversed.push(ptr);
			values.insert(ptr->data);
			++traversalCount;
		}
		else if (ptr->rlink != nullptr && values.find(ptr->rlink->data) != values.end())
		{
			ptr = ptr->rlink;
			traversed.push(ptr);
			values.insert(ptr->data);
			++traversalCount;
		}
		else
		{
			traversed.pop();
			ptr = traversed.top();
			if (ptr->rlink != nullptr)
			{
				ptr = ptr->rlink;
				traversed.push(ptr);
				values.insert(ptr->data);
			}	
		}
	}
	
	
	
	
	
	/*
	while count != traversalcount
		if ptr->llink != nullptr
			ptr = ptr->llink
		else if ptr->rlink != nullptr
			ptr = ptr->rlink
		else
			ptr = traversed.pop()
			if ptr->rlink != nullptr
				ptr = ptr->rlink
	*/
}