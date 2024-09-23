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



template <class T>
Stack<T>::Stack(int maxStack){
    maxLimit = maxStack;
    top = -1;
    items = new T[maxLimit];
}

template <class T>
Stack<T>::~Stack(){
    delete[] items;
}

template <class T>
bool Stack<T>::isEmpty() const{
    return (top == -1);
}

template <class T>
bool Stack<T>::isFull() const{
    return (top == maxLimit - 1);
}

template <class T>
void Stack<T>::push(T newItem){
    if(!(isFull())){
        top++;
        items[top] = newItem;
    }
    else{
        std::cerr << "Error: Stack Overflow" << std::endl;
    }
}

template <class T>
T Stack<T>::pop(){
    if(!(isEmpty())){
        return items[top--];
    }
    else{
        std::cerr << "Error: Stack Underflow" << std::endl;
        return T();
    }
}

template <class T>
void Stack<T>::clear(){
    top = -1;
    delete[] items;
}

//----------------------------------------------------------------
//----------------------------------------------------------------

template <class T>
T Stack<T>::maximum() const {
    if(!std::is_same<T,bool>::value){
        if(!(isEmpty())){
            T max = items[0];
            for (int i = 1; i < size(); i++){
                if(items[i] > max){
                    max = items[i];
                }
            }
            return max;
        }
        else{
            std::cerr << "Error: Stack is empty" << std::endl;
            return -1;
        }
    }
    else{
        std::cerr << "Error: Invalid data type for maximum function" << std::endl;
        return -1; 
    }

}

template <class T>
T Stack<T>::minimum() const {
    if(!std::is_same<T,bool>::value){
        if(!(isEmpty())){
            T min = items[0];
            for (int i = 1; i < size(); i++){
                if(items[i] < min){
                    min = items[i];
                }
            }
            return min;
        }
        else{
            std::cerr << "Error: Stack is empty" << std::endl;
            return -1;
        }
    }
    else{
        std::cerr << "Error: Invalid data type for minimum function" << std::endl;
        return -1; 
    }
}

template <class T>
int Stack<T>::size() const{
    return top + 1;
}


#endif