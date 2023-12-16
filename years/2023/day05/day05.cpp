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
    std::vector<long long> seeds = StringUtil::getLongLongsFromString(input[0]);

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
    long long lowest = LLONG_MAX;
    long long location;
    for (auto &&number : seeds) {
        location = humLoc.calc(tempHum.calc(lightTemp.calc(waterLight.calc(
            fertWater.calc(soilFert.calc(seedsSoil.calc(number)))))));
        std::cout << location << std::endl;
        if (location < lowest) {
            lowest = location;
        }
    }
    std::cout << lowest << std::endl;
}

void Y2023d05::run2() {

    std::vector<long long> seeds = StringUtil::getLongLongsFromString(input[0]);
    std::vector<std::pair<long long, long long>> seedRanges;
    for (size_t i = 0; i < seeds.size(); i += 2) {
        seedRanges.push_back(
            std::pair<long long, long long>(seeds[i], seeds[i] + seeds[i + 1]));
    }
    std::cout << "Original seeds" << std::endl;
    for (auto &&range : seedRanges) {
        std::cout << range.first << " " << range.second << std::endl;
    }
    std::vector<MappingBlock> blocks;
    for (size_t i = 1; i < input.size(); i++) {
        if (input[i].find("seed-to-soil") != std::string::npos) {
            blocks.push_back(makeBlockAtIndex(i));
        }
        if (input[i].find("soil-to-fertilizer") != std::string::npos) {
            blocks.push_back(makeBlockAtIndex(i));
        }
        if (input[i].find("fertilizer-to-water") != std::string::npos) {
            blocks.push_back(makeBlockAtIndex(i));
        }
        if (input[i].find("water-to-light") != std::string::npos) {
            blocks.push_back(makeBlockAtIndex(i));
        }
        if (input[i].find("light-to-temperature") != std::string::npos) {
            blocks.push_back(makeBlockAtIndex(i));
        }
        if (input[i].find("temperature-to-humidity") != std::string::npos) {
            blocks.push_back(makeBlockAtIndex(i));
        }
        if (input[i].find("humidity-to-location") != std::string::npos) {
            blocks.push_back(makeBlockAtIndex(i));
        }
    }
    // std::vector<std::pair<long long, long long>> resultRanges;
    // std::vector<std::pair<long long, long long>> intermediateRanges;
    // for (auto &&seed : seedRanges) {
    //     intermediateRanges = blocks[0].calcRanges(seed);
    //     resultRanges.insert(resultRanges.end(), intermediateRanges.begin(),
    //                         intermediateRanges.end());
    // }
    // seedRanges = resultRanges;
    // resultRanges.clear();
    // for (auto &&block : blocks) {
    //     block.printMaps();
    //     std::cout << " " << std::endl;
    // }
    // seedRanges.resize(1); // Keeps only the first element
    std::vector<std::pair<long long, long long>> resultRanges;
    std::vector<std::pair<long long, long long>> intermediateRanges;
    for (size_t i = 0; i < blocks.size(); i++) {
        for (auto &&seed : seedRanges) {
            intermediateRanges = blocks[i].calcRanges(seed);
            resultRanges.insert(resultRanges.end(), intermediateRanges.begin(),
                                intermediateRanges.end());
        }
        seedRanges = resultRanges;
        resultRanges.clear();
    }

    // std::vector<std::pair<long long, long long>> resultRanges;
    // std::vector<std::pair<long long, long long>> intermediateRanges;
    // for (size_t i = 0; i < blocks.size(); i++) {
    //     for (auto &&seed : seedRanges) {
    //         intermediateRanges = blocks[i].calcRanges(seed);
    //         resultRanges.insert(resultRanges.end(),
    //         intermediateRanges.begin(),
    //                             intermediateRanges.end());
    //     }
    //     seedRanges = resultRanges;
    //     resultRanges.clear();
    // }

    std::cout << "Ranges fter mapping" << std::endl;
    for (auto &&range : seedRanges) {
        std::cout << range.first << " " << range.second << std::endl;
    }
    // long long lowest = LLONG_MAX;
    // long long location;
    // for (auto &&number : seeds) {
    //     location = humLoc.calc(tempHum.calc(lightTemp.calc(waterLight.calc(
    //         fertWater.calc(soilFert.calc(seedsSoil.calc(number)))))));
    //     if (location < lowest) {
    //         lowest = location;
    //     }
    // }
    // std::cout << lowest << std::endl;
}

MappingBlock::MappingBlock(const std::vector<std::string> &inputs,
                           int startindex, int endIndex) {
    for (int i = startindex; i <= endIndex; i++) {
        std::vector<long long> numbers =
            StringUtil::getLongLongsFromString(inputs[i]);
        maps.push_back(numbers);
    }
    std::sort(maps.begin(), maps.end(),
              [](const auto &a, const auto &b) { return a[1] < b[1]; });
}

void MappingBlock::printMaps() {
    for (auto &&vector : maps) {
        std::cout << vector[0] << " " << vector[1] << " " << vector[2]
                  << std::endl;
    }
}

long long MappingBlock::calc(const long long in) {
    long long out = in;
    for (auto &&vec : maps) {
        if (in >= vec[1] && in < (vec[1] + vec[2])) {
            out = in + (vec[0] - vec[1]);
            break;
        }
    }
    return out;
}
#define MAX_RANGE (vec[1] + vec[2])
#define LOW_RANGE vec[1]
#define MAP_TO_ADD (vec[0] - vec[1])
std::vector<std::pair<long long, long long>>
MappingBlock::calcRanges(std::pair<long long, long long> in) {
    std::vector<std::pair<long long, long long>> out;
    long long start;
    long long end;
    bool withinAnyRange = false;
    size_t i = 0;
    for (auto &&vec : maps) {
        // Bottom range is below
        std::cout << "if in first(" << in.first << ") < Low range(" << LOW_RANGE
                  << ")"
                  << ", "
                  << "current max = " << MAX_RANGE << std::endl;
        if (in.first < LOW_RANGE && in.second >= LOW_RANGE) {
            withinAnyRange = true;
            start = LOW_RANGE + MAP_TO_ADD;
            // spans over range
            if (in.second > MAX_RANGE) {
                end = MAX_RANGE + MAP_TO_ADD;
                // ends in range
            } else {
                end = in.second + MAP_TO_ADD;
            }
            out.push_back(
                std::pair<long long, long long>(in.first, LOW_RANGE - 1));
            out.push_back(std::pair<long long, long long>(start, end));
            // bottom range is in current range
        } else if (in.first >= LOW_RANGE && in.first < MAX_RANGE) {
            withinAnyRange = true;
            start = in.first + MAP_TO_ADD;
            // spans over range
            if (in.second > MAX_RANGE) {
                end = MAX_RANGE + MAP_TO_ADD;
                if (i == maps.size() - 1) {
                    out.push_back(
                        std::pair<long long, long long>(MAX_RANGE, in.second));
                }
                // ends in range
            } else {
                end = in.second + MAP_TO_ADD;
            }
            out.push_back(std::pair<long long, long long>(start, end));
        }
        i++;
    }
    if (!withinAnyRange) {
        out.push_back(in);
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