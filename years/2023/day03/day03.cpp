#include "day03.h"

Y2023d03::Y2023d03(){
    std::fstream new_file;
    std::filesystem::path path(__FILE__);
    path.replace_filename("input.txt");
    new_file.open(path, std::ios::in); 
    if (new_file.is_open()) { 
        std::string string;
        while (getline(new_file, string)) { 
            input.push_back(string);
        }   
        new_file.close(); 
    }
}

void Y2023d03::run1(){
    std::cout << "dsfgsdgf" << std::endl;


}

void Y2023d03::run2(){


    
}