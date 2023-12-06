#pragma once
class Aoc {
public:
    virtual void run1() = 0;
    virtual void run2() = 0;
    virtual ~Aoc() = default;
    int start() {
        //int time = 0;
        run1();
        return 0;
    }
    //virtuevoid functipon()
};