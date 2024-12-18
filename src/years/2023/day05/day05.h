#pragma once

#include <algorithm>

#include "../../../aoc.h"
#include "../../../util/stringUtil.h"

class MappingBlock {
  public:
    int iid;
    std::vector<std::vector<long long>> maps;
    MappingBlock(const std::vector<std::string>& inputs, int startindex, int endIndex, int id);
    MappingBlock() : maps(){};
    ~MappingBlock() = default;

    void printMaps();
    long long calc(const long long in);
    std::vector<std::pair<long long, long long>> calcRanges(std::vector<std::pair<long long, long long>> in);
};

class Y2023d05 : public Aoc {

  public:
    Y2023d05();
    virtual ~Y2023d05() = default;

    void run1() override;
    void run2() override;

    MappingBlock makeBlockAtIndex(size_t& i, int id);
};