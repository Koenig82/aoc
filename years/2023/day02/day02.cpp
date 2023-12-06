#include "day02.h"

Y2023d02::Y2023d02(){
    std::fstream new_file;
    new_file.open("years/2023/day02/input.txt", std::ios::in); 
    
    if (new_file.is_open()) { 
        std::string string;
        while (getline(new_file, string)) { 
            input.push_back(string);
        }   
        new_file.close(); 
    }
}

void Y2023d02::run1(){
    std::cout << "ran day 1" << std::endl;
}


void Y2023d02::run2(){

}