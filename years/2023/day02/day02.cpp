#include "day02.h"

Y2023d02::Y2023d02(){
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

void Y2023d02::run1(){
    int gameIndex = 0;
    int sum = 0;

    int red;
    int green;
    int blue;

    bool possible;
    for (auto &&string : input){
        possible = true;
        gameIndex++;
        red = 0;
        green = 0;
        blue = 0;
        std::vector<std::string> sets = Util::split(string, ';');
        for(auto &&set : sets){
            red = getAmountOfColorinSet("red", set);
            green = getAmountOfColorinSet("green", set);
            blue = getAmountOfColorinSet("blue", set);
            if(red > 12 || green > 13 || blue > 14){
                possible = false;
                break;
            }
        }
        if(possible){
            sum += gameIndex;
        }
    }
    std::cout << sum << std::endl;
}

void Y2023d02::run2(){
    int sum = 0;

    int red;
    int green;
    int blue;

    for (auto &&string : input){
        red = 0;
        green = 0;
        blue = 0;
        std::vector<std::string> sets = Util::split(string, ';');
        for(auto &&set : sets){
            if(getAmountOfColorinSet("red", set) > red){
                red = getAmountOfColorinSet("red", set);
            }
            if(getAmountOfColorinSet("green", set) > green){
                green = getAmountOfColorinSet("green", set);
            }
            if(getAmountOfColorinSet("blue", set) > blue){
                blue = getAmountOfColorinSet("blue", set);
            }
        }
        sum += (red*green*blue);

    }
    std::cout << sum << std::endl;
}

int Y2023d02::getAmountOfColorinSet(std::string color, std::string& set){
    std::string::size_type pos = 0;
    std::string numberString;
    while ((pos = set.find(color, pos )) != std::string::npos) {
          break;
    }
    if(pos == std::string::npos){
        return 0;
    }else{
        if(isdigit(set.substr(pos-3)[0])){
            if(isdigit(set.substr(pos-4)[0])){
                numberString = set.substr(pos-4, 3);
            }else{
                numberString = set.substr(pos-3, 2);
            }
        }else{
            numberString = set.substr(pos-2, 1);
        }
    }
    return stoi(numberString);
}