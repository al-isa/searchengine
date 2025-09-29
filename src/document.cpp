#include "document.h"
#include <fstream> //file input
#include <sstream> //reading file into string
#include <iostream>

//Function: load_document
//Parameters:
//   - filepath: the location of the text file
//   - id: an integer ID to assign to this document
//Returns:
//   - A Document object containing the file’s contents
Document load_document(const std::string& filepath, int id){
    std::ifstream file(filepath); //open file for reading

    if(!file.is_open()){ //error handling, quick check if file path is correct
        std::cerr << "Error: Could not open file " << filepath << std::endl;
        return {id, ""}; 
    }

    std::stringstream buffer; //lets us stream the file into memory


    buffer << file.rdbuf(); //read the whole file into the buffer
    // file.rdbuf() = raw stream buffer of the file

    //return document with id an text
    return{id, buffer.str()};
}