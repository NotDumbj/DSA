#include "doublelinkedlist.h"
#include <iostream>
#include <fstream>

DoubleLinkedList::DoubleLinkedList()
{
    list = nullptr;
    length = 0;
}

void DoubleLinkedList::iAS(int x)
{
    Nodeptr p = new Node;
    p->data = x;
    p->prev = list;
    p->next = nullptr;
    list = p;

    length++;
}

int DoubleLinkedList::dAS()
{
    if(list == nullptr){
        return -1;
    }
    if(length == 1){
        int x = list->data;
        list = nullptr;
        return x;
    }
    Nodeptr p = list->prev;
    int x = list->data;
    delete list;
    list = p;

    length--;

    return x;
}

void DoubleLinkedList::traverse()
{
    for(Nodeptr p = list; p != nullptr; p = p->prev){
        std::clog << p->data << std::endl;
    }
}

Nodeptr DoubleLinkedList::find(int x)
{
    for(Nodeptr p = list; p != nullptr; p = p->prev){
        if(p->data == x){
            return p;
        }
    }
    return nullptr;
}

void DoubleLinkedList::iAE(int x)
{
    if(list == nullptr){
        iAS(x);
    }
    Nodeptr p = list;
    while(p->prev != nullptr){
        p = p->prev;
    }
    Nodeptr q = new Node;
    q->data = x;
    q->prev = nullptr;
    q->next = p;
    p->prev = q;

    length++;
}

int DoubleLinkedList::dAE()
{
    if(list == nullptr){
        return -1;
    }
    if(length == 1){
        return dAS();
    }
    Nodeptr p = list;
    while(p->prev != nullptr){
        p = p->prev;
    }
    Nodeptr q = p->next;
    int x = p->data;
    delete p;
    q->prev = nullptr;
    
    length--;

    return x;
}

int DoubleLinkedList::iAM(int x, int index)
{
    Nodeptr p = list;
    int i = 0;
    Nodeptr q = nullptr;
    while(p->prev != nullptr){
        if(i == index){
            q = p;
            break;
        }
        i++;
        p = p->prev;
    }

    if(q == nullptr){
        return -1;
    }

    Nodeptr r = new Node;
    r->data = x;
    r->prev = q->prev;
    r->next = q;
    q->prev->next = r;
    q->prev = r;

    length++;

    return 0;
}

int DoubleLinkedList::dAM(int index)
{
    Nodeptr p = list;
    int i = 0;
    Nodeptr q = nullptr;
    while(p->prev != nullptr){
        if(i == index){
            q = p;
        }
        i++;
        p = p->prev;
    }

    if(q == nullptr){
        return -1;
    }

    int x = q->data;
    q->next->prev = q->prev;
    q->prev->next = q->next;
    delete q;
    
    length--;

    return x;
}

void DoubleLinkedList::saveList()
{
    std::ofstream file("data/list.txt");
    for(Nodeptr p = list; p != nullptr; p = p->prev)
    {
        file << p->data << std::endl;
    }
    file.close();
}

void DoubleLinkedList::loadList()
{
    std::ifstream file("data/list.txt");
    int x;
    while(file >> x)
    {
        iAS(x);
    }
    file.close();
}

void DoubleLinkedList::clear()
{
    Nodeptr p = list->prev;
    while(p->prev != nullptr){
        Nodeptr q = p->next;
        delete p;
        p = q;
    }
}
