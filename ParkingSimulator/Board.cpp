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

	pos_y %= (height - 1);
	pos_x %= (width - 2);

	pos_x += 1;

	table[pos_y][pos_x] = '#';
	table[pos_y][pos_x + 1] = '#';
	table[pos_y][pos_x - 1] = '#';
	table[pos_y + 1][pos_x] = '#';
	table[pos_y + 1][pos_x + 1] = '#';
	table[pos_y + 1][pos_x - 1] = '#';
	//table[pos_y][pos_x + 2] = '#';
	//table[pos_y + 1][pos_x + 2] = '#';
	//table[pos_y][pos_x + 3] = '#';
	//table[pos_y + 1][pos_x + 3] = '#';

}

void Board::updateTable(Position  pos, Position dir)
{
	int pos_x = static_cast<int>(pos.x);
	int pos_y = static_cast<int>(pos.y);

	for (int i = 0; i < height; ++i) {

		for (int j = 0; j < width; ++j) {
			table[i][j] = ' ';
		}
	}

	pos_y %= (height - 1);
	pos_x %= (width - 2);
	//pos_x += 1;

	int dir_x_sign = 1;
	int dir_y_sign = 1;

	if (dir.x < 0) {
		dir_x_sign = -1;
	}
	if (dir.y < 0) {
		dir_y_sign = -1;
	}
	

	table[pos_y][pos_x] = '#';
	table[pos_y + 1][pos_x] = '#';
	table[pos_y][pos_x + 1] = '#';
	table[pos_y][pos_x - 1] = '#';
	table[pos_y + 1][pos_x + 1] = '#';
	table[pos_y + 1][pos_x - 1] = '#';

	if (dir.y < 0.25 && dir.y > -0.25) {
		table[pos_y + 1][pos_x - 2] = '#';  // verev dzax
		table[pos_y][pos_x - 2] = '#';  // nerqev dzax

		table[pos_y + 1][pos_x + 2] = '#'; // verev aj
		table[pos_y][pos_x + 2] = '#'; // nerqev aj
	}

	if (abs(dir.y) < 0.75 && abs(dir.y) > 0.25 && dir_x_sign != dir_y_sign) {
		table[pos_y + 1][pos_x + 2] = '#'; // verev aj
		table[pos_y][pos_x - 2] = '#';  // nerqev dzax
	}
	else if (abs(dir.y) < 0.75 && abs(dir.y) > 0.25 && dir_x_sign == dir_y_sign) {
		table[pos_y][pos_x + 2] = '#'; // nerqev aj
		table[pos_y + 1][pos_x - 2] = '#';  // verev dzax
	}

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
