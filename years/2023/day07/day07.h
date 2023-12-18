#pragma once

#include "../../../aoc.h"
#include "../../../util/stringUtil.h"

class Y2023d07 : public Aoc {

    public:
    Y2023d07();
    virtual ~Y2023d07() = default;

    void run1() override;
    void run2() override;

};

class Hand{
    public:
    int bid;
    std::string hand;

    Hand(int inBid, std::string inHand);
    ~Hand() = default;
};