#include <iostream>
#include <windows.h>
#include <cstdlib>

#include "Car.h"
#include "Board.h"

using namespace std;
int main() {
    // Hide the cursor
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
    cursorInfo.bVisible = false; // set the cursor visibility
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);

    //const auto KEY_W = GetAsyncKeyState(87);
    //const auto KEY_S = GetAsyncKeyState(83);
    //const auto KEY_D = GetAsyncKeyState(68);
    //const auto KEY_A = GetAsyncKeyState(65);

    Car car;
    Board board;

    while (true) {
        system("cls");

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

        //if (car.getSpeed != 0) {
        car.moveCar();
        //}
        std::cout << std::endl << "Speed = " <<  car.getSpeed();
        std::cout << std::endl << "Rotation = " << car.getRotation() << std::endl;
        std::cout << "y: " << car.getPosition().y << ", x: " << car.getPosition().x << std::endl;
        std::cout << "Directions x: " << car.getDirection().x << ", y: " << car.getDirection().y << std::endl;
        board.updateTable(car.getPosition().y, car.getPosition().x);
        board.printTable();

        Sleep(10);
    }

    return 0;
}