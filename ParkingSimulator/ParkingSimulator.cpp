#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <C:\Users\artas\source\repos\PDCurses\curses.h>

#include "Car.hpp"
#include "Board.hpp"
#include "Screen.hpp"

//#define DEBUG

int main() {
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
    cursorInfo.bVisible = false;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);


    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    const int width = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    const int height = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;



    //const auto KEY_W = GetAsyncKeyState(87);
    //const auto KEY_S = GetAsyncKeyState(83);
    //const auto KEY_D = GetAsyncKeyState(68);
    //const auto KEY_A = GetAsyncKeyState(65);

    Car car;
    Board board(height - 2, width - 3);
    Screen screen;

    screen.initScreen();
    auto window = screen.createWindow(height, width);
    //initscr();
    //cbreak();
    //noecho();
    //curs_set(0);

    //auto win = newwin(30,
    //    120,
    //    0,
    //    0);

    board.updateTable(car.getPosition().y, car.getPosition().x);
    //screen.updateGameWindow(window, board.getTable());

    //board.printTable();

    while (true) {


        if (GetAsyncKeyState(87) & 0x8000) {
            car.driveForward();
            //std::cout << "driveForward()";
        }
        else if (GetAsyncKeyState(83) & 0x8000) {
            car.driveBackward();
            //std::cout << "driveBackward()";
        }
        else {
            car.speedDown();
        }

        if (GetAsyncKeyState(68) & 0x8000) {
            car.rotateRight();
            //std::cout << "rotateRight()";
        }
        else if (GetAsyncKeyState(65) & 0x8000) {
            car.rotateLeft();
            //std::cout << "rotateLeft()";

        }
        else {
            car.normalizeRotation();
        }

        //werase(win);
        //box(win, 0, 0);


        //for (int row = 0; row < 40; ++row)
        //{
        //    for (int col = 0; col < 120; col += 2)
        //    {
        //        mvwprintw(win, 1 + row, 1 + col, "  ");
        //    }
        //}

        //wrefresh(win);

        if (car.getSpeed() != 0) {
            car.moveCar();
            board.updateTable(car.getPosition().y, car.getPosition().x);

            screen.updateGameWindow(window, board.getTable());
            //screen.updateGameWindow(window, car.getPosition().x, car.getPosition().y);

#ifdef DEBUG
            std::cout << std::endl << "Speed = " << car.getSpeed();
            std::cout << std::endl << "Rotation = " << car.getRotation() << std::endl;
            std::cout << "y: " << car.getPosition().y << ", x: " << car.getPosition().x << std::endl;
            std::cout << "Directions x: " << car.getDirection().x << ", y: " << car.getDirection().y << std::endl;
#endif
            

            //board.printTable();

        }

        //Sleep(10);
    }

    return 0;
}