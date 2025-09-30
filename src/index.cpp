#include "index.h"
#include "tokenizer.h"
#include <algorithm> //for std::find

//add one documents token into the index
void InvertedIndex::add_document(const Document& doc) {
    auto tokens = tokenize(doc.content); //break text into words
    for (const auto& token : tokens) {
        //avoid duplicate doc IDs if word appears multiple times
        if (index[token].empty() || index[token].back() != doc.id) {
            index[token].push_back(doc.id);
        }
    }
}

//search for a single word
std::vector<int> InvertedIndex::search(const std::string& term) {
    if (index.find(term) != index.end()) {
        return index[term]; //return list of doc ids
    }
    return {}; //empty vector if word is not found
}