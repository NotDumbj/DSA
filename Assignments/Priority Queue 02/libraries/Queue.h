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
        void loadVector(std::vector<itemType> data);
        
    public:
        Queue();
        Queue(int size);
        Queue(std::vector<itemType> data);
        ~Queue();
        bool isEmpty() const;
        bool isFull() const;
        itemType getFront() const;
        int size() const;
        void insert(itemType item);
        itemType remove();
        void display() const;
};

template <class itemType>
Queue<itemType>::Queue(std::vector<itemType> data)
{ 
    front = 0;
    rear = -1;
    count = 0;
    capacity = data.size();
    items = new itemType[capacity];
    loadVector(data);
}

template <class itemType>
Queue<itemType>::Queue(){
    front = 0;
    rear = -1;
    capacity = 10;
    count = 0;
    items = new itemType[capacity];
}

template <class itemType>
Queue<itemType>::Queue(int size) : capacity(size) {
    front = 0;
    rear = -1;
    count = 0;
    items = new itemType[capacity];
}

template <class itemType>
Queue<itemType>::~Queue(){
    delete[] items;
}

template <class itemType>
void Queue<itemType>::display() const {
    if (isEmpty()) {
        std::cout << "Queue is empty." << std::endl;
        return;
    }

    int i = front;
    int j = 1;
    int displayCount = 0;
    while (displayCount < count) {
        std::cout << j << ". " << items[i] << std::endl;
        i = (i + 1) % capacity;
        j++;
        displayCount++;
    }
    std::cout << std::endl;
}
template <class itemType>
void Queue<itemType>::loadVector(std::vector<itemType> data)
{
    for (int i = 0; i < data.size(); i++)
    {
        insert(data[i]);
    }
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
        itemType item = items[front];
        front = (front + 1) % capacity;
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


