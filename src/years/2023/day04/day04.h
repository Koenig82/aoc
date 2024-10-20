#pragma once

#include <algorithm>

#include "../../../aoc.h"
#include "../../../util/stringUtil.h"

class Y2023d04 : public Aoc {
  public:
    Y2023d04();
    virtual ~Y2023d04() = default;

    void run1() override;
    void run2() override;
};

class Ticket {
  public:
    std::vector<int> winners;
    std::vector<int> numbers;
    Ticket(std::vector<int> winNums, std::vector<int> nums);
};