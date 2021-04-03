/*
    Taylor, Charlie
    Ziller, Joseph

    March 19,2021

    CS A200
    Lab 3: Stacks
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
    void push(T);
    void pop();
    T& top() const;
    size_t size() const;
    void swap(Stack<T>&);
    bool empty() const;
    void emplace(T&);

    ~Stack<T>();
private:
    std::list<T> *stack;
};

#endif