/*
    Taylor, Charlie
    Ziller, Joseph

    April 5,2021

    CS A200
    Lab 3: Stacks Part 2
*/

#include "Stack.h"
using namespace std;

template <typename T>
Stack<T>::Stack(const Stack<T>& otherStack) noexcept
{
    stack = new list<T>;
	*stack = *otherStack.stack;
}

template <typename T>
Stack<T>::Stack(Stack<T>&& otherStack) noexcept
{
    stack = otherStack.stack;
    otherStack.stack = nullptr;
}

template <typename T>
Stack<T>& Stack<T>::operator=(const Stack<T>& otherStack) noexcept
{
    if (this == &otherStack)
    {
        cerr << "Attempted self-assignment!";
    }
    else
    {
        *stack = *otherStack.stack;
    }
    return *this;
}

template <typename T>
Stack<T>& Stack<T>::operator=(Stack<T>&& otherStack) noexcept
{
    if (this == &otherStack)
    {
        cerr << "Attempted self-assignment!";
    }
    else
    {
        delete stack;
        stack = otherStack.stack;
        otherStack.stack = nullptr;
    }
    return *this;
}

template <typename T>
void Stack<T>::push(const T& elemToInsert)
{
    stack->push_front(elemToInsert);
}

template <typename T>
void Stack<T>::pop()
{
    stack->pop_front();
}

template <typename T>
T& Stack<T>::top() const
{
    return stack->front();
}

template <typename T>
size_t Stack<T>::size() const
{
	return stack->size();
}

template <typename T>
void Stack<T>::swap(Stack<T>& otherStack)
{
    stack->swap(*otherStack.stack);
}

template <typename T>
bool Stack<T>::empty() const
{
	return stack->empty();
}

template <typename T>
Stack<T>::~Stack<T>()
{
	delete stack;
	stack = nullptr;
}