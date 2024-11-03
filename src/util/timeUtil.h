#pragma once

#include <chrono>
#include <iostream>

namespace TimeUtil {
struct Timestamp {
    std::chrono::year_month_day date;
    std::chrono::hours hour;
    std::chrono::minutes minute;

    Timestamp() = default;

    Timestamp(int year, int month, int day, int hour, int minute)
        : date(std::chrono::year(year) / month / day), hour(std::chrono::hours(hour)),
          minute(std::chrono::minutes(minute)) {}

    // Overload the < operator to compare Timestamps
    bool operator<(const Timestamp& other) const {
        if (date < other.date)
            return true;
        if (date > other.date)
            return false;
        if (hour < other.hour)
            return true;
        if (hour > other.hour)
            return false;
        return minute < other.minute;
    }

    // Print function for testing
    void print() const {
        std::cout << int(date.year()) << '-' << unsigned(date.month()) << '-' << unsigned(date.day()) << ' '
                  << hour.count() << ':' << minute.count() << '\n';
    }
};
} // namespace TimeUtil
