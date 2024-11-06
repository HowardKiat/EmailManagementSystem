#include <iostream>
#include <fstream>
#include <sstream>
#include "Inbox.hpp"
#include "Outbox.hpp"
#include "SpamDetector.hpp"
#include "PriorityQueue.hpp"
#include "SearchAndRetrieval.hpp"

using namespace std;

void loadEmailsFromFile(const string& filename, Inbox& inbox, Outbox& outbox, SpamDetector& spamFilter, PriorityQueue& priorityQueue, SearchAndRetrieval& searchAndRetrieve) {
    ifstream file(filename);
    string line;

    if (!file.is_open()) {
        cerr << "Error: Could not open file " << filename << endl;
        return;
    }

    getline(file, line);  // Skip header line

    while (getline(file, line)) {
        stringstream ss(line);
        string id, sender, recipient, subject, content, priority;

        getline(ss, id, ',');  // Assuming CSV format uses commas
        getline(ss, sender, ',');
        getline(ss, recipient, ',');
        getline(ss, subject, ',');
        getline(ss, content, ',');
        getline(ss, priority, ',');

        string email = "From: " + sender + ", To: " + recipient + ", Subject: " + subject + ", Content: " + content;
        int priorityLevel = stoi(priority);

        // Spam detection based on keywords
        if (content.find("discount") != string::npos || content.find("prize") != string::npos || content.find("offer") != string::npos) {
            spamFilter.markSpam(email);
        }
        else if (priorityLevel == 1) {
            priorityQueue.addHighPriority(email, priorityLevel);
        }
        else {
            inbox.receiveEmail(email);
            outbox.sendEmail(email);
        }

        searchAndRetrieve.addEmail(email);
    }

    file.close();
}

int main() {
    Inbox inbox;
    Outbox outbox;
    SpamDetector spamFilter;
    PriorityQueue priorityQueue;
    SearchAndRetrieval searchAndRetrieve;

    loadEmailsFromFile("emails.csv", inbox, outbox, spamFilter, priorityQueue, searchAndRetrieve);

    int choice;
    while (true) {
        cout << "\nEmail Management System\n";
        cout << "1. View Inbox\n2. Send Email\n3. View Outbox\n4. View Priority Emails\n5. View Spam\n6. Search Email by Sender\n7. Search Email by Subject\n8. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Inbox:\n";
            inbox.showInbox();
            break;
        case 2: {
            string sender, recipient, subject, content;
            cout << "Enter sender: ";
            cin.ignore(); // To clear the input buffer
            getline(cin, sender);
            cout << "Enter recipient: ";
            getline(cin, recipient);
            cout << "Enter subject: ";
            getline(cin, subject);
            cout << "Enter content: ";
            getline(cin, content);

            string email = "From: " + sender + ", To: " + recipient + ", Subject: " + subject + ", Content: " + content;
            inbox.receiveEmail(email);
            outbox.sendEmail(email);
            cout << "Email sent successfully!\n";
            break;
        }
        case 3:
            cout << "Outbox:\n";
            outbox.showOutbox();
            break;
        case 4:
            cout << "Priority Emails:\n";
            priorityQueue.showPriority();
            break;
        case 5:
            cout << "Spam Emails:\n";
            spamFilter.showSpam();
            break;
        case 6: {
            string sender;
            cout << "Enter sender email: ";
            cin >> sender;
            searchAndRetrieve.searchBySender(sender);
            break;
        }
        case 7: {
            string subject;
            cout << "Enter email subject: ";
            cin.ignore();
            getline(cin, subject);
            searchAndRetrieve.searchBySubject(subject);
            break;
        }
        case 8:
            cout << "Exiting the system.\n";
            return 0;
        default:
            cout << "Invalid choice. Try again.\n";
            break;
        }
    }

    return 0;
}
