#include<iostream>
#include "../Queue.h"
using namespace std;

int main()
{
    int size;
    cout << "Enter Queue Size: ";
    cin >> size;

    Queue<int>* queue = new Queue<int>(size);

    cout << "Enter Queue Elements: " << endl;
    for (int i = 0; i < size; i++){
        cout << "Element "<< i+1 << ": ";
        int data;
        cin >> data;
        queue->insert(data);
    }
    
    cout << "Enter Element Number to Reverse from: ";
    int k;
    cin >> k;
    
    if(k > size){
        cout << "Error: Invalid Element Number" << endl;
        return 0;
    }

    queue->reverse(k);

    cout << "Queue elements (Updated): " << endl;
    while(!queue->isEmpty()){
        cout << queue->remove() << endl;
    }
    return 0;
}