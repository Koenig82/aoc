#pragma once

#include "../../../aoc.h"
#include "../../../util/util.h"

class Y2023d02 : public Aoc {

    public:
    Y2023d02();
    virtual ~Y2023d02() = default;

    void run1() override;
    void run2() override;
    
    int getAmountOfColorinSet(std::string, std::string& set);
};