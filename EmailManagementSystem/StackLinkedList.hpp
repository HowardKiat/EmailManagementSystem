#pragma once
#include <iostream>
#include <string>
using namespace std;

class StackNode {
public:
    string data;
    StackNode* next;
    StackNode(const string& d) : data(d), next(nullptr) {}
};

class StackLinkedList {
private:
    StackNode* top;

public:
    StackLinkedList() : top(nullptr) {}

    ~StackLinkedList() {
        while (top != nullptr) {
            pop();
        }
    }

    void push(const string& item) {
        StackNode* newNode = new StackNode(item);
        newNode->next = top;
        top = newNode;
    }

    void pop() {
        if (top == nullptr) {
            cout << "Stack is empty.\n";
            return;
        }
        StackNode* temp = top;
        top = top->next;
        delete temp;
    }

    void displayStack() const {
        StackNode* current = top;
        if (current == nullptr) {
            cout << "Stack is empty.\n";
            return;
        }
        while (current) {
            cout << current->data << endl;
            current = current->next;
        }
    }

    bool isEmpty() const {
        return top == nullptr;
    }
};
