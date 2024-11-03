#pragma once

#include "../../../aoc.h"

#include "../../../util/timeUtil.h"

#include <array>
#include <map>
#include <set>

class Event;
class Y2018d04 : public Aoc {

  public:
    Y2018d04();
    virtual ~Y2018d04() = default;

    void run1() override;
    void run2() override;

    std::set<Event> getEvents();
    std::map<int, std::array<int, 60>> getSleepingShifts(std::set<Event>& eventlist);
    void addSleepingMinutes(std::array<int, 60>& minutes, const TimeUtil::Timestamp& first,
                            const TimeUtil::Timestamp& second);
    void calculateData(const std::map<int, std::array<int, 60>>& shifts);
    void calculateData2(const std::map<int, std::array<int, 60>>& shifts);
};

class Event {

  public:
    TimeUtil::Timestamp timestamp;

    bool isAwake;
    int guardId;

    Event(TimeUtil::Timestamp timestamp, bool isAwake);
    Event(TimeUtil::Timestamp timestamp, bool isAwake, int guardId);

    bool operator<(const Event& other) const { return timestamp < other.timestamp; }
};
