#pragma once
#include <vector>
class Board
{
public:
    Board();
	void updateTable(int pos_y, int pos_x);
    void printTable();

private:
    const int rows = 40;
    const int columns = 100;
    std::vector<std::vector<char>> table;
};

