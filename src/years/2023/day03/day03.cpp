#include "day03.h"

Y2023d03::Y2023d03() {
    std::fstream new_file;
    std::filesystem::path path("resources/Y2023d03/input.txt");
    new_file.open(path, std::ios::in);
    if (new_file.is_open()) {
        std::string string;
        while (getline(new_file, string)) {
            input.push_back(string);
        }
        new_file.close();
    }
}

void Y2023d03::run1() {
    std::vector<int> numbers;
    int sum = 0;
    for (size_t i = 0; i < input.size(); i++) {
        std::vector<int> vec = findConnectedNumbersInInputIndexString(i);
        numbers.insert(std::end(numbers), std::begin(vec), std::end(vec));
    }
    for (auto&& number : numbers) {
        sum += number;
    }
    std::cout << sum << std::endl;
}

void Y2023d03::run2() {
    std::vector<int> numbers;
    std::unordered_map<GearPos, std::vector<int>> gearmap;
    int sum = 0;

    gearmap = findGearNumbersInStringIndex();

    for (const auto& pair : gearmap) {
        // std::cout << "Key: " << pair.first << ", Value: " << pair.second
        //           << std::endl;
        if (pair.second.size() == 2) {
            sum += pair.second.at(0) * pair.second.at(1);
        }
    }
    std::cout << sum << std::endl;
}

std::vector<int> Y2023d03::findConnectedNumbersInInputIndexString(size_t rowIndex) {
    std::vector<int> result;
    int startpos;
    bool addnumber = false;
    if (rowIndex == 0) {
        for (size_t i = 0; i < input[rowIndex].size(); i++) {
            if (isdigit(input[rowIndex][i])) {
                startpos = i;
                if (i > 0 && (isSpecialChar(input[rowIndex + 1][i - 1]) || isSpecialChar(input[rowIndex][i - 1]))) {
                    addnumber = true;
                }
                while (i + 1 < input[rowIndex].length() && isdigit(input[rowIndex][i + 1])) {
                    if (isSpecialChar(input[rowIndex + 1][i + 1])) {
                        addnumber = true;
                    }
                    i++;
                }
                if (isSpecialChar(input[rowIndex + 1][startpos])) {
                    addnumber = true;
                }
                if (i < input[rowIndex].length() - 1 &&
                    (isSpecialChar(input[rowIndex + 1][i + 1]) || isSpecialChar(input[rowIndex][i + 1]))) {
                    addnumber = true;
                }
                if (addnumber) {
                    result.push_back(stoi(input[rowIndex].substr(startpos, i + 1)));
                    addnumber = false;
                }
            }
        }
    } else if (rowIndex == input.size() - 1) {
        for (size_t i = 0; i < input[rowIndex].size(); i++) {
            if (isdigit(input[rowIndex][i])) {
                startpos = i;
                if (i > 0 && (isSpecialChar(input[rowIndex - 1][i - 1]) || isSpecialChar(input[rowIndex][i - 1]))) {
                    addnumber = true;
                }
                while (i + 1 < input[rowIndex].length() && isdigit(input[rowIndex][i + 1])) {
                    if (isSpecialChar(input[rowIndex - 1][i + 1])) {
                        addnumber = true;
                    }
                    i++;
                }
                if (isSpecialChar(input[rowIndex - 1][startpos])) {
                    addnumber = true;
                }
                if (i < input[rowIndex].length() - 1 &&
                    (isSpecialChar(input[rowIndex - 1][i + 1]) || isSpecialChar(input[rowIndex][i + 1]))) {
                    addnumber = true;
                }
                if (addnumber) {
                    result.push_back(stoi(input[rowIndex].substr(startpos, i + 1)));
                    addnumber = false;
                }
            }
        }
    } else {
        for (size_t i = 0; i < input[rowIndex].size(); i++) {
            if (isdigit(input[rowIndex][i])) {
                startpos = i;
                if (i > 0 && (isSpecialChar(input[rowIndex - 1][i - 1]) || isSpecialChar(input[rowIndex + 1][i - 1]) ||
                              isSpecialChar(input[rowIndex][i - 1]))) {
                    addnumber = true;
                }
                while (i + 1 < input[rowIndex].length() && isdigit(input[rowIndex][i + 1])) {
                    if (isSpecialChar(input[rowIndex - 1][i + 1]) || isSpecialChar(input[rowIndex + 1][i + 1])) {
                        addnumber = true;
                    }
                    i++;
                }
                if (isSpecialChar(input[rowIndex - 1][startpos]) || isSpecialChar(input[rowIndex + 1][startpos])) {
                    addnumber = true;
                }
                if (i < input[rowIndex].length() - 1 &&
                    (isSpecialChar(input[rowIndex - 1][i + 1]) || isSpecialChar(input[rowIndex + 1][i + 1]) ||
                     isSpecialChar(input[rowIndex][i + 1]))) {
                    addnumber = true;
                }
                if (addnumber) {
                    result.push_back(stoi(input[rowIndex].substr(startpos, i + 1)));
                    addnumber = false;
                }
            }
        }
    }

    return result;
}

std::unordered_map<Y2023d03::GearPos, std::vector<int>> Y2023d03::findGearNumbersInStringIndex() {
    std::unordered_map<GearPos, std::vector<int>> result;
    int startpos;
    bool addnumber = false;
    int gearRow;
    int gearCol;
    for (size_t rowIndex = 0; rowIndex < input.size(); rowIndex++) {
        if (rowIndex == 0) {
            for (size_t i = 0; i < input[rowIndex].size(); i++) {
                if (isdigit(input[rowIndex][i])) {
                    startpos = i;
                    if (i > 0 && isGear(input[rowIndex + 1][i - 1])) {
                        addnumber = true;
                        gearRow = rowIndex + 1;
                        gearCol = i - 1;
                    }
                    if (i > 0 && isGear(input[rowIndex][i - 1])) {
                        addnumber = true;
                        gearRow = rowIndex;
                        gearCol = i - 1;
                    }
                    while (i + 1 < input[rowIndex].length() && isdigit(input[rowIndex][i + 1])) {
                        if (isGear(input[rowIndex + 1][i + 1])) {
                            addnumber = true;
                            gearRow = rowIndex + 1;
                            gearCol = i + 1;
                        }
                        i++;
                    }
                    if (isGear(input[rowIndex + 1][startpos])) {
                        addnumber = true;
                        gearRow = rowIndex + 1;
                        gearCol = startpos;
                    }
                    if (i < input[rowIndex].length() - 1 && isGear(input[rowIndex + 1][i + 1])) {
                        addnumber = true;
                        gearRow = rowIndex + 1;
                        gearCol = i + 1;
                    }
                    if (isGear(input[rowIndex][i + 1])) {
                        addnumber = true;
                        gearRow = rowIndex;
                        gearCol = i + 1;
                    }
                    if (addnumber) {
                        auto it = result.find(GearPos(gearRow, gearCol));
                        if (it != result.end()) {
                            it->second.push_back(stoi(input[rowIndex].substr(startpos, i + 1)));
                        } else {
                            std::vector<int> newValue = {stoi(input[rowIndex].substr(startpos, i + 1))};
                            result[GearPos(gearRow, gearCol)] = newValue;
                        }
                        addnumber = false;
                    }
                }
            }
        } else if (rowIndex == input.size() - 1) {
            for (size_t i = 0; i < input[rowIndex].size(); i++) {
                if (isdigit(input[rowIndex][i])) {
                    startpos = i;
                    if (i > 0 && isGear(input[rowIndex - 1][i - 1])) {
                        addnumber = true;
                        gearRow = rowIndex - 1;
                        gearCol = i - 1;
                    }
                    if (isGear(input[rowIndex][i - 1])) {
                        addnumber = true;
                        gearRow = rowIndex;
                        gearCol = i - 1;
                    }
                    while (i + 1 < input[rowIndex].length() && isdigit(input[rowIndex][i + 1])) {
                        if (isGear(input[rowIndex - 1][i + 1])) {
                            addnumber = true;
                            gearRow = rowIndex - 1;
                            gearCol = i + 1;
                        }
                        i++;
                    }
                    if (isGear(input[rowIndex - 1][startpos])) {
                        addnumber = true;
                        gearRow = rowIndex - 1;
                        gearCol = startpos;
                    }
                    if (i < input[rowIndex].length() - 1 && isGear(input[rowIndex - 1][i + 1])) {
                        addnumber = true;
                        gearRow = rowIndex - 1;
                        gearCol = i + 1;
                    }
                    if (isGear(input[rowIndex][i + 1])) {
                        addnumber = true;
                        gearRow = rowIndex;
                        gearCol = i + 1;
                    }
                    if (addnumber) {
                        auto it = result.find(GearPos(gearRow, gearCol));
                        if (it != result.end()) {
                            it->second.push_back(stoi(input[rowIndex].substr(startpos, i + 1)));
                        } else {
                            std::vector<int> newValue = {stoi(input[rowIndex].substr(startpos, i + 1))};
                            result[GearPos(gearRow, gearCol)] = newValue;
                        }
                        addnumber = false;
                    }
                }
            }
        } else {
            for (size_t i = 0; i < input[rowIndex].size(); i++) {
                if (isdigit(input[rowIndex][i])) {
                    startpos = i;
                    if (i > 0 && isGear(input[rowIndex - 1][i - 1])) {
                        addnumber = true;
                        gearRow = rowIndex - 1;
                        gearCol = i - 1;
                    }
                    if (isGear(input[rowIndex + 1][i - 1])) {
                        addnumber = true;
                        gearRow = rowIndex + 1;
                        gearCol = i - 1;
                    }
                    if (isGear(input[rowIndex][i - 1])) {
                        addnumber = true;
                        gearRow = rowIndex;
                        gearCol = i - 1;
                    }
                    while (i + 1 < input[rowIndex].length() && isdigit(input[rowIndex][i + 1])) {
                        if (isGear(input[rowIndex - 1][i + 1])) {
                            addnumber = true;
                            gearRow = rowIndex - 1;
                            gearCol = i + 1;
                        }
                        if (isGear(input[rowIndex + 1][i + 1])) {
                            addnumber = true;
                            gearRow = rowIndex + 1;
                            gearCol = i + 1;
                        }
                        i++;
                    }
                    if (isGear(input[rowIndex - 1][startpos])) {
                        addnumber = true;
                        gearRow = rowIndex - 1;
                        gearCol = startpos;
                    }
                    if (isGear(input[rowIndex + 1][startpos])) {
                        addnumber = true;
                        gearRow = rowIndex + 1;
                        gearCol = startpos;
                    }
                    if (i < input[rowIndex].length() - 1 && isGear(input[rowIndex - 1][i + 1])) {
                        addnumber = true;
                        gearRow = rowIndex - 1;
                        gearCol = i + 1;
                    }
                    if (isGear(input[rowIndex + 1][i + 1])) {
                        addnumber = true;
                        gearRow = rowIndex + 1;
                        gearCol = i + 1;
                    }
                    if (isGear(input[rowIndex][i + 1])) {
                        addnumber = true;
                        gearRow = rowIndex;
                        gearCol = i + 1;
                    }
                    if (addnumber) {
                        auto it = result.find(GearPos(gearRow, gearCol));
                        if (it != result.end()) {
                            it->second.push_back(stoi(input[rowIndex].substr(startpos, i + 1)));
                        } else {
                            std::vector<int> newValue = {stoi(input[rowIndex].substr(startpos, i + 1))};
                            result[GearPos(gearRow, gearCol)] = newValue;
                        }
                        addnumber = false;
                    }
                }
            }
        }
    }

    return result;
}

int Y2023d03::addNumbersAroundGear(const size_t gearPosRow, const int gearPosCol) {
    int i = 0;
    int startPos;
    if (gearPosRow == 0) {
    } else if (gearPosRow == input.size() - 1) {
    } else {
        if (gearPosCol > 0 && isdigit(input[gearPosRow - 1][gearPosCol - 1])) {
            if (gearPosCol > 1 && isdigit(input[gearPosRow - 1][gearPosCol - 2])) {
                std::cout << "there is backwards search from top left" << std::endl;
                while (gearPosCol - 1 - i > 0 && isdigit(input[gearPosRow - 1][gearPosCol - 1 - i])) {
                    i++;
                }
                startPos = gearPosCol - i;
                std::cout << input[gearPosRow - 1].substr(startPos, i) << std::endl;
                i = 0;
            } else {
                std::cout << "there is forward search from top left" << std::endl;
                while (isdigit(input[gearPosRow - 1][gearPosCol - 1 + i])) {
                    std::cout << "is digit:" << input[gearPosRow - 1][gearPosCol - 1 + i] << std::endl;
                    i++;
                }
                startPos = gearPosCol - 1;
                std::cout << input[gearPosRow - 1].substr(startPos, i) << std::endl;
                i = 0;
            }
        } else if (gearPosCol > 0 && isdigit(input[gearPosRow - 1][gearPosCol])) {
            std::cout << "there is forward search from top" << std::endl;
            while (isdigit(input[gearPosRow - 1][gearPosCol + i])) {
                std::cout << "is digit:" << input[gearPosRow - 1][gearPosCol + i] << std::endl;
                i++;
            }
            startPos = gearPosCol;
            std::cout << input[gearPosRow - 1].substr(startPos, i) << std::endl;
            i = 0;
        } else if (gearPosCol > 0 && isdigit(input[gearPosRow - 1][gearPosCol + 1])) {
            std::cout << "there is forward search from top right" << std::endl;
            while (isdigit(input[gearPosRow - 1][gearPosCol + 1 + i])) {
                std::cout << "is digit:" << input[gearPosRow - 1][gearPosCol + 1 + i] << std::endl;
                i++;
            }
            startPos = gearPosCol + 1;
            std::cout << input[gearPosRow - 1].substr(startPos, i) << std::endl;
            i = 0;
        }
    }

    return 0;
}

bool Y2023d03::isSpecialChar(const char character) {
    if (!isdigit(character) && character != '.') {
        return true;
    } else {
        return false;
    }
}

bool Y2023d03::isGear(const char character) { return character == '*'; }

Y2023d03::GearPos::GearPos(int inRow, int inCol) {
    row = inRow;
    col = inCol;
}