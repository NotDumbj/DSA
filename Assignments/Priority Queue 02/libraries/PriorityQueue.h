#include <iostream>
#include "Queue.h"
#include <fstream>
#include <initializer_list>
#include <map>


template <class itemType>
class PriorityQueue2D{
    private:
        std::map<std::string, int> priorityLevels;
        Queue<itemType> *queues;
        int noOfPriorityLevel;

    public:
        PriorityQueue2D();
        PriorityQueue2D(int noOfPriorityLevels);
        PriorityQueue2D(int noOfPriorityLevels, std::initializer_list<int> sizes);
        ~PriorityQueue2D();
        void readFile();
};

template <class itemType>
PriorityQueue2D<itemType>::PriorityQueue2D(){
    priorityLevel = 1;
    queues = new Queue<itemType>[priorityLevel];
    priorityLevels["Low"] = 0;
    priorityLevels["Medium"] = 1;
    priorityLevels["High"] = 2;
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

template <class itemType>
void PriorityQueue2D<itemType>::readFile(){
    path = "Assignments/Priority Queue 02/data/data.txt";
    std::ifstream inputFile(path);
    
    if(!inputFile.is_open()){
        std::cerr << "Error: File not Opening." << std::endl;
        return;
    }
    
    std::string lineData;
    while(std::getline(inputFile, lineData)){
        
    }
}