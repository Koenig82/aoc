#include "day06.h"
#include <valarray>

Y2023d06::Y2023d06() {
    resourcePath = "2023/day06";

    readInput();
}

void Y2023d06::run1() {
    std::vector<int> recordTimes = StringUtil::getIntsFromString(input[0]);
    std::vector<int> recordDistances = StringUtil::getIntsFromString(input[1]);

    int raceSum = 1;
    for (size_t i = 0; i < recordDistances.size(); i++) {
        raceSum *= calcNumberOfWays(recordTimes[i], recordDistances[i]);
    }
    std::cout << raceSum << std::endl;
};

void Y2023d06::run2() {
    std::vector<std::string> timeString = StringUtil::split(input[0], ' ');
    long long time = stoll(timeString[1] + timeString[2] + timeString[3] + timeString[4]);
    std::vector<std::string> distanceString = StringUtil::split(input[1], ' ');
    long long distance = stoll(distanceString[1] + distanceString[2] + distanceString[3] + distanceString[4]);
    long long result = calcNumberOfWaysLargeGPT(time, distance);
    std::cout << result << std::endl;
};

int Y2023d06::calcNumberOfWays(int time, int distance) {
    int numberOfWays = 0;
    for (int speed = 0; speed < distance; speed++) {
        if (speed * (time - speed) > distance) {
            numberOfWays++;
        }
    }
    return numberOfWays;
}

long long Y2023d06::calcNumberOfWaysLarge(long long time, long long distance) {
    long long low = 1;
    long long high = time / 2;
    while (high - low > 1) {
        long long half = (high - low) / 2 + low;
        if (half * (time - half) > distance) {
            high = half;
        } else {
            low = half;
        }
    }
    return time + 1 - high * 2;
}

long long Y2023d06::calcNumberOfWaysLargeGPT(long long time, long long distance) {

    // speed * (time - speed) > distance
    // => speed^2 - speed * time + distance < 0
    // discriminant of "ax^2 + bx + c = 0" ==> "b^2 - 4ac"
    // aSpeed^2 -speedTime + distance
    long long a = 1;
    long long b = -time;
    long long c = distance;

    long long discriminant = b * b - 4 * a * c;

    // roots for ax^2 + bx + c is x = (-b+-sqrt(b^2-4ac))/2a
    //  speed = (-(-time))+-sqrt((-time)-4*1*distance)/2*1
    //  discriminant can also be seen under the sqrt in formula
    //  => using discriminant variable for readability

    // Calculate the roots
    long double root1 = (-b + sqrt(discriminant)) / (2 * a);
    long double root2 = (-b - sqrt(discriminant)) / (2 * a);

    // Find the valid range of speeds
    long long lowerBound = ceil(std::min(root1, root2));
    long long upperBound = floor(std::max(root1, root2));

    // Calculate the number of ways within the valid range of speeds
    // return std::max(0LL, upperBound - lowerBound + 1);
    return upperBound - lowerBound + 1;
}

// GPT notes
//  speed * (time - speed) > distance  => är quadratic equation in terms of
//  speed

// speed * time - speed^2 > distance
// speed^2 - speed * time + distance < 0      => represents parabola
//  This inequity can be solved by finding the range of speed that satisfy
//  the condition

// speed^2 - speed * time + distance = 0    => find the roots of this
// the roots represent the points where the equation is '0',
// which is the ranges of speed that satisfy the inequity

// Ex. find the roots of:
// speed^2 - speed * time + distance = 0
// => speed = (-b ± sqrt(b^2 - 4ac)) / 2a     where:
// a= 1, b= -time, c= distance.
// Find these roots to determine the valid speeds that satisfy:
// speed * (time - speed) > distance