#include "Queue.h"
#include <iostream>
#include <map>

template <typename T>
class PriorityQueue2d{
    private:
        std::map<int, Queue<T>> queue;

    public:
        void insert(int pLvl,T value);
        T remove();
        void display();
        bool isEmpty();
};

template <typename T>
void PriorityQueue2d<T>::insert(int pLvl, T value) {
    queue[pLvl].insert(value);
}
template <typename T>
T PriorityQueue2d<T>::remove(){
    if(!isEmpty()){
        auto firstElem = queue.begin();
        T data = firstElem->second.remove();

        if(firstElem->second.isEmpty()){
            queue.erase(firstElem);
        }

        return data;
    }
    else{
        throw std::out_of_range("Queue is empty");
    }
}
template <typename T>
void PriorityQueue2d<T>::display(){
    for (const auto& [outerPriority, innerQueue] : queue) {
            std::cout << "Outer Priority " << outerPriority << ": ";
            
            Queue<T> tempQueue = innerQueue;
            while (!tempQueue.isEmpty()) {
                std::cout << tempQueue.getFront() << " ";
                tempQueue.remove();
            }
            std::cout << std::endl;
    }
}

template <typename T>
bool PriorityQueue2d<T>::isEmpty(){
    return queue.empty();
}