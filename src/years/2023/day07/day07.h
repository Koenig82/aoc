#pragma once

#include "../../../aoc.h"
#include "../../../util/stringUtil.h"
#include <map>

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
    std::map<char,int> cardTypes;
    std::string hand;
    int score = 0;
    bool three = false;
    bool pair = false;

    Hand(int inBid, std::string inHand);
    ~Hand() = default;

    void calculateScore();
};