#include "list.h"
#include <iostream>
#include <fstream>

LinkedList::LinkedList(){
    head = nullptr;
    length = 0;

}

void LinkedList::iAS(int x){
    Nodeptr p = new Node;
    p->data = x;
    p->next = head;
    head = p;

    length++;
}

int LinkedList::dAS(){
    if(head == nullptr){
        return -1;
    }
    if(head->next == nullptr){
        int x = head->data;
        head = nullptr;
        return x;
    }
    Nodeptr p = head->next;
    int x = head->data;
    delete head;
    head = p;

    length--;

    return x;
}

void LinkedList::traverse(){
    for(Nodeptr p = head; p != nullptr; p = p->next){
        std::clog << p->data << std::endl;
    }
}

Nodeptr LinkedList::find(int x){
    for(Nodeptr p = head; p != nullptr; p = p->next){
        if(p->data == x){
            return p;
        }
    }
    return nullptr;
}

void LinkedList::iAE(int x){
    if(head == nullptr){
        iAS(x);
    }
    Nodeptr p = head;
    while(p->next != nullptr){
        p = p->next;
    }
    Nodeptr q = new Node;
    q->data = x;
    q->next = nullptr;
    p->next = q;

    length++;
}

int LinkedList::dAE(){
    if(head == nullptr){
        return -1;
    }
    if(length == 1){
        return dAS();
    }
    Nodeptr p = head;
    Nodeptr q = nullptr;
    while(p->next != nullptr){
        if(p->next->next == nullptr){
            q = p;
        }
        p = p->next;
    }
    int x = p->data;
    delete p;
    q->next = nullptr;
    
    length--;

    return x;
}

int LinkedList::iAM(int x, int index){
    Nodeptr p = head;
    int i = 0;
    Nodeptr q = nullptr;
    while(p->next != nullptr){
        if(i == index){
            q = p;
            break;
        }
        i++;
        p = p->next;
    }

    if(q == nullptr){
        return -1;
    }

    Nodeptr r = new Node;
    r->data = x;
    r->next = q->next;
    q->next = r;

    length++;

    return 0;
}

int LinkedList::dAM(int index){
    Nodeptr p = head;
    int i = 0;
    Nodeptr q = nullptr;
    while(p->next != nullptr){
        if(i == index - 1){
            q = p;
        }
        if(i == index){
            break;
        }
        i++;
        p = p->next;
    }

    if(q == nullptr){
        return -1;
    }

    int x = p->data;
    q->next = p->next;
    delete p;
    
    length--;

    return x;
}

void LinkedList::saveList()
{
    std::ofstream file("Labs/Lab 5/Task 1/list.txt");
    for(Nodeptr p = head; p != nullptr; p = p->next)
    {
        file << p->data << std::endl;
    }
    file.close();
}

void LinkedList::loadList()
{
    std::ifstream file("Labs/Lab 5/Task 1/list.txt");
    if(file.is_open())
    {
        int x;
        while(file >> x)
        {
            iAE(x);
        }
        file.close();
    }
    else
    {
        std::cerr << "File not found" << std::endl;
        system("pause");
    }
}