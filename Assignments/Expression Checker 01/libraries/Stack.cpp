#include "Stack.h"

Stack::Stack(int maxStack)
{
    maxLimit = maxStack;
    top = -1;
    items = new char[maxLimit];
}


Stack::~Stack()
{
    delete[] items;
}

bool Stack::isEmpty() const
{
    return (top == -1);
}

bool Stack::isFull() const
{
    return (top == maxLimit - 1);
}

void Stack::push(char newItem)
{
    if(!(isFull()))
    {
        top++;
        items[top] = newItem;
    }
    else
    {
        std::cerr << "Error: Stack Overflow" << std::endl;
    }
}

char Stack::pop()
{
    if(!(isEmpty()))
    {
        return items[top--];
    }
    else
    {
        std::cerr << "Error: Stack Underflow" << std::endl;
        return 0;
    }
}

void Stack::clear()
{
    top = -1;
    delete[] items;
}