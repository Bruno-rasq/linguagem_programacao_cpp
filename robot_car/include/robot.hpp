#ifndef ROBOT_HPP
#define ROBOT_HPP

#include <utility>
#include <vector>
#include "./gridCollections.hpp"


class Robot{
private:
    std::pair<int, int> coord_robot;

public:

    Robot(int x, int y);

    std::pair<int, int> getCoord() const;

    void setCoord(int x, int y);

    std::pair<int, int> getNextCoord(GridCollections::Board& board);
};

#endif