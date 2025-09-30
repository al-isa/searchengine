#ifndef INDEX_H
#define INDEX_H

#include <string>
#include <vector>
#include <unordered_map>
#include "document.h"

//InvertedIndex Structure
struct InvertedIndex {
    //Dictionary word->list of doc IDS
    std::unordered_map<std::string, std::vector<int>> index;

    //add one document to index
    void add_document(const Document& doc);

    //search for word->return doc ids
    std::vector<int> search(const std::string& term);
};

#endif