/*
    Taylor, Charlie
    Ziller, Joseph

    April 5,2021

    CS A200
    Lab 3: Stacks Part 2
*/

#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <list>
#include <string>

template <typename T>
class Stack
{
public:
    Stack() : stack(new std::list<T>) {}
    Stack(const Stack<T>&) noexcept;
    Stack(Stack<T>&&) noexcept;
    Stack<T>& operator=(const Stack<T>&) noexcept;
    Stack<T>& operator=(Stack<T>&& otherStack) noexcept;
    void push(const T&);
    void pop();
    T& top() const;
    size_t size() const;
    void swap(Stack<T>&);
    bool empty() const;

    ~Stack<T>();
private:
    std::list<T> *stack;
};

#endif