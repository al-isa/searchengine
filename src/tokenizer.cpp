#include "tokenizer.h"
#include <cctype> //for is alnum (check if char is a number or letter), tolower

//Function: tokenize
//input: raw text (e.g. "The cat sat on the mat.")
//output: tokenized text in list/vector ["the", "cat", "sat", "on", "the", "mat"]
std::vector<std::string> tokenize(const std::string& text) {
    std::vector<std::string> tokens; //this will hold all words
    std::string current; //buffer for building a single word

    //loop through each charcater in text
    for(char c : text) {
        if (isalnum(c)) {
            //if its a letter or number->add a lowercase version to current word
            current += std::tolower(c);
        } else {
            //if we hit punctuation/space->finish current word(if not empty)
            if (!current.empty()){
                tokens.push_back(current); //save word
                current.clear(); //reset buffer
            }
        }
    }
    if (!current.empty()) {
        tokens.push_back(current);
    }
    return tokens;
}