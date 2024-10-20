#include "day01.h"

Y2018d01::Y2018d01() {
    std::fstream new_file;
    std::filesystem::path path("resources/Y2018d01/input.txt");
    new_file.open(path, std::ios::in);
    if (new_file.is_open()) {
        std::string string;
        while (getline(new_file, string)) {
            input.push_back(string);
        }
        new_file.close();
    }
}

void Y2018d01::run1() { std::cout << "day 01 star 1" << std::endl; }
void Y2018d01::run2() { std::cout << "day 01 star 2" << std::endl; }