#include "../include/simple_include.h"

HANDLE hConsole;
#define Colour SetConsoleTextAttribute

inline void ColourInit() {
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
}

enum ColourConsole {
    Green = 2,
    BRIGHTGreen = 10,
    BRIGHTCyan = 11,
    Red = 12,
    Yellow = 14,
    BRIGHTWhite = 15,
};
