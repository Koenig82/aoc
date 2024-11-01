#include "day01.h"
#include <unordered_set>

Y2018d01::Y2018d01() {
    resourcePath = "2018/day01";

    readInput();
}

void Y2018d01::run1() {

    int sum = 0;
    for (std::string line : input) {
        sum += stoi(line);
    }
    std::cout << sum << std::endl;

    return;
}

void Y2018d01::run2() {
    std::unordered_set<int> results;
    results.insert(0);
    int sum = 0;
    int numberAsInt = 0;
    while (true) {
        for (const auto& numberAsString : input) {
            numberAsInt = std::stoi(numberAsString);
            sum += numberAsInt;
            if (!results.insert(sum).second) {
                std::cout << sum << std::endl;
                return;
            }
        }
    }
}
