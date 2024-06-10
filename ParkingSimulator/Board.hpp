#pragma once
#include <vector>
#include "Car.hpp"
class Board
{
public:
    Board(int height, int width);
	void updateTable(int pos_y, int pos_x);
	void updateTable(Position pos, Position dir);
    void printTable();
    std::vector<std::vector<char>> getTable() const;

private:
    int height = 0;
    int width = 0;
    std::vector<std::vector<char>> table;
};

