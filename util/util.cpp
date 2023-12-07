#include "util.h"

std::vector<std::string> Util::split(const std::string &string, char delim){
    std::vector<std::string> result;
    std::stringstream ss (string);
    std::string item;

    while (getline(ss, item, delim)) {
        result.push_back (item);
    }
    return result;
}