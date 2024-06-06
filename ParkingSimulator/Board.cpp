#include "Board.h"
#include <iostream>

Board::Board() {
	std::vector<std::vector<char>> table1(rows, std::vector<char>(columns, 'A'));
	table = table1;
}

void Board::updateTable(int pos_y, int pos_x)
{
	for (int i = 0; i < table.size(); ++i) {
		for (int j = 0; j < table[i].size(); ++j) {
			table[i][j] = ' ';
		}
	}

	table[pos_y][pos_x] = '#';
	table[pos_y][pos_x+1] = '#';
	table[pos_y][pos_x-1] = '#';
	table[pos_y+1][pos_x] = '#';
	table[pos_y+1][pos_x+1] = '#';
	table[pos_y+1][pos_x-1] = '#';
	//table[pos_y-1][pos_x] = '#';
	//table[pos_y-1][pos_x+1] = '#';
	//table[pos_y-1][pos_x-1] = '#';
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
