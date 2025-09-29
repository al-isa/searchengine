#ifndef TOKENIZER_H
#define TOKENIZER_H

#include <string>
#include <vector>

//decalre function that we can use later
//input: a string of text
//output: a list (vector) of clean tokens (words)
std::vector<std::string> tokenize(const std::string& text);

#endif