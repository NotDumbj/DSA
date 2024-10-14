#include <iostream>
#include "Queue.h"
#include <fstream>
#include <initializer_list>
#include <map>
#include <vector>


template <class itemType>
class PriorityQueue2D
{
    private:
        std::map<std::string, int> priorityLevels;
        Queue<itemType> *queues;

    public:
        PriorityQueue2D();
        PriorityQueue2D(int noOfPriorityLevels);
        PriorityQueue2D(int noOfPriorityLevels, std::initializer_list<int> sizes);
        ~PriorityQueue2D();
        void loadData();
        void insertItem(int index, itemType value);
        itemType removeItem();
};

template <class itemType>
PriorityQueue2D<itemType>::PriorityQueue2D()
{
    priorityLevel = 3;
    queues = new Queue<itemType>[priorityLevel];
    priorityLevels["student"] = 1;
    priorityLevels["teacher"] = 2;
    priorityLevels["parent"] = 3;
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
void PriorityQueue2D<itemType>::loadData()
{
    path = "Assignments/Priority Queue 02/data/data.txt";
    std::ifstream inputFile(path);
    
    if(!inputFile.is_open())
    {
        std::cerr << "Error: File not Opening." << std::endl;
        return;
    }

    vector<string> students;
    vector<string> teachers;
    vector<string> parents;
    std::string lineData;
    while(std::getline(inputFile, lineData))
    {
        if (lineData == "student")
        {
            std::getline(inputFile, lineData);
            students.push_back(lineData);
        }
        else if (lineData == "teacher")
        {
            std::getline(inputFile, lineData);
            teachers.push_back(lineData);
        }
        else if (lineData == "parent")
        {
            std::getline(inputFile, lineData);
            parents.push_back(lineData);
        }
    }
    Queue<string> studentQueue = new Queue<string>(students);
    Queue<string> teacherQueue = new Queue<string>(teachers);
    Queue<string> parentQueue = new Queue<string>(parents);
    queues[0] = studentQueue;
    queues[1] = teacherQueue;
    queues[2] = parentQueue;
}

template <class itemType>
PriorityQueue2D<itemType>::insertItem(int index, itemType value)
{
    queues[index].insert(value);
}

template <class itemType>
PriorityQueue2D<itemType>::removeItem()
{
    while(!queues[2].isEmpty())
    {
        return queues[2].remove();
    }
    while(!queues[1].isEmpty() && queues[2].isEmpty())
    {
        return queues[1].remove();
    }
    while(!queues[0].isEmpty() && queues[1].isEmpty)
    {
        return queues[0].remove();
    }
}