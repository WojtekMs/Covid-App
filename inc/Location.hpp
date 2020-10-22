#pragma once
#include <cmath>
#include <functional>

class Location {
    public:
    int x_{};
    int y_{};
    Location() = default;
    Location(int x, int y) : x_(x), y_(y) {}
    static double Distance(const Location& lhs, const Location& rhs) {
        return sqrt(pow((lhs.x_ - rhs.x_), 2) + pow((lhs.y_ - rhs.y_), 2));
    }
    bool operator==(const Location& rhs) const {
        return x_ == rhs.x_ && y_ == rhs.y_;
    }
};

namespace std
{
    template<>
    struct hash<Location>
    {
        std::size_t operator()(const Location& location) const {
            return std::hash<int>()(location.x_) ^ std::hash<int>()(location.y_);
        }
    };
}
