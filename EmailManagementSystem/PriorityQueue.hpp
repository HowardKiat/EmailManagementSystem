#pragma once
#include <iostream>
#include <queue>
#include <string>

class PriorityQueue {
private:
    std::priority_queue<std::pair<int, std::string>> priorityEmails;

public:
    // Method to add an email with a high priority (priority is the first parameter)
    void addHighPriority(const std::string& email, int priority) {
        priorityEmails.push(std::make_pair(priority, email));
    }

    // Method to show priority emails
    void showPriority() const {
        if (priorityEmails.empty()) {
            std::cout << "No priority emails.\n";
        }
        else {
            std::cout << "Displaying priority emails:\n";
            // Creating a temporary queue to preserve the original queue
            std::priority_queue<std::pair<int, std::string>> tempQueue = priorityEmails;
            while (!tempQueue.empty()) {
                std::cout << "Priority " << tempQueue.top().first << ": "
                    << tempQueue.top().second << std::endl;
                tempQueue.pop();
            }
        }
    }
};
