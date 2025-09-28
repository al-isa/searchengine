#include <iostream> //for std::cout printing
#include "document.h"

//forward declare our function since its already decalred in docment.cpp
Document load_document(const std::string& filepath, int id);

int main() {
    //load 3 text file into memory
    Document doc1 = load_document("../data/doc1.txt", 1);
    Document doc2 = load_document("../data/doc2.txt", 1);
    Document doc3 = load_document("../data/doc3.txt", 1);

    //print the contents of each document just to check if it worked
    std::cout << "Doc1 contents: " << doc1.content << "\n";
    std::cout << "Doc2 contents: " << doc2.content << "\n";
    std::cout << "Doc3 contents: " << doc3.content << "\n";

    return 0;
}