#include "list.h"
#include <iostream>

LinkedStr::LinkedStr() {
    ptr = nullptr;
}

LinkedStr::~LinkedStr() {
    Node* temp;
    while (ptr != nullptr) {
        temp = ptr;
        ptr = ptr->next;
        delete temp;
    }
}

void LinkedStr::makeStr(int len){
    Node* head = nullptr;
    Node* ptr = nullptr; 

    if (len <= 0) {
        std::cerr << "Error Msg: Invalid length!" << std::endl;
        return;
    }

    for (int i = 0; i < len; ++i) {
        int value;
        std::cout << "Enter value for node " << i + 1 << ": ";
        std::cin >> value;

        Node* newNode = new Node;
        newNode->info = value;

        if (head == nullptr) {
            head = newNode;
        } else {
            ptr->next = newNode;
        }

        ptr = newNode;
    }
    this->ptr = head;
}

void LinkedStr::displayStr() {
    for(Node* p = ptr; p != nullptr; p = p->next){
        std::clog << p->info << " ";
    }
}

void LinkedStr::removeFirst() {
    if(ptr == nullptr){
        return;
    }
    if(ptr->next == nullptr){
        return removeLast();
    }
    Node* p = ptr;
    Node* q = nullptr;
    while(p->next != nullptr){
        if(p->next->next == nullptr){
            q = p;
        }
        p = p->next;
    }
    delete p;
    q->next = nullptr;
    
}
void LinkedStr::removeLast() {
    if(ptr == nullptr){
        return;
    }
    Node* temp = ptr;
    ptr = ptr->next;
    delete temp;
}

void LinkedStr::remove(int k) {
    Node* q = nullptr;
    if(ptr->info == k){
        removeLast();
    }
    for(Node* p = ptr; p != nullptr; p = p->next){
        if(p->next->info == k){
            q = p->next;
            delete q;
            p->next = p->next->next;
        }
    }
}