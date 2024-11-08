#pragma once
#include <iostream>

class QueueLinkedList {
private:
    struct Node {
        std::string email;
        Node* next;
        Node(const std::string& emailContent) {
            email = emailContent;
            next = nullptr;
        }
    };

    Node* front;
    Node* rear;

public:
    QueueLinkedList() {
        front = nullptr;
        rear = nullptr;
    }

    // Check if the queue is empty
    bool isEmpty() const {
        return front == nullptr;
    }

    // Enqueue
    void enqueue(const std::string& email) {
        Node* newNode = new Node(email);
        if (isEmpty()) {
            front = rear = newNode;
        }
        else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    // Dequeue
    void dequeue() {
        if (isEmpty()) {
            std::cout << "Queue is empty.\n";
            return;
        }
        Node* temp = front;
        front = front->next;
        delete temp;
    }

    // Display all emails in the queue
    void displayQueue() const {
        if (isEmpty()) {
            std::cout << "Queue is empty.\n";
            return;
        }
        Node* current = front;
        while (current != nullptr) {
            std::cout << current->email << std::endl;
            current = current->next;
        }
    }

    ~QueueLinkedList() {
        while (!isEmpty()) {
            dequeue();
        }
    }
};
