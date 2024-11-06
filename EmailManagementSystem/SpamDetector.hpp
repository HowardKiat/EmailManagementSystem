#pragma once
#include "QueueLinkedList.hpp"

class SpamDetector {
private:
    QueueLinkedList spamQueue;

public:
    // Method to mark an email as spam by enqueueing it into the spam queue
    void markSpam(const std::string& email) {
        spamQueue.enqueue(email);
    }

    // Method to display spam emails
    void showSpam() const {
        if (spamQueue.isEmpty()) {
            std::cout << "No spam emails.\n";
        }
        else {
            std::cout << "Displaying spam emails:\n";
            spamQueue.displayQueue();
        }
    }
};
