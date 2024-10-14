#include <iostream>
#include <vector>

template <class itemType>
class Queue{
    private:
        int front;
        int rear;
        int capacity;
        int count;
        itemType* items;
        
    public:
        Queue();
        Queue(int size);
        ~Queue();
        bool isEmpty() const;
        bool isFull() const;
        itemType getFront() const;
        int size() const;
        void insert(itemType item);
        void reverse(int k);
        itemType remove();
};

template <class itemType>
Queue<itemType>::Queue(){
    front = rear = 0;
    capacity = 10;
    count = 0;
    items = new itemType[capacity];
}

template <class itemType>
Queue<itemType>::Queue(int size) : capacity(size) {
    front = rear = 0;
    count = 0;
    items = new itemType[capacity];
}

template <class itemType>
Queue<itemType>::~Queue(){
    delete[] items;
}

template <class itemType>
bool Queue<itemType>::isEmpty() const{
    return (count == 0);
}

template <class itemType>
bool Queue<itemType>::isFull() const{
    return (count == capacity);
}

template <class itemType>
void Queue<itemType>::insert(itemType item){
    if(!(isFull())){
        rear = (rear + 1) % capacity;
        items[rear] = item;
        count++;
    }
    else{
        std::cerr << "Error: Queue Overflow" << std::endl;
    }
}

template <class itemType>
itemType Queue<itemType>::remove(){
    if(!(isEmpty())){
        front = (front + 1) % capacity;
        itemType item = items[front];
        count--;
        return item;
    }
    else{
        std::cerr << "Error: Queue Underflow" << std::endl;
        return itemType();
    }
}

template <class itemType>
itemType Queue<itemType>::getFront() const{
    return items[front];
}

template <class itemType>
int Queue<itemType>::size() const{
    return count;
}

template <class itemType>
void Queue<itemType>::reverse(int k){
    Queue<itemType> queue;
    int i = 0;
    itemType arrItem[k];
    if(!isEmpty()){
        while(front != k){
            arrItem[i] = remove();
            i++;
        }
    }

    for (int j = k - 1; j >= 0; j--){
        queue.insert(arrItem[j]);
    }

    while(!isEmpty()){
        queue.insert(remove());
    }

    *this = queue;
}
