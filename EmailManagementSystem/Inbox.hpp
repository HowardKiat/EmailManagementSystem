#pragma once
#include "StackLinkedList.hpp"

class Inbox {
private:
    StackLinkedList inboxStack;

public:
    // Method to receive an email and push it to the inbox stack
    void receiveEmail(const std::string& email) {
        inboxStack.push(email);
        std::cout << "Email received: " << email << std::endl;
    }

    // Method to display inbox contents
    void showInbox() const {
        std::cout << "Displaying inbox contents:\n";
        inboxStack.displayStack();
    }

    // Method to delete the most recent email (pop from stack)
    void deleteEmail() {
        if (inboxStack.isEmpty()) {
            std::cout << "No emails to delete.\n";
        }
        else {
            inboxStack.pop();
            std::cout << "Most recent email deleted.\n";
        }
    }
};
