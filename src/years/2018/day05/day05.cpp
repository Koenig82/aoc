#include "day05.h"

#include <cstring>

Y2018d05::Y2018d05() {
    resourcePath = "2018/day05";

    readInput();
}

void Y2018d05::run1() {
    int size = this->input[0].length() + 1;
    std::vector<char> input;
    input.resize(size);
    std::copy(this->input[0].begin(), this->input[0].end(), input.begin());
    std::cout << "Result: " << reactPolymers(input) << std::endl;
}

void Y2018d05::run2() { std::cout << "Not implemented" << std::endl; }

int Y2018d05::reactPolymers(std::vector<char>& array) {

    bool done = false;
    int removeCount = 0;
    while (!done) {
        done = true;
        removeCount = 0;
        for (int i = 0; i < (int)array.size() - 1; i++) {
            if ((int)array[i] == (int)array[i + 1] - 32 || (int)array[i] == (int)array[i + 1] + 32) {
                done = false;
                array[i] = ' ';
                array[i + 1] = ' ';
                removeCount += 2;
            }
        }
        array = removeBlanks(array, removeCount);
    }
    return array.size();
}

std::vector<char> Y2018d05::removeBlanks(std::vector<char>& array, int removeCount) {
    int j = 0;
    std::vector<char> newArray(array.size() - removeCount + 1);
    for (int i = 0, j = 0; i < (int)array.size(); i++) {
        if (array[i] == ' ') {
        }
        else {
            newArray[j++] = array[i];
        }
    }
    newArray[j] = '\0';
    return newArray;
}