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
        std::cout << number << " ";
    }
    std::cout << std::endl;
    std::cout << " " << std::endl;

    MappingBlock seedsSoil;
    MappingBlock soilFert;
    MappingBlock fertWater;
    MappingBlock waterLight;
    MappingBlock lightTemp;
    MappingBlock tempHum;
    MappingBlock humLoc;
    for (size_t i = 1; i < input.size(); i++) {
        if (input[i].find("seed-to-soil") != std::string::npos) {
            seedsSoil = makeBlockAtIndex(i);
        }
        if (input[i].find("soil-to-fertilizer") != std::string::npos) {
            soilFert = makeBlockAtIndex(i);
        }
        if (input[i].find("fertilizer-to-water") != std::string::npos) {
            fertWater = makeBlockAtIndex(i);
        }
        if (input[i].find("water-to-light") != std::string::npos) {
            waterLight = makeBlockAtIndex(i);
        }
        if (input[i].find("light-to-temperature") != std::string::npos) {
            lightTemp = makeBlockAtIndex(i);
        }
        if (input[i].find("temperature-to-humidity") != std::string::npos) {
            tempHum = makeBlockAtIndex(i);
        }
        if (input[i].find("humidity-to-location") != std::string::npos) {
            humLoc = makeBlockAtIndex(i);
        }
    }
    int test = seedsSoil.calc(79);
    std::cout << test << std::endl;
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
        std::cout << vector[0] << " " << vector[1] << " " << vector[2]
                  << std::endl;
    }
}

int MappingBlock::calc(const int in) {
    int out;
    for (auto &&vec : maps) {
        if (in >= vec[1] && in < (vec[1] + vec[2])) {
            out = in + (vec[0] - vec[1]);
        } else {
            out = in;
        }
    }
    return out;
}

MappingBlock Y2023d05::makeBlockAtIndex(size_t &i) {
    i++;
    int startIndex = i;
    while (i < input.size() && isdigit(input[i][0])) {
        i++;
    }
    return MappingBlock(input, startIndex, i - 1);
}

// if x >= a && x < a+c
//   x = a + (b-a)
// else x = a