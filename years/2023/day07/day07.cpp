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
        hand.calculateScore();
        std::cout << hand.bid << " : " << hand.hand << " score: " << hand.score << std::endl;
    }
    
}

void Y2023d07::run2(){
    std::cout << "day 07 star2" << std::endl;
}

Hand::Hand(int inBid, std::string inHand){
    for (auto &&character : inHand)
    {
        if(cardTypes.contains(character)){
            cardTypes[character]++;
        }else{
            cardTypes.insert(std::pair<char, int>(character, 1));
        }
    }
    
    bid = inBid;
    hand = inHand;
}

void Hand::calculateScore(){
    for (const auto& cardtype : cardTypes) {
        switch (cardtype.second)
        {
        case 5:
            //five of a kind
            if(score < 7){
                score = 7;
            }
            break;
        case 4:
            // four of a kind
            if(score < 6){
                score = 6;
            }
            break;
        case 3:
            // full house
            if(score < 5 && pair){
                score = 5;
            // three of a kind
            }else if(score < 4){
                score = 4;
            }
            three = true;
            break;
        case 2:
            // full house
            if(score < 5 && three){
                score = 5;
            // two pairs
            }else if(score < 3 && pair){
                score = 3;
            //pair
            }else if(score < 2){
                score = 2;
            }
            pair = true;
            break;
        case 1:
            // high card
            if(score < 1){
                score = 1;
            }
            break;
        default:
            break;
        }
    }   
}