#include "Stack.h"
#include "Stack.cpp"
#include "Student.h"

using namespace std;

int main()
{
    //Test #1
    Stack<int> yeet;

	yeet.push(1);
	cout << yeet.top() << "\n";
	yeet.pop();
    cout << yeet.empty()  << "\n";

	Stack<int> yeehaw;
	yeehaw.push(3);
	yeehaw.push(4);

    yeet.swap(yeehaw);

    cout << "Original stack is now:\n";
    while(!yeet.empty())
    {
        cout << yeet.top() << "\n";
        yeet.pop();
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

    Stack<Student> test7;
    test7.push(new Student());


	return 0;
}