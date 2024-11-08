#pragma once
#include "StackLinkedList.hpp"
#include <iostream>
#include <string>

class Outbox {
private:
    StackLinkedList outboxStack;  // Stack for Outbox

public:
    // Method to send an email by pushing it onto the outbox stack
    void sendEmail(const std::string& email) {
        outboxStack.push(email);  // Push to stack (LIFO order)
        std::cout << "Email sent: " << email << std::endl;
    }

    // Method to display outbox contents (LIFO order)
    void showOutbox() const {
        if (outboxStack.isEmpty()) {
            std::cout << "Outbox is empty. No emails have been sent yet.\n";
        }
        else {
            std::cout << "Displaying outbox contents (LIFO order):\n";
            outboxStack.displayStack();  // Display in stack order (LIFO)
        }
    }
};