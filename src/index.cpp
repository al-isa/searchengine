#include "index.h"
#include "tokenizer.h"
#include <algorithm> //for std::find
#include <unordered_set>
#include <iostream>

//add one documents token into the index
void InvertedIndex::add_document(const Document& doc) {
    auto tokens = tokenize(doc.content); //break text into words
    //track if we already added this doc for a given word
    std::unordered_set<std::string> seen_tokens;
    for (const auto& token : tokens) {
        //avoid duplicate doc IDs if word appears multiple times
        if (seen_tokens.find(token) == seen_tokens.end()) {
            index[token].push_back(doc.id);
            seen_tokens.insert(token);

            //std::cout << "Adding '" << token << "' to index for doc " << doc.id << "\n";

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