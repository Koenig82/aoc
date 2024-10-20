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

    void readInput() {
        std::fstream new_file;
        std::filesystem::path path("resources/" + yearSlashDay + "/input.txt");
        new_file.open(path, std::ios::in);
        if (new_file.is_open()) {
            std::string string;
            while (getline(new_file, string)) {
                input.push_back(string);
            }
            new_file.close();
        }
    }
    int start() {
        auto start1 = std::chrono::high_resolution_clock::now();
        run1();
        auto end1 = std::chrono::high_resolution_clock::now();
        auto duration1 = std::chrono::duration_cast<std::chrono::nanoseconds>(end1 - start1);
        std::cout << "star 1 took " << duration1.count() << " nanoseconds\n";

        auto start2 = std::chrono::high_resolution_clock::now();
        run2();
        auto end2 = std::chrono::high_resolution_clock::now();
        auto duration2 = std::chrono::duration_cast<std::chrono::nanoseconds>(end2 - start2);
        std::cout << "star 2 took " << duration2.count() << " nanoseconds\n";
        return 0;
    }

  protected:
    std::string yearSlashDay;
    std::vector<std::string> input;
};