#pragma once
#include <iostream>
using namespace std;

struct StackNode {
    string data;
    StackNode* next;
    StackNode(string data) : data(data), next(nullptr) {}
};

class StackLinkedList {
private:
    StackNode* top;
    int size;

public:
    StackLinkedList();
    ~StackLinkedList();
    void push(string data);
    void pop();
    bool isEmpty();
    int getSize();
    void displayStack();
};

StackLinkedList::StackLinkedList() : top(nullptr), size(0) {}

StackLinkedList::~StackLinkedList() {
    while (!isEmpty()) pop();
}

void StackLinkedList::push(string data) {
    StackNode* newNode = new StackNode(data);
    newNode->next = top;
    top = newNode;
    size++;
}

void StackLinkedList::pop() {
    if (isEmpty()) return;
    StackNode* temp = top;
    top = top->next;
    delete temp;
    size--;
}

bool StackLinkedList::isEmpty() {
    return top == nullptr;
}

int StackLinkedList::getSize() {
    return size;
}

void StackLinkedList::displayStack() {
    StackNode* temp = top;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

//CHANGE LATER ON