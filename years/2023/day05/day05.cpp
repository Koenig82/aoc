#include "day05.h"

Y2023d05::Y2023d05() {
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

void Y2023d05::run1() { std::cout << "sadgdg" << std::endl; }

void Y2023d05::run2() {}