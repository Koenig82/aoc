#pragma once
#include <vector>
#include <string>
#include <fstream>
#include <iostream>

#include "../../../aoc.h"

class Y2023d02 : public Aoc {

    public:
    Y2023d02();
    virtual ~Y2023d02() = default;

    std::vector<std::string> input;
    
    void run1() override;
    void run2() override;
    
};