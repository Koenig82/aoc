#pragma once

#include "../../../aoc.h"
#include "../../../util/matrixUtil.h"

class Y2023d03 : public Aoc {

    public:
    Y2023d03();
    virtual ~Y2023d03() = default;

    void run1() override;
    void run2() override;

    std::vector<int> findConnectedNumbersInInputIndexString(int rowIndex);
    bool isSpecialChar(const char character);
};