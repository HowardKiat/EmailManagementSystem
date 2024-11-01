#pragma once
#include "QueueLinkedList.hpp"

class Inbox {
private:
    QueueLinkedList emails;

public:
    void receiveEmail(string email);
    void showInbox();
    void deleteEmail();
};


void Inbox::receiveEmail(string email) {
    emails.enqueue(email);
}

void Inbox::showInbox() {
    emails.displayQueue();
}

void Inbox::deleteEmail() {
    emails.dequeue();
}
