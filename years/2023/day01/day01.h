#include "../../../aoc.h"
#include <regex>
#include <ctype.h>
#include <unordered_map>
#include <string.h>

class Y2023d01 : public Aoc {

    public:
    const std::unordered_map<std::string, int> string_to_case{
        {"one", 1},
        {"two", 2},
        {"three", 3},
        {"four", 4},
        {"five", 5},
        {"six", 6},
        {"seven", 7},
        {"eight", 8},
        {"nine", 9}
    };
    int get_number_from_string(std::string string);
    std::vector<std::string> input;
    Y2023d01();
    
    void run1() override;

    void run2() override;

    int charToInt(char c);

};