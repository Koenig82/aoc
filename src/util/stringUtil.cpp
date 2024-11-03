#include "stringUtil.h"

/**
 * Splits a string into a vector of strings using a delimiter.
 * @param string The string to split.
 * @param delim The character to use as the delimiter.
 * @return A vector of strings, split from the input string.
 */
std::vector<std::string> StringUtil::split(const std::string& string, char delim) {
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

/**
 * Extracts all the integers from a string and returns them as a vector.
 * Each integer must be a sequence of consecutive digits.
 * @param string The string to search for integers in.
 * @return A vector of all the integers found in the string.
 */
std::vector<int> StringUtil::getIntsFromString(const std::string& string) {
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

/**
 * Extracts all the long longs from a string and returns them as a vector.
 * Each long long must be a sequence of consecutive digits.
 * @param string The string to search for long longs in.
 * @return A vector of all the long longs found in the string.
 */
std::vector<long long> StringUtil::getLongLongsFromString(const std::string& string) {
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
