#include <iostream> //for std::cout printing
#include "document.h"
#include "tokenizer.h"
#include "index.h"

//forward declare our function since its already decalred in docment.cpp
Document load_document(const std::string& filepath, int id);

int main() {
    //load 3 text file into memory
    Document doc1 = load_document("../data/doc1.txt", 1);
    Document doc2 = load_document("../data/doc2.txt", 2);
    Document doc3 = load_document("../data/doc3.txt", 3);


    //print the contents of each document just to check if it worked
    // std::cout << "Doc1 contents: " << doc1.content << "\n";
    // std::cout << "Doc2 contents: " << doc2.content << "\n";
    // std::cout << "Doc3 contents: " << doc3.content << "\n";

    //tokenize its contents
    std::vector<std::string> tokens = tokenize(doc1.content);

    //print the tokens
    std::cout << "Tokens from Doc1:" << std::endl;
    for (const auto& t : tokens) { 
        std::cout << t << " "; //create a space between each token
    }

    std::cout << std::endl;

    //tokenize its contents
    tokens = tokenize(doc2.content);

    //print the tokens
    std::cout << "Tokens from Doc2:" << std::endl;
    for (const auto& t : tokens) { 
        std::cout << t << " "; //create a space between each token
    }
    std::cout << std::endl;

    //tokenize its contents
    tokens = tokenize(doc3.content);

    //print the tokens
    std::cout << "Tokens from Doc3:" << std::endl;
    for (const auto& t : tokens) { 
        std::cout << t << " "; //create a space between each token
    }
    std::cout << std::endl;

    //create inverted index
    InvertedIndex idx;
    idx.add_document(doc1);
    idx.add_document(doc2);
    idx.add_document(doc3);

    //search test
    std::string query = "mat";
    auto results = idx.search(query);

    std::cout << "Search Results for '" << query << "': ";
    for (int id : results) {
        std::cout << id << " ";
    }
    std::cout << std::endl;

    return 0;
}