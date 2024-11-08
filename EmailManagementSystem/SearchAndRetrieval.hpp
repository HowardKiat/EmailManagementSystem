#pragma once
#include <iostream>
#include <string>

struct EmailNode {
    std::string email;
    EmailNode* next;

    // Constructor initializes email content and sets the next pointer to nullptr
    EmailNode(const std::string& emailContent) : email(emailContent), next(nullptr) {}
};

class SearchAndRetrieval {
private:
    EmailNode* head;

public:
    // Constructor initializes the head pointer to nullptr
    SearchAndRetrieval() : head(nullptr) {}

    // Add an email to the linked list
    void addEmail(const std::string& email) {
        EmailNode* newNode = new EmailNode(email);
        newNode->next = head;
        head = newNode;
    }

    // Search emails by sender
    void searchBySender(const std::string& sender) const {
        bool found = false;
        std::cout << "Searching for emails from: " << sender << std::endl;
        EmailNode* current = head;
        while (current != nullptr) {
            if (current->email.find("From: " + sender) != std::string::npos) {
                std::cout << current->email << std::endl;
                found = true;
            }
            current = current->next;
        }
        if (!found) {
            std::cout << "No emails found from " << sender << "." << std::endl;
        }
    }

    // Search emails by subject
    void searchBySubject(const std::string& subject) const {
        bool found = false;
        std::cout << "Searching for emails with subject: " << subject << std::endl;
        EmailNode* current = head;
        while (current != nullptr) {
            if (current->email.find("Subject: " + subject) != std::string::npos) {
                std::cout << current->email << std::endl;
                found = true;
            }
            current = current->next;
        }
        if (!found) {
            std::cout << "No emails found with subject " << subject << "." << std::endl;
        }
    }

    // Search emails by date
    void searchByDate(const std::string& date) const {
        bool found = false;
        std::cout << "Searching for emails on date: " << date << std::endl;
        EmailNode* current = head;
        while (current != nullptr) {
            if (current->email.find("Date: " + date) != std::string::npos) {
                std::cout << current->email << std::endl;
                found = true;
            }
            current = current->next;
        }
        if (!found) {
            std::cout << "No emails found on " << date << "." << std::endl;
        }
    }

    // Destructor cleans up the dynamically allocated memory
    ~SearchAndRetrieval() {
        while (head) {
            EmailNode* temp = head;
            head = head->next;
            delete temp;
        }
    }
};
