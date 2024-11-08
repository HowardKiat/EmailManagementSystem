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
        if (email.empty()) {
            std::cerr << "Error: Cannot send an empty email." << std::endl;
            return;
        }
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

    // Method to get all emails in the outbox for searching
    void getAllOutboxEmails(StackLinkedList& outboxSearchList) const {
        // Create a temporary stack to hold the emails for iteration
        StackLinkedList tempStack = outboxStack;

        // While the outbox stack is not empty, pop emails and push them to outboxSearchList
        while (!tempStack.isEmpty()) {
            std::string email = tempStack.peek();  // Peek at the top email
            tempStack.pop();                       // Pop from outbox stack
            outboxSearchList.push(email);          // Push to the search list (stack)
        }
    }
};
