#include "day04.h"

#include "../../../util/stringUtil.h"

Y2018d04::Y2018d04() {
    resourcePath = "2018/day04";

    readInput();
}

Event::Event(TimeUtil::Timestamp timestamp, bool isAwake) {
    this->timestamp = timestamp;
    this->isAwake = isAwake;
    this->guardId = -1;
}
Event::Event(TimeUtil::Timestamp timestamp, bool isAwake, int guardId) {
    this->timestamp = timestamp;
    this->isAwake = isAwake;
    this->guardId = guardId;
}

void Y2018d04::run1() {
    std::set<Event> eventlist = getEvents();
    std::map<int, std::array<int, 60>> shifts = getSleepingShifts(eventlist);
    calculateData(shifts);
}

void Y2018d04::run2() {
    std::set<Event> eventlist = getEvents();
    std::map<int, std::array<int, 60>> shifts = getSleepingShifts(eventlist);
    calculateData2(shifts);
}

std::set<Event> Y2018d04::getEvents() {
    std::set<Event> eventList;

    for (const std::string& line : input) {
        // Extract and parse timestamp parts
        int year = std::stoi(line.substr(1, 4));
        int month = std::stoi(line.substr(6, 2));
        int day = std::stoi(line.substr(9, 2));
        int hour = std::stoi(line.substr(12, 2));
        int minute = std::stoi(line.substr(15, 2));

        TimeUtil::Timestamp timestamp{year, month, day, hour, minute};

        // Process event type and guard ID
        std::vector<std::string> eventSubstring = StringUtil::split(line.substr(19), ' ');

        if (eventSubstring.size() > 2) {
            // printMinuteFromTimePoint(timePoint);
            eventList.emplace(timestamp, true, std::stoi(eventSubstring[1].substr(1)));
        }
        else {
            if (eventSubstring[0] == "wakes") {
                // printMinuteFromTimePoint(timePoint);
                eventList.emplace(timestamp, true);
            }
            else {
                // printMinuteFromTimePoint(timePoint);
                eventList.emplace(timestamp, false);
            }
        }
    }

    return eventList;
}

std::map<int, std::array<int, 60>> Y2018d04::getSleepingShifts(std::set<Event> eventlist) {

    std::map<int, std::array<int, 60>> shifts;
    TimeUtil::Timestamp latestStamp;
    int activeGuardId = -1;
    for (const auto& event : eventlist) {
        // if a new shift is starting
        if (event.guardId != -1) {
            // if the new shift is a new guard
            if (!shifts.contains(event.guardId)) {
                // add id and create defaultdata
                std::array<int, 60> sleepMinutes = {0};
                activeGuardId = event.guardId;
                shifts[event.guardId] = sleepMinutes;
                // if the shift is an existing guard
            }
            else {
                // set as active guard shift
                activeGuardId = event.guardId;
            }
            // continuing shift, add minutes asleep (event id = -1)
        }
        else {
            // Guard just woke up, add minutes since fall asleep timestamp for active guard
            if (event.isAwake) {
                addSleepingMinutes(shifts.at(activeGuardId), latestStamp, event.timestamp);
                // Guard just fell asleep, log the timestamp
            }
            else {
                latestStamp = event.timestamp;
            }
        }
    }
    return shifts;
}

void Y2018d04::addSleepingMinutes(std::array<int, 60>& minutes, TimeUtil::Timestamp first, TimeUtil::Timestamp second) {

    if (first.hour != second.hour) {
        // Fill minutes from first minute to end of the hour
        for (int i = first.minute.count(); i < 60; ++i) {
            minutes[i]++;
        }
        // Fill minutes from start of the next hour to second minute
        for (int i = 0; i < second.minute.count(); ++i) {
            minutes[i]++;
        }
    }
    else {
        // Fill minutes between first and second
        for (int i = first.minute.count(); i < second.minute.count(); ++i) {
            minutes[i]++;
        }
    }
}

void Y2018d04::calculateData(const std::map<int, std::array<int, 60>>& shifts) {

    int mostMinutesAsleep = 0;
    int tempMinutes;
    int leaderGuard = -1;
    for (const auto& entry : shifts) {
        tempMinutes = 0;
        for (size_t i = 0; i < entry.second.size(); i++) {
            tempMinutes += (int)entry.second[i];
        }
        if (tempMinutes > mostMinutesAsleep) {
            leaderGuard = entry.first;
            mostMinutesAsleep = tempMinutes;
        }
    }
    std::cout << "hello leaderguard " << leaderGuard << std::endl;
    int savedIndex = 0;
    int highestMinuteCount = 0;
    for (size_t i = 0; i < shifts.at(leaderGuard).size(); i++) {
        if (shifts.at(leaderGuard)[i] > highestMinuteCount) {
            highestMinuteCount = shifts.at(leaderGuard)[i];
            savedIndex = i;
        }
    }
    std::cout << (leaderGuard * savedIndex) << std::endl;
}

void Y2018d04::calculateData2(const std::map<int, std::array<int, 60>>& shifts) {

    int tempMinutes = 0;
    int minute = -1;
    int leaderGuard = -1;
    for (const auto& entry : shifts) {

        for (size_t i = 0; i < entry.second.size(); i++) {
            if (entry.second[i] > tempMinutes) {
                tempMinutes = entry.second[i];
                leaderGuard = entry.first;
                minute = i;
            }
        }
    }

    std::cout << (leaderGuard * minute) << std::endl;
}