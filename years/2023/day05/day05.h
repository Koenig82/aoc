#pragma once

#include "../../../aoc.h"
#include "../../../util/stringUtil.h"

class MappingBlock {
  public:
    std::vector<std::vector<int>> maps;
    MappingBlock(const std::vector<std::string> &inputs, int startindex,
                 int endIndex);
    MappingBlock() : maps(){};
    ~MappingBlock() = default;

    void printMaps();
    int calc(const int in);
};

class Y2023d05 : public Aoc {

  public:
    Y2023d05();
    virtual ~Y2023d05() = default;

    void run1() override;
    void run2() override;

    MappingBlock makeBlockAtIndex(size_t &i);
};