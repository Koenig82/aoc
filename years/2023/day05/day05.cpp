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

void Y2023d05::run1() {
    std::vector<int> seeds = StringUtil::getIntsFromString(input[0]);

    for (auto &&number : seeds) {
        std::cout << number << std::endl;
    }
    int startIndex;
    MappingBlock seedsSoil;
    for (size_t i = 1; i < input.size(); i++) {
        if (input[i].find("seed-to-soil") != std::string::npos) {
            i++;
            startIndex = i;
            while (isdigit(input[i][0])) {
                i++;
            }
            seedsSoil = MappingBlock(input, startIndex, i);
        }
    }

    seedsSoil.printMaps();
}

void Y2023d05::run2() {}

MappingBlock::MappingBlock(const std::vector<std::string> &inputs,
                           int startindex, int endIndex) {
    for (int i = startindex; i <= endIndex; i++) {
        std::vector<int> numbers = StringUtil::getIntsFromString(inputs[i]);
        maps.push_back(numbers);
    }
}

void MappingBlock::printMaps() {
    for (auto &&vector : maps) {
        std::cout << vector[0] << vector[1] << vector[2] << std::endl;
    }
}