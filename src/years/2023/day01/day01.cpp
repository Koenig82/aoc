#include "day01.h"

// TODO fix a general implementation of this at aoc.h
Y2023d01::Y2023d01() {
    std::fstream new_file;
    std::filesystem::path path("resources/Y2023d01/input.txt");
    new_file.open(path, std::ios::in);
    if (new_file.is_open()) {
        std::string string;
        while (getline(new_file, string)) {
            input.push_back(string);
        }
        new_file.close();
    }
}

void Y2023d01::run1() {

    std::regex numbers("(\\d)");
    std::smatch match;

    int numberA;
    int numberB;
    int sum = 0;
    for (auto&& string : input) {
        std::sregex_iterator iter(string.begin(), string.end(), numbers);
        std::sregex_iterator end;
        bool foundfirst = false;
        while (iter != end) {
            std::smatch match = *iter;
            if (!foundfirst) {
                foundfirst = true;
                numberA = stoi(match.str()) * 10;
            }
            if (++iter == end) {
                numberB = stoi(match.str());
                sum += (numberA + numberB);
            }
        }
    }
    std::cout << sum << std::endl;
    return;
};

void Y2023d01::run2() {

    int numberA;
    int numberB;
    int sum = 0;

    for (auto&& string : input) {
        for (int i = 0; i < (int)string.length(); ++i) {
            std::string subStr = string.substr(i, 5);
            if (isdigit(subStr[0])) {
                numberA = charToInt(subStr[0]) * 10;
                i = string.length();
                continue;
            } else {
                switch (subStr[0]) {
                case 'o':
                    if (subStr.compare(0, 3, "one") == 0) {
                        numberA = 1 * 10;
                        i = string.length();
                        continue;
                    }
                    break;
                case 't':
                    if (subStr.compare(0, 3, "two") == 0) {
                        numberA = 2 * 10;
                        i = string.length();
                        continue;
                    } else if (subStr.compare(0, 5, "three") == 0) {
                        numberA = 3 * 10;
                        i = string.length();
                        continue;
                    }
                    break;
                case 'f':
                    if (subStr.compare(0, 4, "four") == 0) {
                        numberA = 4 * 10;
                        i = string.length();
                        continue;
                    } else if (subStr.compare(0, 4, "five") == 0) {
                        numberA = 5 * 10;
                        i = string.length();
                        continue;
                    }
                    break;
                case 's':
                    if (subStr.compare(0, 3, "six") == 0) {
                        numberA = 6 * 10;
                        i = string.length();
                        continue;
                    } else if (subStr.compare(0, 5, "seven") == 0) {
                        numberA = 7 * 10;
                        i = string.length();
                        continue;
                    }
                    break;
                case 'e':
                    if (subStr.compare(0, 5, "eight") == 0) {
                        numberA = 8 * 10;
                        i = string.length();
                        continue;
                    }
                    break;
                case 'n':
                    if (subStr.compare(0, 4, "nine") == 0) {
                        numberA = 9 * 10;
                        i = string.length();
                        continue;
                    }
                    break;
                }
            }
        }
        for (int i = string.length(); i > 0; --i) {
            std::string subStr = string.substr(i - 1, i + 5);
            if (isdigit(subStr[0])) {
                numberB = charToInt(subStr[0]);
                i = -1;
                continue;
            } else {
                if (subStr.length() < 3) {
                    // Handle cases where substring length is less than 3 (near the beginning of the string)
                    continue;
                }
                switch (subStr[0]) {
                case 'o':
                    if (subStr.compare(0, 3, "one") == 0) {
                        numberB = 1;
                        i = -1;
                        continue;
                    }
                    break;
                case 't':
                    if (subStr.compare(0, 3, "two") == 0) {
                        numberB = 2;
                        i = -1;
                        continue;
                    } else if (subStr.compare(0, 5, "three") == 0) {
                        numberB = 3;
                        i = -1;
                        continue;
                    }
                    break;
                case 'f':
                    if (subStr.compare(0, 4, "four") == 0) {
                        numberB = 4;
                        i = -1;
                        continue;
                    } else if (subStr.compare(0, 4, "five") == 0) {
                        numberB = 5;
                        i = -1;
                        continue;
                    }
                    break;
                case 's':
                    if (subStr.compare(0, 3, "six") == 0) {
                        numberB = 6;
                        i = -1;
                        continue;
                    } else if (subStr.compare(0, 5, "seven") == 0) {
                        numberB = 7;
                        i = -1;
                        continue;
                    }
                    break;
                case 'e':
                    if (subStr.compare(0, 5, "eight") == 0) {
                        numberB = 8;
                        i = -1;
                        continue;
                    }
                    break;
                case 'n':
                    if (subStr.compare(0, 4, "nine") == 0) {
                        numberB = 9;
                        i = -1;
                        continue;
                    }
                    break;
                    break;
                }
            }
        }

        sum += (numberA + numberB);
    }
    std::cout << sum << std::endl;
    return;
};

int Y2023d01::charToInt(char c) {

    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    return arr[c - '0'];
}
