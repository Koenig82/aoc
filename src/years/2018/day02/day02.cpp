#include "day02.h"

#include <unordered_map>

Y2018d02::Y2018d02() {
    yearSlashDay = "2018/day02";

    readInput();
}

void Y2018d02::run1() {

    std::unordered_map<char, int> counts;

    int twos = 0;
    int threes = 0;
    int twosPoint = 0;
    int threesPoint = 0;

    for (const std::string& word : input) {
        counts.clear();
        twos = 0;
        threes = 0;

        for (char character : word) {
            counts[character]++;
            if (counts[character] == 2) {
                twos++;
            }
            else if (counts[character] == 3) {
                twos--;
                threes++;
            }
            else if (counts[character] == 4) {
                threes--;
            }
        }
        if (twos > 0) {
            twosPoint++;
        }
        if (threes > 0) {
            threesPoint++;
        }
    }
    std::cout << (twosPoint * threesPoint) << std::endl;
}

#define WORD_LENGTH 26
void Y2018d02::run2() {
    std::unordered_map<std::string, std::pair<std::string, int>> greatestMatch;
    int count = 0;

    for (const std::string& word : input) {
        greatestMatch[word] = {"", 0};

        for (const std::string& compareWith : input) {
            count = 0;
            for (unsigned long long i = 0; i < word.length(); i++) {
                if (word[i] == compareWith[i]) {
                    count++;
                }
            }
            if (count > greatestMatch[word].second && count < WORD_LENGTH) {
                greatestMatch[word] = {compareWith, count};
            }
        }
    }

    int greatestScore = 0;
    std::string idA;
    std::string idB;
    std::string result;
    for (const auto& entry : greatestMatch) {
        if (entry.second.second > greatestScore) {
            greatestScore = entry.second.second;
            idA = entry.first;
            idB = entry.second.first;
        }
    }

    for (unsigned long long i = 0; i < idA.length(); i++) {
        if (idA[i] == idB[i]) {
            result += idA[i];
        }
    }

    std::cout << result << std::endl;
}