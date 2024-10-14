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
        int priorityLevels;
        Queue<itemType> *queues;

    public:
        PriorityQueue2D();
        PriorityQueue2D(int noOfPriorityLevels);
        PriorityQueue2D(int noOfPriorityLevels, std::initializer_list<int> sizes);
        ~PriorityQueue2D();
        void loadData();
        void insertItem(int index, itemType value);
        itemType removeItem();
        void displayItems() const;
};

template <class itemType>
PriorityQueue2D<itemType>::PriorityQueue2D()
{
    int priorityLevels = 3;
    queues = new Queue<itemType>[priorityLevels];
}

template <class itemType>
PriorityQueue2D<itemType>::~PriorityQueue2D() {
    delete[] queues; 
}


template <class itemType>
PriorityQueue2D<itemType>::PriorityQueue2D(int priorityLevels){
    this->priorityLevels = priorityLevels;
    queues = new Queue<itemType>[this->priorityLevels];
}

template <class itemType>
PriorityQueue2D<itemType>::PriorityQueue2D(int priorityLevels, std::initializer_list<int> sizes){
    this->priorityLevels = priorityLevels;
    queues = new Queue<itemType>[this->priorityLevels]; 
    int i = 0;
    for (int size : sizes) {
        if (i < priorityLevels) { 
            queues[i] = Queue<itemType>(size); 
            i++;
        }
    }
}

template <class itemType>
void PriorityQueue2D<itemType>::loadData()
{
    std::string path = "Assignments/Priority Queue 02/data/data.txt";
    std::ifstream inputFile(path);
    
    if(!inputFile.is_open())
    {
        std::cerr << "Error: File not Opening." << std::endl;
        return;
    }

    std::vector<std::string> students;
    std::vector<std::string> teachers;
    std::vector<std::string> parents;
    std::string lineData;
    while(std::getline(inputFile, lineData))
    {
        if (lineData == "Student")
        {
            std::getline(inputFile, lineData);
            students.push_back(lineData);
        }
        else if (lineData == "Teacher")
        {
            std::getline(inputFile, lineData);
            teachers.push_back(lineData);
        }
        else if (lineData == "Parent")
        {
            std::getline(inputFile, lineData);
            parents.push_back(lineData);
        }
    }
    Queue<std::string> studentQueue(students);
    Queue<std::string> teacherQueue(teachers);
    Queue<std::string> parentQueue(parents);
    queues[0] = studentQueue;
    queues[1] = teacherQueue;
    queues[2] = parentQueue;
}

template <class itemType>
void PriorityQueue2D<itemType>::insertItem(int index, itemType value)
{
    queues[index].insert(value);
}

template <class itemType>
itemType PriorityQueue2D<itemType>::removeItem()
{
    while(!queues[2].isEmpty())
    {
        return queues[2].remove();
    }
    while(!queues[1].isEmpty())
    {
        return queues[1].remove();
    }
    while(!queues[0].isEmpty())
    {
        return queues[0].remove();
    }
    return itemType();
}

template <class itemType>
void PriorityQueue2D<itemType>::displayItems() const
{
    std::cout << std::endl;

    if (!queues[2].isEmpty()) {
        std::cout << "Parents: " << std::endl;
        queues[2].display();
    } else {
        std::cerr << "Error: Parents queue is empty.\n";
    }

    if (!queues[1].isEmpty()) {
        std::cout << "Teachers: " << std::endl;
        queues[1].display();
    } else {
        std::cerr << "Error: Teachers queue is empty.\n";
    }

    if (!queues[0].isEmpty()) {
        std::cout << "Students: " << std::endl;
        queues[0].display();
    } else {
        std::cerr << "Error: Students queue is empty.\n";
    }
}