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
        itemType front() const;
        int size() const;
        void insert(itemType item);
        itemType remove();
        void loadVector(vector<itemType> data);
        void display() const;
};

template <class itemType>
Queue<itemType>::Queue(std::vector<itemType> data)
{ 
    front = rear = 0;
    count = 0;
    capacity = data.size();
    items = new itemType[capacity];
    loadVector(data);
}

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
Queue<itemType>::display() const
{
    for (int i = front; i < rear; i++)
    {
        std::cout << i << ". " << items[i] << endl;
    }
    std::cout << std::endl;
}

template <class itemType>
Queue<itemType>::loadVector(vector<itemType> data)
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
itemType Queue<itemType>::front() const{
    return items[front];
}

template <class itemType>
int Queue<itemType>::size() const{
    return count;
}


