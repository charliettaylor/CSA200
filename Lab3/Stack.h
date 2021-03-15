/*
    Taylor, Charlie
    Ziller, Joseph

    March ?,2021

    CS A200
    Lab 3: Stacks
*/

#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <list>

class Stack
{
public:
    Stack() : stack(new std::list<int>), numOfElements(0) {}
    Stack(const Stack&);
    Stack& operator=(const Stack&);
    void push(int);
    void pop();
    int top() const;
    int size() const;
    void swap(Stack&);
    bool empty() const;
    void emplace(int);

    ~Stack();
private:
    std::list<int> *stack;
    int numOfElements;
};

#endif