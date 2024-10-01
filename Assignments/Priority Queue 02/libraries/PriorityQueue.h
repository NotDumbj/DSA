#include <iostream>
#include "Queue.h"
#include <initializer_list>

template <class itemType>
class PriorityQueue2D{
    private:
        Queue<itemType> *queues;
        int priorityLevel;

    public:
        PriorityQueue2D();
        PriorityQueue2D(int priorityLevels);
        PriorityQueue2D(int priorityLevels, std::initializer_list<int> sizes);
        ~PriorityQueue2D();
};

template <class itemType>
PriorityQueue2D<itemType>::PriorityQueue2D(){
    priorityLevel = 1;
    queues = new Queue<itemType>[priorityLevel];
}

template <class itemType>
PriorityQueue2D<itemType>::PriorityQueue2D(int priorityLevels){
    priorityLevel = priorityLevels;
    queues = new Queue<itemType>[priorityLevel];
}

template <class itemType>
PriorityQueue2D<itemType>::PriorityQueue2D(int priorityLevels, std::initializer_list<int> sizes){
    priorityLevel = priorityLevels;
    queues = new Queue<itemType>[priorityLevel]{
        int i = 0;
        for(int size : sizes){
            queues[i] = Queue<itemType>(size);
            i++;
        }
    };
}