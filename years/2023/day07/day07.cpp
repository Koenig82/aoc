#include "day07.h"

Y2023d07::Y2023d07(){
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

void Y2023d07::run1(){
    std::vector<Hand> hands;
    for (auto &&string : input) {
        std::vector<std::string> split = StringUtil::split(string, ' ');
        hands.push_back(Hand(stoi(split[1]),split[0]));
    }
    
    for (auto &&hand : hands) {
        std::cout << hand.bid << " : " << hand.hand << std::endl;
    }
    
}

void Y2023d07::run2(){
    std::cout << "day 07 star2" << std::endl;
}

Hand::Hand(int inBid, std::string inHand){
    bid = inBid;
    hand = inHand;
}