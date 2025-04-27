#include "windows.h"

#ifndef PRACTPROJ_CONSOLEMANAGER_H
#define PRACTPROJ_CONSOLEMANAGER_H

class ConsoleManager{
public:
    //static BufferManager buffer_manager;
    static short int consoleWidth, consoleHeight;

    static HANDLE consoleHandle;
    static DWORD written;

    static void ConsoleManager_init(short int width, short int height);
    static void setConsoleSize();
    static void set_cursor_pos(short int x_pos, short int y_pos);
    static void print_str(const wchar_t* str, short int length);
    static void print_to_pos(const wchar_t* str, short int length, short int x_pos, short int y_pos);
    static void clear_console();
    //static void updateScreenBuffer();
    //static void displayScreenBuffer();
    //static void cleanScreenBuffer();
};

#endif //PRACTPROJ_CONSOLEMANAGER_H
