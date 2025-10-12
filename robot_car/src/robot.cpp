#include <utility>
#include <vector>
#include "../include/robot.hpp"
#include "../include/gridCollections.hpp"

Robot::Robot(int x, int y){
    this->coord_robot = std::make_pair(x, y);
}

std::pair<int, int> Robot::getCoord() const {
    return this->coord_robot;
}

void Robot::setCoord(int x, int y) {
    this->coord_robot = std::make_pair(x, y);
}

std::pair<int, int> Robot::getNextCoord(GridCollections::Board& board) {

    const int row = board.size();
    const int col = board[0].size();

    const std::vector<std::pair<int, int>> delta = {{1,0}, {-1,0}, {0, 1}, {0, -1}};

    for(const auto& d : delta){
        int nx = d.first + this->coord_robot.first;
        int ny = d.second + this->coord_robot.second;

        if(0 <= nx && nx < row && 0 <= ny && ny < col)
            if(board[nx][ny] == 1)
                return {nx, ny};
    }

    return {-1, -1};
}