#pragma once
#include <regex>

#include "../../../aoc.h"


class Y2023d01 : public Aoc {

    public:
    Y2023d01();
    virtual ~Y2023d01() = default;

    void run1() override;
    void run2() override;

    int charToInt(char c);

};