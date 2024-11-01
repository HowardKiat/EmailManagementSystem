#pragma once
#include <iostream>
using namespace std;

struct queueNode {
    string emailData;
    queueNode* nextNode;
};

class QueueLinkedList {
    queueNode* front, * rear;
    int queueSize;
    string queueName;

public:
    QueueLinkedList(string queueName = "") : front(nullptr), rear(nullptr), queueSize(0), queueName(queueName) {}

    ~QueueLinkedList() {
        cout << queueName << " is deleted from the memory!" << endl;
        while (!isEmpty()) {
            dequeue();
        }
    }

    bool isEmpty() const {
        return front == nullptr;
    }

    queueNode* createNewNode(const string& emailData) {
        queueNode* newNode = new queueNode;
        newNode->emailData = emailData;
        newNode->nextNode = nullptr;
        return newNode;
    }

    void enqueue(const string& emailData) {
        queueNode* newNode = createNewNode(emailData);

        if (isEmpty()) {
            front = rear = newNode;
        }
        else {
            rear->nextNode = newNode;
            rear = newNode;
        }
        queueSize++;
    }

    string dequeue() {
        if (isEmpty()) {
            cout << "Error: Queue is empty!" << endl;
            return "";
        }

        queueNode* current = front;
        front = front->nextNode;

        if (front == nullptr)  // Queue is now empty
            rear = nullptr;

        string value = current->emailData;
        delete current;
        queueSize--;
        return value;
    }

    void displayQueue() const {
        if (isEmpty()) {
            cout << "The queue is empty!" << endl;
            return;
        }

        queueNode* current = front;
        while (current != nullptr) {
            cout << current->emailData << endl;
            current = current->nextNode;
        }
    }

    int size() const {
        return queueSize;
    }
};
