#include "Board.hpp"
#include <iostream>

Board::Board(int height, int width) {
	this -> height = height;
	this -> width = width;

	std::vector<std::vector<char>> table1(height, std::vector<char>(width, '0'));
	table = table1;
}

void Board::updateTable(int pos_y, int pos_x)
{
	for (int i = 0; i < height; ++i) {

		for (int j = 0; j < width; ++j) {
				table[i][j] = ' ';
		}
	}

	//if (pos_y <= 1) {
	//	pos_y = abs(height - 2 - pos_y);
	//}
	//if (pos_x <= 1) {
	//	pos_x = abs(width - 2 - pos_x);
	//}

	//if (pos_x == 116) {
	//	pos_x = 10;
	//	int a = 15 % 117;
	//}

	pos_x += 1;

	table[pos_y % (height - 1)][pos_x % (width - 2)] = '#';
	table[pos_y % (height - 1)][pos_x % (width - 2) + 1] = '#';
	table[pos_y % (height - 1)][pos_x % (width - 2) - 1] = '#';
	table[pos_y % (height - 1) + 1][pos_x % (width - 2)] = '#';
	table[pos_y % (height - 1) + 1][pos_x % (width - 2) + 1] = '#';
	table[pos_y % (height - 1) + 1][pos_x % (width - 2) - 1] = '#';
	//table[pos_y-1][pos_x] = 219;
	//table[pos_y-1][pos_x+1] = 219;
	//table[pos_y-1][pos_x-1] = 219;
}

void Board::printTable()
{
	for (int i = 0; i < table.size(); ++i) {
		for (int j = 0; j < table[i].size(); ++j) {
			std::cout << table[i][j];
		}
		std::cout << std::endl;
	}
}

std::vector<std::vector<char>> Board::getTable() const {
	return table;
}
