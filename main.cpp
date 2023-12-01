#include <iostream>
#include <vector>
#include <string>
#include <fstream>

#include "main.h"

int main(int argc, char const *argv[]) {
    
    std::vector<std::string> input;

    std::fstream new_file;
    // open a file to perform read operation using file object.
    new_file.open("years/2023/day01/input.txt", std::ios::in); 
    
    // Checking whether the file is open.
    if (new_file.is_open()) { 
        std::string string;
        // Read data from the file object and put it into a string.
        while (getline(new_file, string)) { 
            // Print the data of the string.
            input.push_back(string);
        }   
        // Close the file object.
        new_file.close(); 
    }

    for (auto &&string : input){
        std::cout << string << std::endl;
    }
 
    

    y2023d01 y2023d01{};
    //run();
    return 0;
}


