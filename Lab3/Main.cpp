#include "Stack.h"
#include "Stack.cpp"
#include <stack>
using namespace std;
int main()
{
    //Bergers Code
    stack<int> myStack;
    myStack.push(1);
    myStack.push(2);
    myStack.push(3);
    if (!myStack.empty())
        myStack.pop();
    myStack.push(4);
    while (!myStack.empty())
    {
        cout << myStack.top() << " ";
        myStack.pop();
    }
    cout << "\n";
    //Our code
    Stack myStac;
    Stack uStack;
    myStac.push(1);
    myStac.push(2);
    myStac.push(3);
    uStack.push(4);
    uStack.push(5);
    uStack.push(6);
    if (!myStac.empty())
        myStac.pop();
    myStac.push(4);

    while (!myStac.empty())
    {
        cout << myStac.top() << " ";
        myStac.pop();
    }

    myStac = uStack;
    Stack newStack(myStac);
    while (!myStac.empty())
    {
        cout << myStac.top() << " ";
        myStac.pop();
    }
    cout << "pog";
    while(!newStack.empty())
    {
        cout << newStack.top() << " ";
        newStack.pop();
    }

    return 0;

}