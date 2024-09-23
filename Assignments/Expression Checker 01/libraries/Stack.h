#ifndef STACK_H
#define STACK_H

#include <iostream>

class Stack
{
    public:
        Stack(){}
        Stack(int maxStack);
        ~Stack();
        bool isEmpty() const;
        bool isFull() const;
        void push(char newItem);
        void clear();
        int size() const;
        char pop();

    private:
        int top;
        int maxLimit;
        int items;
};

#endif