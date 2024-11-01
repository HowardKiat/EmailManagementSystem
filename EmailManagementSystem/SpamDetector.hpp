#pragma once
#include "QueueLinkedList.hpp"

class SpamDetector {
private:
    QueueLinkedList spamQueue;

public:
    void markSpam(string email);
    void showSpam();
    void deleteSpam();
};


void SpamDetector::markSpam(string email) {
    spamQueue.enqueue(email);
}

void SpamDetector::showSpam() {
    spamQueue.displayQueue();
}

void SpamDetector::deleteSpam() {
    spamQueue.dequeue();
}
