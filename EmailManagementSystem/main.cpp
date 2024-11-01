#include <iostream>
#include <fstream>
#include <sstream>
#include "Inbox.hpp"
#include "Outbox.hpp"
#include "SpamDetector.hpp"
#include "PriorityQueue.hpp"
#include "QueueLinkedList.hpp" // Include your QueueLinkedList definition

using namespace std;

// Function to load emails from a CSV file
void loadEmailsFromFile(const std::string& filename, Inbox& inbox, Outbox& outbox, SpamDetector& spamFilter, PriorityQueue& priorityQueue) {
    std::ifstream file(filename);
    std::string line;

    if (!file.is_open()) {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return;
    }

    // Skip header line
    std::getline(file, line);

    // Read each line from the file
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string emailID, type, priorityLevel, content;

        // Extract fields by splitting the line with a comma
        std::getline(ss, emailID, ',');
        std::getline(ss, type, ',');
        std::getline(ss, priorityLevel, ',');
        std::getline(ss, content, ',');

        // Assign emails to the appropriate data structure based on their type and priority
        if (type == "Inbox") {
            if (priorityLevel == "High") {
                inbox.receiveEmail(content + " [High Priority]");
            }
            else if (priorityLevel == "Normal") {
                inbox.receiveEmail(content + " [Normal Priority]");
            }
            else {
                inbox.receiveEmail(content + " [Low Priority]");
            }
        }
        else if (type == "Outbox") {
            outbox.sendEmail(content);
        }
        else if (type == "Spam") {
            spamFilter.markSpam(content);
        }
        else if (type == "Priority") {
            priorityQueue.addHighPriority(content + " [Priority]");
        }
    }

    file.close();
}

int main() {
    Inbox inbox;
    Outbox outbox;
    SpamDetector spamFilter;
    PriorityQueue priorityQueue;

    // Load emails from the CSV file
    loadEmailsFromFile("emails.csv", inbox, outbox, spamFilter, priorityQueue);

    // Display the contents of each category
    cout << "Inbox:\n";
    inbox.showInbox();

    cout << "\nOutbox:\n";
    outbox.showOutbox();

    cout << "\nSpam:\n";
    spamFilter.showSpam();

    cout << "\nPriority:\n";
    priorityQueue.showPriority();

    return 0;
}
