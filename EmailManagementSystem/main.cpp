#include <iostream>
#include <fstream>
#include <ctime>
#include "Inbox.hpp"
#include "Outbox.hpp"
#include "SpamDetector.hpp"
#include "PriorityQueue.hpp"
#include "SearchAndRetrieval.hpp"

using namespace std;

// Function to load emails from a CSV file and categorize them
void loadEmailsFromFile(const string& filename, Inbox& inbox, Outbox& outbox, SpamDetector& spamFilter, PriorityQueue& priorityQueue, SearchAndRetrieval& searchAndRetrieve) {
    ifstream file(filename);
    string line;

    if (!file.is_open()) {
        cerr << "Error: Could not open file " << filename << endl;
        return;
    }

    getline(file, line);  // Skip header line

    while (getline(file, line)) {
        size_t pos = 0;
        string fields[8];
        int index = 0;

        // Extract fields based on commas
        while ((pos = line.find(',')) != string::npos && index < 8) {
            fields[index++] = line.substr(0, pos);
            line.erase(0, pos + 1);
        }
        fields[index] = line;  // Last field

        string id = fields[0];
        string sender = fields[1];
        string recipient = fields[2];
        string subject = fields[3];
        string content = fields[4];
        string priority = fields[5];
        string date = (index >= 6) ? fields[6] : "N/A";
        string time = (index >= 7) ? fields[7] : "N/A";

        string email = "From: " + sender + ", To: " + recipient + ", Subject: " + subject + ", Content: " + content + ", Date: " + date + ", Time: " + time;
        int priorityLevel;
        try {
            priorityLevel = stoi(priority);
        }
        catch (invalid_argument& e) {
            cerr << "Invalid priority level for email: " << email << endl;
            continue;
        }

        // Spam detection and priority handling with hardcoded spam words
        if (content.find("free") != string::npos ||
            content.find("win") != string::npos ||
            content.find("congratulations") != string::npos ||
            content.find("limited time offer") != string::npos ||
            content.find("urgent") != string::npos ||
            content.find("act now") != string::npos ||
            content.find("winner") != string::npos ||
            content.find("claim") != string::npos ||
            content.find("click here") != string::npos ||
            content.find("exclusive") != string::npos ||
            content.find("100% free") != string::npos ||
            content.find("guaranteed") != string::npos ||
            content.find("discount") != string::npos ||
            content.find("offer expires") != string::npos ||
            content.find("risk-free") != string::npos ||
            content.find("money-back guarantee") != string::npos ||
            content.find("no obligation") != string::npos ||
            content.find("order now") != string::npos ||
            content.find("promise you") != string::npos ||
            content.find("apply now") != string::npos ||
            content.find("buy direct") != string::npos ||
            content.find("credit card required") != string::npos ||
            content.find("amazing") != string::npos ||
            content.find("investment") != string::npos ||
            content.find("deal") != string::npos ||
            content.find("winning") != string::npos) {
            spamFilter.markSpam(email);
        }
        else if (priorityLevel == 1) {
            priorityQueue.addImportantEmail(email, priorityLevel);
        }
        else {
            priorityQueue.addGeneralEmail(email);
            inbox.receiveEmail(email);
        }

        searchAndRetrieve.addEmail(email);
    }

    file.close();
}

// Function to print a divider line
void printDivider() {
    cout << "------------------------------------------------------------\n";
}

int main() {
    // Initialize system components
    Inbox inbox;
    Outbox outbox;
    SpamDetector spamFilter;
    PriorityQueue priorityQueue;
    SearchAndRetrieval searchAndRetrieve;

    // Load emails from CSV file
    loadEmailsFromFile("emails.csv", inbox, outbox, spamFilter, priorityQueue, searchAndRetrieve);

    int choice;
    while (true) {
        cout << "\n======================== Email Management System ========================\n";
        printDivider();
        cout << "1. View Inbox\n2. Send Email\n3. View Outbox\n4. View Important Emails\n5. View General Emails\n6. View Spam\n7. Search Email by Sender\n8. Search Email by Subject\n9. Search Email by Date\n10. Exit\n";
        printDivider();

        // Input validation
        cout << "Enter your choice (1-10): ";
        cin >> choice;

        // Check if the input failed (non-integer or special character input)
        if (cin.fail()) {
            cout << "Invalid input. Please enter a number between 1 and 9.\n";
            cin.clear();  // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Ignore the invalid input
            continue;  // Go back to the start of the loop
        }

        switch (choice) {
        case 1:
            cout << "\n----- Inbox -----\n";
            inbox.showInbox();
            printDivider();
            break;
        case 2: {
            string sender, recipient, subject, content;
            cout << "\n----- Send New Email -----\n";
            cout << "Enter sender: ";
            cin.ignore();
            getline(cin, sender);
            cout << "Enter recipient: ";
            getline(cin, recipient);
            cout << "Enter subject: ";
            getline(cin, subject);
            cout << "Enter content: ";
            getline(cin, content);

            // Get current date and time
            time_t now = time(0);
            tm ltm;
            localtime_s(&ltm, &now);  // Use localtime_s instead of localtime

            string date = to_string(ltm.tm_mon + 1) + "/" + to_string(ltm.tm_mday) + "/" + to_string(1900 + ltm.tm_year);
            string time = to_string(ltm.tm_hour) + ":" + to_string(ltm.tm_min);

            string email = "From: " + sender + ", To: " + recipient + ", Subject: " + subject + ", Content: " + content + ", Date: " + date + ", Time: " + time;
            outbox.sendEmail(email);
            searchAndRetrieve.addEmail(email);
            cout << "Email sent successfully!\n";
            printDivider();
            break;
        }
        case 3:
            cout << "\n----- Outbox -----\n";
            outbox.showOutbox();
            printDivider();
            break;
        case 4:
            cout << "\n----- Important Emails -----\n";
            priorityQueue.showImportantEmails();
            printDivider();
            break;
        case 5:
            cout << "\n----- General Emails -----\n";
            priorityQueue.showGeneralEmails();
            printDivider();
            break;
        case 6:
            cout << "\n----- Spam Emails -----\n";
            spamFilter.showSpam();
            printDivider();
            break;
        case 7: {
            string sender;
            cout << "Enter sender name to search: ";
            cin.ignore();
            getline(cin, sender);
            searchAndRetrieve.searchBySender(sender);
            printDivider();
            break;
        }
        case 8: {
            string subject;
            cout << "Enter subject to search: ";
            cin.ignore();
            getline(cin, subject);
            searchAndRetrieve.searchBySubject(subject);
            printDivider();
            break;
        }
        case 9: {
            string date;
            cout << "\nEnter date (dd-mm-yyyy) to search for: ";
            cin.ignore();
            getline(cin, date);
            searchAndRetrieve.searchByDate(date);
            printDivider();
            break;
        }
        case 10:
            cout << "Exiting program. Goodbye!" << endl;
            return 0;
        default:
            cout << "Invalid choice! Please try again." << endl;
        }
    }
    return 0;
}