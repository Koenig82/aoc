#pragma once

#include <chrono>
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
        std::filesystem::path path("resources/" + resourcePath + "/input.txt");
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

        std::chrono::high_resolution_clock::time_point start;
        std::chrono::high_resolution_clock::time_point end;

        start = std::chrono::high_resolution_clock::now();
        run1();
        end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> duration1 =
            std::chrono::duration_cast<std::chrono::duration<double, std::milli>>(end - start);
        std::cout << "star 1 took " << duration1.count() << " milliseconds\n";

        start = std::chrono::high_resolution_clock::now();
        run2();
        end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> duration2 =
            std::chrono::duration_cast<std::chrono::duration<double, std::milli>>(end - start);
        std::cout << "star 2 took " << duration2.count() << " milliseconds\n";
        return 0;
    }

  protected:
    std::string resourcePath;
    std::vector<std::string> input;
};