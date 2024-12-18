#include "day05.h"
// #include <cstddef>

Y2023d05::Y2023d05() {
    resourcePath = "2023/day05";

    readInput();
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
            seedsSoil = makeBlockAtIndex(i, 0);
        }
        if (input[i].find("soil-to-fertilizer") != std::string::npos) {
            soilFert = makeBlockAtIndex(i, 1);
        }
        if (input[i].find("fertilizer-to-water") != std::string::npos) {
            fertWater = makeBlockAtIndex(i, 2);
        }
        if (input[i].find("water-to-light") != std::string::npos) {
            waterLight = makeBlockAtIndex(i, 3);
        }
        if (input[i].find("light-to-temperature") != std::string::npos) {
            lightTemp = makeBlockAtIndex(i, 4);
        }
        if (input[i].find("temperature-to-humidity") != std::string::npos) {
            tempHum = makeBlockAtIndex(i, 5);
        }
        if (input[i].find("humidity-to-location") != std::string::npos) {
            humLoc = makeBlockAtIndex(i, 6);
        }
    }
    long long lowest = LLONG_MAX;
    long long location;
    for (auto&& number : seeds) {
        location = humLoc.calc(
            tempHum.calc(lightTemp.calc(waterLight.calc(fertWater.calc(soilFert.calc(seedsSoil.calc(number)))))));
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
        seedRanges.push_back(std::pair<long long, long long>(seeds[i], (seeds[i] + seeds[i + 1]) - 1));
    }

    std::vector<MappingBlock> mappingBlock;
    for (size_t i = 1; i < input.size(); i++) {
        if (input[i].find("seed-to-soil") != std::string::npos) {
            mappingBlock.push_back(makeBlockAtIndex(i, 0));
        }
        if (input[i].find("soil-to-fertilizer") != std::string::npos) {
            mappingBlock.push_back(makeBlockAtIndex(i, 1));
        }
        if (input[i].find("fertilizer-to-water") != std::string::npos) {
            mappingBlock.push_back(makeBlockAtIndex(i, 2));
        }
        if (input[i].find("water-to-light") != std::string::npos) {
            mappingBlock.push_back(makeBlockAtIndex(i, 3));
        }
        if (input[i].find("light-to-temperature") != std::string::npos) {
            mappingBlock.push_back(makeBlockAtIndex(i, 4));
        }
        if (input[i].find("temperature-to-humidity") != std::string::npos) {
            mappingBlock.push_back(makeBlockAtIndex(i, 5));
        }
        if (input[i].find("humidity-to-location") != std::string::npos) {
            mappingBlock.push_back(makeBlockAtIndex(i, 6));
        }
    }

    for (size_t i = 0; i < mappingBlock.size(); i++) {

        seedRanges = mappingBlock[i].calcRanges(seedRanges);
    }
    long long lowest = LLONG_MAX;
    for (auto&& range : seedRanges) {
        if (range.first < lowest) {
            lowest = range.first;
        }
    }

    std::cout << lowest << std::endl;
}

MappingBlock::MappingBlock(const std::vector<std::string>& inputs, int startindex, int endIndex, int id) {
    for (int i = startindex; i <= endIndex; i++) {
        std::vector<long long> numbers = StringUtil::getLongLongsFromString(inputs[i]);
        maps.push_back(numbers);
    }
    std::sort(maps.begin(), maps.end(), [](const auto& a, const auto& b) { return a[1] < b[1]; });
    iid = id;
}

void MappingBlock::printMaps() {
    for (auto&& vector : maps) {
        std::cout << vector[0] << " " << vector[1] << " " << vector[2] << std::endl;
    }
}

long long MappingBlock::calc(const long long in) {
    long long out = in;
    for (auto&& vec : maps) {
        if (in >= vec[1] && in < (vec[1] + vec[2])) {
            out = in + (vec[0] - vec[1]);
            break;
        }
    }
    return out;
}

#define SOURCE_END ((mapping[1] + mapping[2]) - 1)
#define SOURCE_START mapping[1]
#define MAP_DIFF (mapping[0] - mapping[1])
std::vector<std::pair<long long, long long>> MappingBlock::calcRanges(std::vector<std::pair<long long, long long>> in) {
    bool started;
    size_t mapindex;
    std::vector<std::pair<long long, long long>> out;
    for (auto&& range : in) { // for each input range:
        started = false;
        mapindex = 0;
        for (auto&& mapping : maps) {
            // bottom range is below:
            if (range.first < SOURCE_START && !started) {
                started = true;
                // Whole range is below (1 range out: same lower)
                if (range.second < SOURCE_START) {
                    out.push_back(range);
                    break;
                }
                // ends in range ( 2 range out: same lower, new)
                else if (range.second <= SOURCE_END) {
                    out.push_back(std::pair<long long, long long>(range.first, SOURCE_START - 1));
                    out.push_back(std::pair<long long, long long>(SOURCE_START + MAP_DIFF, range.second + MAP_DIFF));
                    break;
                }
                // spans over range (3 ranges out: same lower, new, cont upper)
                else {
                    out.push_back(std::pair<long long, long long>(range.first, SOURCE_START - 1));
                    out.push_back(std::pair<long long, long long>(SOURCE_START + MAP_DIFF, SOURCE_END + MAP_DIFF));
                }
            }
            // bottom range starts in range:
            else if (range.first <= SOURCE_END && !started) {
                started = true;
                // ends in range (1 range out: new)
                if (range.second <= SOURCE_END) {
                    out.push_back(std::pair<long long, long long>(range.first + MAP_DIFF, range.second + MAP_DIFF));
                    break;
                }
                // ends outside range (2 ranges out: new, cont upper)
                else {
                    out.push_back(std::pair<long long, long long>(range.first + MAP_DIFF, SOURCE_END + MAP_DIFF));
                }
            }
            // continued from last range end here (1 range new)
            else if (range.second <= SOURCE_END && started) {
                out.push_back(std::pair<long long, long long>(SOURCE_START + MAP_DIFF, range.second + MAP_DIFF));
                break;
            }
            // continued from last range span over (1 range cont)
            else if (range.second > SOURCE_END && started) {
                out.push_back(std::pair<long long, long long>(SOURCE_START + MAP_DIFF, SOURCE_END + MAP_DIFF));
            }
            // bottom range outside range (1 range out: same range)
            else if (mapindex == maps.size() - 1) {
                out.push_back(std::pair<long long, long long>(range.first, range.second));
                break;
            }
            mapindex++;
        }
    }
    return out;
}

MappingBlock Y2023d05::makeBlockAtIndex(size_t& i, int id) {
    i++;
    int startIndex = i;
    while (i < input.size() && isdigit(input[i][0])) {
        i++;
    }
    return MappingBlock(input, startIndex, i - 1, id);
}