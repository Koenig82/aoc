#include "day03.h"

#include "../../../util/stringUtil.h"

#include <set>

Y2018d03::Y2018d03() {
    yearSlashDay = "2018/day03";

    readInput();
}

void Y2018d03::run1() {
    std::cout << "day 03 star 1" << std::endl;

    int** cloth = new int*[1000];
    for (int i = 0; i < 1000; i++) {
        cloth[i] = new int[1000]();
    }

    int overlapcount = 0;

    for (std::string& line : input) {
        std::vector<std::string> substrings = StringUtil::split(line, ' ');

        int id = std::stoi(substrings[0].substr(1));

        std::vector<std::string> coordsubs = StringUtil::split(substrings[2], ',');
        int startFromX = std::stoi(coordsubs[0]);
        int startFromY = std::stoi(coordsubs[1].substr(0, coordsubs[1].find(":")));

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

    for (int i = 0; i < 1000; i++) {
        delete[] cloth[i];
    }
    delete[] cloth;

    std::cout << overlapcount << std::endl;
}

void Y2018d03::run2() {

    int** cloth = new int*[1000];
    for (int i = 0; i < 1000; i++) {
        cloth[i] = new int[1000]();
    }
    std::set<int> candidates;

    for (std::string& line : input) {

        std::vector<std::string> substrings = StringUtil::split(line, ' ');

        int id = std::stoi(substrings[0].substr(1));
        candidates.insert(id);

        std::vector<std::string> coordsubs = StringUtil::split(substrings[2], ',');
        int startFromX = std::stoi(coordsubs[0]);
        int startFromY = std::stoi(coordsubs[1].substr(0, coordsubs[1].find(":")));

        std::vector<std::string> sizesubs = StringUtil::split(substrings[3], 'x');
        int sizeX = std::stoi(sizesubs[0]);
        int sizeY = std::stoi(sizesubs[1]);

        for (int x = startFromX; x < sizeX + startFromX; x++) {
            for (int y = startFromY; y < sizeY + startFromY; y++) {
                if (cloth[x][y] == 0) {
                    cloth[x][y] = id;
                }
                else if (cloth[x][y] != -1) {
                    candidates.erase(cloth[x][y]);
                    candidates.erase(id);
                    cloth[x][y] = -1;
                }
                else {
                    candidates.erase(id);
                    candidates.erase(cloth[x][y]);
                }
            }
        }
    }

    for (int i = 0; i < 1000; i++) {
        delete[] cloth[i];
    }
    delete[] cloth;

    for (int s : candidates) {
        std::cout << s << std::endl;
    }
}