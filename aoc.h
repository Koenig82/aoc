#pragma once

#include <vector>
#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>

class Aoc {
public:
    virtual void run1() = 0;
    virtual void run2() = 0;
    virtual ~Aoc() = default;
    int start() {
        //int time = 0;
        run2();
        return 0;
    }
    std::vector<std::string> input;
};