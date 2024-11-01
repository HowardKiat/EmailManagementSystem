#pragma once
#include "QueueLinkedList.hpp"

class PriorityQueue {
private:
    QueueLinkedList highPriority;
    QueueLinkedList lowPriority;

public:
    void addHighPriority(string email);
    void addLowPriority(string email);
    void showPriority();
};

void PriorityQueue::addHighPriority(string email) {
    highPriority.enqueue(email);
}

void PriorityQueue::addLowPriority(string email) {
    lowPriority.enqueue(email);
}

void PriorityQueue::showPriority() {
    cout << "High Priority Emails:" << endl;
    highPriority.displayQueue();
    cout << "Low Priority Emails:" << endl;
    lowPriority.displayQueue();
}
