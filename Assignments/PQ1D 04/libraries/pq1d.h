#include<iostream>

typedef struct Node* Nodeptr;

struct Node
{
    std::string name;
    std::string role;
    int priority;
    Nodeptr next;
};


class PriorityQueue1D
{
    private:
    Nodeptr head;
    bool isEmpty();
    Nodeptr makeNode(std::string name, std::string role, int priority);
    
    public:
    PriorityQueue1D();
    ~PriorityQueue1D();
    void insert(std::string name, std::string role, int priority);
    void display();
    std::string remove();
    int getPriority(std::string role);
};

PriorityQueue1D::PriorityQueue1D()
{
    head = nullptr;
}

PriorityQueue1D::~PriorityQueue1D()
{
    while(!isEmpty())
    {
        remove();
    }
}

bool PriorityQueue1D::isEmpty()
{
    return (head == nullptr);
}

Nodeptr PriorityQueue1D::makeNode(std::string name, std::string role, int priority)
{
    Nodeptr newNode = new Node;
    newNode->name = name;
    newNode->role = role;
    newNode->priority = priority;
    newNode->next = nullptr;
    return newNode;
}

void PriorityQueue1D::insert(std::string name, std::string role, int priority)
{
    Nodeptr newNode = makeNode(name, role, priority);
    if(isEmpty() || priority > head->priority)
    {
        newNode->next = head;
        head = newNode;
    }
    else
    {
        Nodeptr current = head;
        while(current->next!= nullptr && current->next->priority >= priority)
        {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

void PriorityQueue1D::display()
{
    Nodeptr current = head;
    std::cout << "Priority Queue: " << std::endl;
    while(current!= nullptr)
    {
        std::cout << "Name: " << current->name << ", Role: " << current->role << ", Priority: " << current->priority << std::endl;
        current = current->next;
    }
}

std::string PriorityQueue1D::remove()
{
    if(isEmpty())
    {
        throw std::runtime_error("Priority Queue is empty");
    }
    std::string name = head->name;
    Nodeptr temp = head;
    head = head->next;
    delete temp;
    return name;
}

int PriorityQueue1D::getPriority(std::string role) 
{
    if (role == "Teacher") return 2;
    else if (role == "Parent") return 3;
    else if (role == "Student") return 1;
    return 0;
}