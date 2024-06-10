#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <C:\Users\artas\source\repos\PDCurses\curses.h>

#include "Car.hpp"
#include "Board.hpp"
#include "Screen.hpp"

//#define DEBUG
#define ROTATION_ON

int main() {
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
    cursorInfo.bVisible = false;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);


    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    const int width = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    const int height = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

    Car car;
    Board board(height - 2, width - 3);
    Screen screen;

    screen.initScreen();
    auto window = screen.createWindow(height, width);

    board.updateTable(car.getPosition().y, car.getPosition().x);

    while (true) {


        if (GetAsyncKeyState(87) & 0x8000) {
            car.driveForward();
        }
        else if (GetAsyncKeyState(83) & 0x8000) {
            car.driveBackward();
        }
        else {
            car.speedDown();
        }

        if (GetAsyncKeyState(68) & 0x8000) {
            car.rotateRight();
        }
        else if (GetAsyncKeyState(65) & 0x8000) {
            car.rotateLeft();
        }
        else {
            car.normalizeRotation();
        }

        if (car.getSpeed() != 0) {
            car.moveCar();



#ifdef ROTATION_ON
            board.updateTable(car.getPosition(), car.getDirection());
#endif


#ifndef ROTATION_ON
            board.updateTable(car.getPosition().y, car.getPosition().x);
#endif


#ifdef DEBUG
            std::cout << std::endl << "Speed = " << car.getSpeed();
            std::cout << std::endl << "Rotation = " << car.getRotation() << std::endl;
            std::cout << "y: " << car.getPosition().y << ", x: " << car.getPosition().x << std::endl;
            std::cout << "Directions x: " << car.getDirection().x << ", y: " << car.getDirection().y << std::endl;
#endif
            

            screen.updateGameWindow(window, board.getTable());
            //screen.updateGameWindow(window, car.getPosition().x, car.getPosition().y);

        }

        //Sleep(10);
    }

    return 0;
}