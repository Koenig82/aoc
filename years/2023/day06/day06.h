#pragma once

#include "../../../aoc.h"
#include "../../../util/stringUtil.h"

class Y2023d06 : public Aoc {

  public:
    Y2023d06();
    virtual ~Y2023d06() = default;

    void run1() override;
    void run2() override;

    int calcNumberOfWays(int time, int distance);
    long long calcNumberOfWaysLarge(long long time, long long distance);
    long long calcNumberOfWaysLargeGPT(long long time, long long distance);
};