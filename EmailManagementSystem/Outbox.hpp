#pragma once
#include "QueueLinkedList.hpp"

class Outbox {
private:
    QueueLinkedList sentEmails;

public:
    void sendEmail(string email);
    void showOutbox();
    void removeSentEmail();
};


void Outbox::sendEmail(string email) {
    sentEmails.enqueue(email);
}

void Outbox::showOutbox() {
    sentEmails.displayQueue();
}

void Outbox::removeSentEmail() {
    sentEmails.dequeue();
}
