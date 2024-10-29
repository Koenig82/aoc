#include "day03.h"

#include "../../../util/stringUtil.h"

Y2018d03::Y2018d03() {
    yearSlashDay = "2018/day03";

    readInput();
}

void Y2018d03::run1() {
    std::cout << "asdf" << std::endl;
    int cloth[1000][1000];
    int overlapcount = 0;
    for (auto&& string : input) {
        std::cout << string << std::endl;
    }
    for (std::string& line : input) {

        std::vector<std::string> substrings = StringUtil::split(line, ' ');
        int id = std::stoi(substrings[0].substr(1));
        std::vector<std::string> coordsubs = StringUtil::split(substrings[2], ',');
        int startFromX = std::stoi(coordsubs[0]);
        int startFromY = std::stoi(substrings[0].substr(0, coordsubs[1].find(":")));

        std::vector<std::string> sizesubs = StringUtil::split(substrings[3], 'x');
        int sizeX = std::stoi(sizesubs[0]);
        int sizeY = std::stoi(sizesubs[1]);

        for (int x = startFromX; x < sizeX + startFromX; x++) {
            for (int y = startFromY; y < sizeY + startFromY; y++) {
                if (cloth[x][y] == 0) {
                    cloth[x][y] = id;
                }
                else if (cloth[x][y] != -1) {
                    cloth[x][y] = -1;
                    overlapcount++;
                }
            }
        }
    }
    std::cout << "Result = " << overlapcount << "" << std::endl;
}

void Y2018d03::run2() { std::cout << "not implemented" << std::endl; }
