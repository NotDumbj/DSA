#include "Stack.h"
#include <iostream>
#include <ctime> // for time
#include <cstdlib> // for random

int main(){
    Stack<int> myStack(5);
    myStack.push(10);
    myStack.push(20);
    myStack.push(30);
    myStack.push(40);
    myStack.push(50);
    myStack.push(60); // overflow error

    while(!myStack.isEmpty()){
        std::cout << myStack.pop() << std::endl;
    }

    myStack.pop();  // underflow error


    ////////////////////////////////////////////////////////////////

    Stack<int> myStack2(10);

    std::srand(std::time(0));

    for(int i = 0; i < 10; i++){
        myStack2.push(std::rand() % 100 + 1);
    }

    std::cout << "\nMaximum number: " << myStack2.maximum() << std::endl;
    std::cout << "Minimum number: " << myStack2.minimum() << std::endl;

    while(!myStack2.isEmpty()){
        std::cout << myStack2.pop() << std::endl;
    }

    Stack<bool> boolStack(5);
    boolStack.push(true);
    boolStack.push(false);

    boolStack.maximum();

    return 0;
}
