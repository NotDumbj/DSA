#include<iostream>
#include "../Queue.h"
using namespace std;

int main()
{
    int size = 10;
    Queue<int>* queue = new Queue<int>(size);
    for (int i = 0; i < size; i++){
        queue->insert(i+1);
    }
    cout << "Queue elements: ";
    while(!queue->isEmpty()){
        cout << queue->remove() << endl;
    }
    return 0;
}