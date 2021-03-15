/*
    Taylor, Charlie
    Ziller, Joseph

    March ?,2021

    CS A200
    Lab 3: Stacks
*/


#include "Stack.h"
using namespace std;

Stack::Stack(const Stack& otherStack)
{
    stack = new list<int>;
	*stack = *otherStack.stack;
	numOfElements = otherStack.numOfElements;
}

Stack& Stack::operator=(const Stack& otherStack)
{
    if (this == &otherStack)
    {
        cerr << "Attempted self-assignment!";
    }
    else
    {
        *stack = *otherStack.stack;
        numOfElements = otherStack.numOfElements;
    }
    return *this;
}

void Stack::push(int elemToInsert)
{
    stack->push_front(elemToInsert);
    ++numOfElements;
}

void Stack::pop()
{
	stack->pop_front();
	--numOfElements;
}

int Stack::top() const
{
    return stack->front();
}

int Stack::size() const
{
	return numOfElements;
}

void Stack::swap(Stack& otherStack)
{
    stack->swap(*otherStack.stack);
    int temp = numOfElements;
    numOfElements = otherStack.numOfElements;
    otherStack.numOfElements = temp;
}

bool Stack::empty() const
{
	return numOfElements == 0;
}

void Stack::emplace(int elemToInsert)
{
    stack->push_front(elemToInsert);
    ++numOfElements;
}

Stack::~Stack() 
{
	delete stack;
	stack = nullptr;
	numOfElements = 0;
}