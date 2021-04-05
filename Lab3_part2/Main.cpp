/*
    Taylor, Charlie
    Ziller, Joseph

    April 5,2021

    CS A200
    Lab 3: Stacks Part 2
*/

#include "Stack.h"
#include "Stack.cpp"
#include "Student.h"
#include "Student.cpp"

using namespace std;

int main()
{
    //Test #1
    Stack<int> test1;

	test1.push(1);
	cout << test1.top() << "\n";
	test1.pop();
    cout << test1.empty()  << "\n";

	Stack<int> yeehaw;
	yeehaw.push(3);
	yeehaw.push(4);

    test1.swap(yeehaw);

    cout << "Original stack is now:\n";
    while(!test1.empty())
    {
        cout << test1.top() << "\n";
        test1.pop();
    }


	//Test 2
	Stack<string> names;

	names.push("Joe");
	cout << names.top() << "\n";
    
	names.pop();
	cout << names.empty() << "\n";

	Stack<string> lastNames;
	lastNames.push("Taylor");
	lastNames.push("Ziller");

	names.swap(lastNames);

	cout << "Original stack is now:\n";
    while(!names.empty())
    {
        cout << names.top() << "\n";
        names.pop();
    }

	//Test 3
    Stack<int> test3;
    test3.push(1);
    test3.push(2);
    test3.push(3);
    Stack<int> copy3(test3);
    copy3.pop();

    cout << "test3 is size " << test3.size() << 
            " and the copy is size " << copy3.size() << "\n";


    // //Test 4
    // Stack<int> test4;
    // test3.push(4);
    // test3.push(5);
    // test3.push(6);
	// Stack<int> move4 = move(test4);
    // move4.top() = 7;
    // cout << "test4 is " << test4.top() <<
    //         " and the move is " << move4.top();

	//Test 5
	Stack<int> test5One;
    test5One.push(7);
    test5One.push(8);
    test5One.push(9);
	test5One.push(10);

	Stack<int> test5Two;
    test5Two.push(3);
    test5Two.push(4);
    test5Two.push(5);

	test5Two = test5One;

	test5Two.pop();

    cout << "test5One is size " << test5One.size() << 
            " test5Two is size " << test5Two.size() << "\n";

    // //Test 6
	// Stack<int> stack1;
	// stack1.push(4);
	// stack1.push(5);
	// stack1.push(6);

	// Stack<int> stack2;
    // stack2.push(1);
	// stack2.push(2);
	// stack2.push(3);

	// stack1 = move(stack2);

	// stack1.pop();
	// stack2.pop();

    //Test 7
    // set up first stack
    Student John;
    Student Sally(10, 'A');
    Student Greg;
    Stack<Student> test7;
    test7.push(John);
    test7.push(Sally);
    test7.push(Greg);

    test7.pop();
    cout << "test7 size is " <<test7.size() << "\n";
    test7.empty();

    cout << test7.top() << "\n";
    // set up swapping stack 
    Stack<Student> test7swap;
    Student James(20, 'B');
    Student Sam(10, 'A');
    Student Charlie(30, 'C');
    test7.push(James);
    test7.push(Sam);
    test7.push(Charlie);

	test7.swap(test7swap);
    //set up copy constructor and assignment swap stack
    Stack<Student> ploy(test7swap);

    cout << "ploy contains after test7swap\n";
    cout << "ploy is of size " << ploy.size()  << "\n";
	while(!ploy.empty())
    {
		cout << ploy.top() << "\n";
		ploy.pop();
	}

	ploy = test7;

    cout << "ploy contains after test7 assignment\n";
    cout << "ploy is of size " << ploy.size()  << "\n";
    while(!ploy.empty())
    {
		cout << ploy.top() << "\n";
		ploy.pop();
	}

	ploy = move(test7swap);

    cout << "ploy's contents after using"
         << "the move constructor with test7swap\n";
    cout << "ploy is of size " << ploy.size() << "\n";

    while(!ploy.empty())
    {
		cout << ploy.top() << "\n";
		ploy.pop();
	}

	Stack<Student> moveConstructor7 = move(ploy);

    cout << "moveConstructor7's contents after using"
            << " the move constructor with test7swap\n";
    cout << "moveConstructor7 is of size " 
        << moveConstructor7.size() << "\n";
    
    
    while(!moveConstructor7.empty())
    {
		cout << moveConstructor7.top() << "\n";
		moveConstructor7.pop();
	}

	return 0;
}