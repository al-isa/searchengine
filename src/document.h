#ifndef DOCUMENT_H //prevents double including this file
#define DOCUMENT_H

#include <string> //for std::string to store text

//simple struct to represent document
struct Document {
    int id;
    std::string content; //raw text in document
};

#endif