#pragma once
#include "StackLinkedList.hpp"

class SearchAndRetrieval {
private:
    StackLinkedList searchResults;

public:
    void addSearchResult(string email);
    void showSearchResults();
};

void SearchAndRetrieval::addSearchResult(string email) {
    searchResults.push(email);
}

void SearchAndRetrieval::showSearchResults() {
    searchResults.displayStack();
}
