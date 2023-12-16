#include "day06.h"

Y2023d06::Y2023d06() {
    std::fstream new_file;
    std::filesystem::path path(__FILE__);
    path.replace_filename("input.txt");
    new_file.open(path, std::ios::in);
    if (new_file.is_open()) {
        std::string string;
        while (getline(new_file, string)) {
            input.push_back(string);
        }
        new_file.close();
    }
}

void Y2023d06::run1() {
    std::vector<int> recordTimes = StringUtil::getIntsFromString(input[0]);
    std::vector<int> recordDistances = StringUtil::getIntsFromString(input[1]);

    for (auto &&time : recordTimes) {
        std::cout << time << std::endl;
    }
    for (auto &&dist : recordDistances) {
        std::cout << dist << std::endl;
    }
    int raceSum = 1;
    for (size_t i = 0; i < recordDistances.size(); i++) {
        std::cout << "race " << i << std::endl;
        raceSum *= calcNumberOfWays(recordTimes[i], recordDistances[i]);
    }
    std::cout << raceSum << std::endl;
};

void Y2023d06::run2() { std::cout << "star 2" << std::endl; };

int Y2023d06::calcNumberOfWays(int time, int distance) {
    int numberOfWays = 0;
    for (int speed = 0; speed < distance; speed++) {
        if (speed * (time - speed) > distance) {
            numberOfWays++;
        }
    }

    return numberOfWays;
}