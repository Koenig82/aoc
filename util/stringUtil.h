#pragma once

#include <sstream>
#include <string>
#include <vector>

class StringUtil {
  public:
    static std::vector<std::string> split(const std::string &string,
                                          char delim);
    static std::vector<int> getIntsFromString(const std::string &string);
};