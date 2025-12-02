#include "day01.h"
#include <functional>
#include <string>

// TODO fix a general implementation of this at aoc.h
Y2025d01::Y2025d01() {
    resourcePath = "2025/day01";

    readInput();
}

void Y2025d01::run1() {
    int zeroes = 0;
    int dial = 50;

    for (std::string line : input) {
        std::cout << line + "\n";
        int number = std::stoi(line.substr(1));
        if (line.at(0) == 'L') {
            dial -= number;
        }
        else {
            dial += number;
        }
        dial = (dial % 100);

        if (dial == 0) {
            zeroes++;
        }
        std::cout << "Dial is now: " + std::to_string(dial) + "\n";
    }
    std::cout << "Number of zeroes: " << std::to_string(zeroes) + "\n";
    std::cout << (-5) % 100 << "\n";
    return;
}

void Y2025d01::run2() {
    std::cout << "Not implemented\n";

    return;
}