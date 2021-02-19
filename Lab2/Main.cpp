#include "BST.h"

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	{
		cout << "TESTING: Recursive functions...\n";

		vector<int> v = { 49, 35, 89, 24, 15, 16, 45, 67 };
		int vSize = static_cast<int>(v.size());

		BST bst;
		for (const int& i : v)
			bst.recursiveInsert(i);

		cout << "Inorder traversal (recursive):\n      ";
		if (!bst.isEmpty()) bst.recursiveInorder();
		else cerr << "Tree is empty.";
		cout << endl;
	}

	{
		cout << "\nTESTING: Recursive functions...\n";

		// 3 occurrences of 59, 2 occurrences of 12
		vector<int> v = { 59, 46, 58, 59, 25, 12, 76, 59, 12 };
		int vSize = static_cast<int>(v.size());

		BST bst;
		for (const int& i : v)
			bst.recursiveInsert(i);

		cout << "Inorder traversal (recursive):\n      ";
		if (!bst.isEmpty()) bst.recursiveInorder();
		else cerr << "Tree is empty.";
		cout << endl;
	}

	{
		cout << "\nTESTING: Non-recursive functions...\n";

		vector<int> v = { 13, 3, 9, 12, 4, 19, 2, 11, 16, 17, 18, 10 };
		int vSize = static_cast<int>(v.size());

		BST bst;
		for (const int& i : v)
			bst.nonRecursiveInsert(i);

		cout << "Inorder traversal (non-recursive):\n      ";
		if (!bst.isEmpty()) bst.nonRecursiveInorder();
		else cerr << "Tree is empty.";
	}
	
	{
		cout << "\nTESTING: Non-recursive functions...\n";

		vector<int> v = { 50, 25, 70, 16, 30, 60, 85, 12, 20, 27, 40, 54, 63, 61 };
		int vSize = static_cast<int>(v.size());

		BST bst;
		for (const int& i : v)
			bst.nonRecursiveInsert(i);

		cout << "Inorder traversal (non-recursive):\n      ";
		if (!bst.isEmpty()) bst.nonRecursiveInorder();
		else cerr << "Tree is empty.";
	}

	{
		cout << "\nTESTING: Non-recursive functions...\n";
		
		// 3 occurrences of 38, 2 occurrences of 90
		vector<int> v = { 38, 46, 58, 38, 25, 90, 76, 38, 90 }; 
		int vSize = static_cast<int>(v.size());

		BST bst;
		for (const int& i : v)
			bst.nonRecursiveInsert(i);

		cout << "Inorder traversal (non-recursive):\n      ";
		if (!bst.isEmpty()) bst.nonRecursiveInorder();
		else cerr << "Tree is empty.";
	}

	{
		cout << "\nTESTING: Non-recursive functions...\n";

		vector<int> v = { 86, 75, 64, 52, 48, 35, 31, 22 };
		int vSize = static_cast<int>(v.size());

		BST bst;
		for (const int& i : v)
			bst.nonRecursiveInsert(i);

		cout << "Inorder traversal (non-recursive):\n      ";
		if (!bst.isEmpty()) bst.nonRecursiveInorder();
		else cerr << "Tree is empty.";
	}

	cout << endl << endl;
	system("Pause");
	return 0;
}
