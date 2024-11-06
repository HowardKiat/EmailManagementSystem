#pragma once
#include "QueueLinkedList.hpp"

class Outbox {
private:
    QueueLinkedList outboxQueue;

public:
    // Method to send an email by enqueueing it into the outbox queue
    void sendEmail(const std::string& email) {
        outboxQueue.enqueue(email);
        std::cout << "Email sent: " << email << std::endl;
    }

    // Method to display outbox contents
    void showOutbox() const {
        std::cout << "Displaying outbox contents:\n";
        outboxQueue.displayQueue();
    }
};
