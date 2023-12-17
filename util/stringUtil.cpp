#include "stringUtil.h"

std::vector<std::string> StringUtil::split(const std::string &string,
                                           char delim) {
    std::vector<std::string> result;
    std::stringstream sstream(string);
    std::string item;

    while (getline(sstream, item, delim)) {
        if (!item.empty()) { // Omit empty strings caused by consecutive
                             // delimiters
            result.push_back(item);
        }
    }
    return result;
}

std::vector<int> StringUtil::getIntsFromString(const std::string &string) {
    std::vector<int> result;
    int numLen = 0;
    int startPos;
    for (size_t i = 0; i < string.length(); i++) {
        if (isdigit(string[i])) {
            startPos = i;
            while (isdigit(string[i])) {
                numLen++;
                i++;
            }
            result.push_back(stoi(string.substr(startPos, numLen)));
        }
    }
    return result;
}

std::vector<long long>
StringUtil::getLongLongsFromString(const std::string &string) {
    std::vector<long long> result;
    int numLen = 0;
    int startPos;
    for (size_t i = 0; i < string.length(); i++) {
        if (isdigit(string[i])) {
            startPos = i;
            while (isdigit(string[i])) {
                numLen++;
                i++;
            }
            result.push_back(stoll(string.substr(startPos, numLen)));
        }
    }
    return result;
}
