#include "Screen.hpp"

namespace {

    //const int SCREEN_HEIGHT = 40;
    //const int SCREEN_WIDTH = 120;
    const int OFFSET_X = 1;
    const int OFFSET_Y = 1;

} //unnamed namespace

void Screen::initScreen()
{
    initscr();
    //cbreak();
    noecho();
    curs_set(0);
    //keypad(stdscr, TRUE);
    //nodelay(stdscr, TRUE);
    start_color();

    init_pair(1, COLOR_BLACK, COLOR_CYAN);
    init_pair(2, COLOR_CYAN, COLOR_BLACK);
    init_pair(3, COLOR_YELLOW, COLOR_BLACK);
    init_pair(4, COLOR_BLACK, COLOR_YELLOW);

}

//std::pair<int, int> Screen::computeScreenDims() const
//{
//    int max_x;
//    int max_y;
//    getmaxyx(stdscr, max_y, max_x);
//
//    const int screenY = max_y / 2 - (SCREEN_HEIGHT + 2) / 2;
//    const int screenX = max_x / 2 - (SCREEN_WIDTH + 2) / 2;
//    return { screenX, screenY };
//}

WINDOW* Screen::createWindow(int height, int width) const
{

    return newwin(height,
        width,
        0,
        0);
}

void Screen::updateGameWindow(WINDOW* window, const std::vector<std::vector<char>>& table)
{
    werase(window);
    box(window, 0, 0);

    int colorNumber;

    for (int row = 0; row < table.size(); ++row)
    {
        for (int col = 0; col < table[row].size(); ++col)
        {
            colorNumber = 2;
            if (table[row][col] == '#') {
                colorNumber = 4;
            }
            wattron(window, COLOR_PAIR(colorNumber));
            mvwprintw(window, OFFSET_Y + row, OFFSET_X + col, " ");
            wattroff(window, COLOR_PAIR(colorNumber));
        }
    }


    wrefresh(window);
}

////

void Screen::updateGameWindow(WINDOW* window, int x, int y) const
{
    werase(window);
    box(window, 0, 0);

    int colorNumber = 4;

    wattron(window, COLOR_PAIR(colorNumber));
    printCar(window, x, y);
    wattroff(window, COLOR_PAIR(colorNumber));


    wrefresh(window);
}

void Screen::printCar(WINDOW* screen, int x, int y) const {

    mvwprintw(screen, OFFSET_Y + y, OFFSET_X + x, " ");
    mvwprintw(screen, OFFSET_Y + y, OFFSET_X + x + 1, " ");
    mvwprintw(screen, OFFSET_Y + y, OFFSET_X + x - 1, " ");
    mvwprintw(screen, OFFSET_Y + y + 1, OFFSET_X + x, " ");
    mvwprintw(screen, OFFSET_Y + y + 1, OFFSET_X + x + 1, " ");
    mvwprintw(screen, OFFSET_Y + y + 1, OFFSET_X + x - 1, " ");

}


