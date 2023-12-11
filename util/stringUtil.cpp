#include "stringUtil.h"

std::vector<std::string> StringUtil::split(const std::string &string,
                                           char delim) {
    std::vector<std::string> result;
    std::stringstream sstream(string);
    std::string item;

    while (getline(sstream, item, delim)) {
        result.push_back(item);
    }
    return result;
}

std::vector<int> StringUtil::getIntsFromString(const std::string &string) {
    std::vector<int> result;
    std::stringstream sstream(string);
    int number;
    std::string token;
    while (sstream >> token) {
        if (std::stringstream(token) >> std::noskipws >> number) {
            result.push_back(number);
        }
    }
    return result;
}