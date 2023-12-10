#pragma once

#include <unordered_map>

#include "../../../aoc.h"
#include "../../../util/matrixUtil.h"

class Y2023d03 : public Aoc {
   public:
    Y2023d03();
    virtual ~Y2023d03() = default;

    void run1() override;
    void run2() override;

    std::vector<int> findConnectedNumbersInInputIndexString(int rowIndex);

    int addNumbersAroundGear(const int gearPosRow, const int gearPosCol);
    bool isSpecialChar(const char character);
    bool isGear(const char character);
    class GearPos {
       public:
        int row;
        int col;
        GearPos(int inRow, int inCol);
        bool operator==(const GearPos& other) const {
            return (row == other.row) && (col == other.col);
        }
    };
    std::unordered_map<Y2023d03::GearPos, std::vector<int>>
    findGearNumbersInStringIndex();
};

namespace std {
template <>
struct hash<Y2023d03::GearPos> {
    std::size_t operator()(const Y2023d03::GearPos& obj) const {
        return std::hash<int>()(obj.row) ^ std::hash<int>()(obj.col);
    }
};
}  // namespace std
