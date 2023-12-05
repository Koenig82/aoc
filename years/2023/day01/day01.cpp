#include "../../../aoc.h"
#include <regex>

class Y2023d01 : public Aoc {

public:
    std::vector<std::string> input;
    Y2023d01(){
        
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
    }
    
    void run1() override{

        std::regex numbers("(\\d)");
        std::smatch match;
        
        int numberA;
        int numberB;
        int sum = 0;
        for (auto &&string : input){
            std::sregex_iterator iter(string.begin(), string.end(), numbers);
            std::sregex_iterator end;
            bool foundfirst = false;
            while (iter != end) {
                std::smatch match = *iter;
                if(!foundfirst) {
                    foundfirst = true;
                    numberA = stoi(match.str())*10;
                }
                if(++iter == end) {
                    numberB = stoi(match.str());
                    sum += (numberA + numberB);
                }

            }
            std::cout << sum << std::endl;
        }
        return;
    };

    void run2() override{
        //|one|two|three|four|five|six|seven|eight|nine
        std::regex numbers("^[^\\d]*(\\d)?.*(\\d).*");
        std::smatch matches;

        int number = 0;
        int sum = 0;
        for (auto &&string : input){
            if(std::regex_search(string, matches, numbers)) {
                if(matches[1].length() == 0){
                    number = stoi(matches[matches.size()-1].str() + matches[matches.size()-1].str());
                    sum += number;
                }else{
                    number = stoi(matches[1].str() + matches[matches.size()-1].str());
                    sum += number;
                }    
            }
        }
        std::cout << sum << std::endl;
        return;
    };

};

