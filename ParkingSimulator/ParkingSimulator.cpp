#include <iostream>
#include <windows.h>

using namespace std;
int main() {
    // Hide the cursor
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
    cursorInfo.bVisible = false; // set the cursor visibility
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);

    double i = 0;
    double j = 10000;

    while (true) {

        if (GetAsyncKeyState(68) & 0x8000) {
            i += 0.5;
        }

        if (GetAsyncKeyState(65) & 0x8000) {

            j -= 1;
        }

        Sleep(50);
        cout << "\t\t" << i << endl;
        cout << "\t\t" << j << endl;
    }

    return 0;
}