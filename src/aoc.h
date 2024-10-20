#pragma once

#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

class Aoc {
  public:
    virtual void run1() = 0;
    virtual void run2() = 0;
    virtual ~Aoc() = default;
    int start() {
        // int time = 0;
        run1();
        // run2();
        return 0;
    }

  protected:
    std::vector<std::string> input;
};