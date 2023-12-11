#include "day04.h"

Y2023d04::Y2023d04() {
    std::fstream new_file;
    std::filesystem::path path(__FILE__);
    path.replace_filename("input.txt");
    new_file.open(path, std::ios::in);
    if (new_file.is_open()) {
        std::string string;
        while (getline(new_file, string)) {
            input.push_back(string);
        }
        new_file.close();
    }
}

void Y2023d04::run1() {
    int points = 0;
    int startPos;
    int numberlength = 0;
    for (auto &&string : input) {
        numberlength = 0;
        std::vector<std::string> ticket = Util::split(string, '|');
        std::size_t pos = string.find(':');
        if (pos != std::string::npos) {
            std::cout << "Getting pos of : " << pos << '\n';
        }
        std::vector<std::string> winNums =
            Util::split(ticket[0].substr(7), ' ');
        std::vector<int> winnersInt;
        // for (auto &&string : winNums) {
        //     winnersInt.push_back(stoi(string));
        // }
        for (auto &&string : winNums) {
            std::cout << string << std::endl;
        }
        // for (int i = pos; i < ticket[0].size() - 1; i++) {
        // startPos = i;
        // if (isdigit(ticket[0][i])) {
        //     numberlength++;
        //     while (isdigit(ticket[0][i + numberlength])) {
        //         numberlength++;
        //     }
        //     std::cout << "Looking for: $"
        //               << ticket[0].substr(i - 1, numberlength + 1) << "$"
        //               << std::endl;
        //     std::size_t found =
        //         ticket[1].find(ticket[0].substr(i - 1, numberlength +
        //         1));
        //     if (found != std::string::npos) {
        //         std::cout << "found winner: "
        //                   << ticket[0].substr(i - 1, numberlength + 1)
        //                   << '\n';
        //     }
        // }
        // }
    }
}

void Y2023d04::run2() {}