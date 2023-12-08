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
    std::vector<int> numbers;
    for(size_t i = 0; i < input.size(); i++){
        std::vector<int> vec = findConnectedNumbersInInputIndexString(i);
        numbers.insert(std::end(numbers), std::begin(vec), std::end(vec));
    }

}

void Y2023d03::run2(){

 
}


std::vector<int> Y2023d03::findConnectedNumbersInInputIndexString(int rowIndex){
    std::vector<int> result;
    
    
    if(rowIndex == 0){
        for(int i = 0; i < input[rowIndex].size(); i++){
            bool numberIsConnected = false;
            if(isdigit(input[rowIndex][i])){
                if(i > 0){
                    if(isSpecialChar(input[rowIndex+1][i-1])){

                    }
                }
                
                while(isdigit(input[rowIndex][i])){
                    i++; // checka raden under på varje sen kanske diagonalerna utanför while
                    //kanske diagonalerna före innan while och andra diagonalerna efter while
                }
            }
        }         
    }
    return result;
}

bool Y2023d03::isSpecialChar(const char character){
    if(!isdigit(character) && character != '.'){
        return true;
    }else{
        return false;
    }
}