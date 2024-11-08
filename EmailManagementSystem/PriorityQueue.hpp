#pragma once
#include <iostream>
#include <queue>
#include <string>

class PriorityQueue {
private:
    std::priority_queue<std::pair<int, std::string>> importantEmails;
    std::queue<std::string> generalEmails;

public:
    // "IMPORTANT EMAILS"
    void addImportantEmail(const std::string& email, int priority) {
        importantEmails.push(std::make_pair(priority, email));
        std::cout << "Added to Important Emails with priority " << priority << ": " << email << std::endl;
    }

    // "GENERAL EMAILS"
    void addGeneralEmail(const std::string& email) {
        generalEmails.push(email);
        std::cout << "Added to General Emails: " << email << std::endl;
    }

    // Method to display important emails (highest priority first - Priority 1)
    void showImportantEmails() const {
        if (importantEmails.empty()) {
            std::cout << "No important emails.\n";
        }
        else {
            std::cout << "Displaying important emails:\n";
            auto tempQueue = importantEmails;  // Create a copy of the priority queue
            while (!tempQueue.empty()) {
                std::cout << "Priority " << tempQueue.top().first << ": "
                    << tempQueue.top().second << std::endl;
                tempQueue.pop();
            }
        }
    }

    // Display GENERAL EMAILS
    void showGeneralEmails() const {
        if (generalEmails.empty()) {
            std::cout << "No general emails.\n";
        }
        else {
            std::cout << "Displaying general emails:\n";
            auto tempQueue = generalEmails;  // Create a copy of the queue
            while (!tempQueue.empty()) {
                std::cout << tempQueue.front() << std::endl;
                tempQueue.pop();
            }
        }
    }
};
