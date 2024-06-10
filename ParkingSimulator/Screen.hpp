#pragma once
#include <C:\Users\artas\source\repos\PDCurses\curses.h>
#include <vector>

class Screen
{
public:
	void initScreen();
	WINDOW* createWindow(int height, int width) const;
	void updateGameWindow(WINDOW* screen, const std::vector<std::vector<char>>& table);
	void updateGameWindow(WINDOW* screen, int x, int y) const;
	void printCar(WINDOW* screen, int x, int y) const;

private:
	std::pair<int, int> computeScreenDims() const;
};

