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

Ticket::Ticket(std::vector<int> winNums, std::vector<int> nums) {
    winners = winNums;
    numbers = nums;
}

void Y2023d04::run1() {
    int points = 0;
    int multiplier;
    bool firstWin;
    for (auto &&string : input) {
        multiplier = 0;
        firstWin = false;
        std::vector<std::string> ticket = StringUtil::split(string, '|');
        std::vector<std::string> winnersRaw = StringUtil::split(ticket[0], ':');

        std::vector<int> winners = StringUtil::getIntsFromString(winnersRaw[1]);
        std::vector<int> numbers = StringUtil::getIntsFromString(ticket[1]);

        for (auto &&number : numbers) {
            if (std::find(winners.begin(), winners.end(), number) !=
                winners.end()) {
                if (!firstWin) {
                    multiplier++;
                    firstWin = true;
                } else {
                    multiplier = multiplier * 2;
                }
            }
        }
        points += multiplier;
    }
    std::cout << points << std::endl;
}

void Y2023d04::run2() {
    int sum = 0;
    int card;
    int cardindex;
    std::vector<Ticket> ticketObjects;
    std::vector<int> extraTickets(input.size(), 0);
    for (auto &&string : input) {
        std::vector<std::string> ticket = StringUtil::split(string, '|');
        std::vector<std::string> winnersRaw = StringUtil::split(ticket[0], ':');

        card = StringUtil::getIntsFromString(winnersRaw[0]).at(0);
        cardindex = card - 1;
        std::vector<int> winners = StringUtil::getIntsFromString(winnersRaw[1]);
        std::vector<int> numbers = StringUtil::getIntsFromString(ticket[1]);
        ticketObjects.push_back(Ticket(winners, numbers));

        for (auto &&number : numbers) {
            if (std::find(winners.begin(), winners.end(), number) !=
                winners.end()) {
                extraTickets[cardindex + 1]++;
                cardindex++;
            }
        }
    }
    for (size_t extraTicketsindex = 0; extraTicketsindex < extraTickets.size();
         extraTicketsindex++) {
        for (int i = 0; i < extraTickets[extraTicketsindex]; i++) {
            cardindex = extraTicketsindex;
            for (auto &&number : ticketObjects[extraTicketsindex].numbers) {
                if (std::find(ticketObjects[extraTicketsindex].winners.begin(),
                              ticketObjects[extraTicketsindex].winners.end(),
                              number) !=
                    ticketObjects[extraTicketsindex].winners.end()) {
                    extraTickets[cardindex + 1]++;
                    cardindex++;
                }
            }
        }
    }
    for (auto &&numberOfTicketsAtIndex : extraTickets) {
        sum += numberOfTicketsAtIndex;
    }
    sum += input.size();
    std::cout << sum << std::endl;
}