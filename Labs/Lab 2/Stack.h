#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <type_traits>

template<class T>
class Stack{
public:
    Stack(){}
    Stack(int maxStack);
    ~Stack();
    bool isEmpty() const;
    bool isFull() const;
    void push(T newItem);
    void clear();
    int size() const;
    T pop();
    T maximum() const;
    T minimum() const;

private:
    int top;
    int maxLimit;
    T* items;
};

//#include "Stack.cpp"

#endif