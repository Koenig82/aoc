#pragma once

#include "../../../aoc.h"

class Y2018d05 : public Aoc {

  public:
    Y2018d05();
    virtual ~Y2018d05() = default;

    void run1() override;
    void run2() override;

    int reactPolymers(std::vector<char>& array);
    std::vector<char> removeBlanks(std::vector<char>& array, int removeCount);
};